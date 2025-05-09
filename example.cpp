#include <oak_util/types.h>
#include <oak_util/fmt.h>
#include <oak_math/math.h>

#include "web_gl.h"

using namespace oak;

#define WASM_IMPORT(module, name) extern "C" __attribute__((import_module(#module), import_name(#name)))
#define WASM_EXPORT(name) extern "C" __attribute__((export_name(#name)))

WASM_IMPORT(env, growMemory) void grow_memory(int pages);

WASM_IMPORT(env, consoleLog) void console_log(char const *str, usize length);
WASM_IMPORT(env, performanceNow) f64 performance_now();

WASM_IMPORT(env, sin) f64 wasm_sin(f64 a);
WASM_IMPORT(env, cos) f64 wasm_cos(f64 a);

extern "C" f32 sinf(f32 a) {
	return static_cast<f32>(wasm_sin(static_cast<f64>(a)));
}

extern "C" f32 cosf(f32 a) {
	return static_cast<f32>(wasm_cos(static_cast<f64>(a)));
}

extern "C" void* memset (void *s, int c, size_t n) {
	for (size_t i = 0; i < n; ++i) {
		static_cast<char*>(s)[i] = c;
	}
	return s;
}

extern "C" void* memcpy (void *__restrict dest, const void *__restrict src, size_t n) {
	for (size_t i = 0; i < n; ++i) {
		static_cast<char *__restrict>(dest)[i] = static_cast<char const*__restrict>(src)[i];
	}
	return dest;
}

extern "C" unsigned char __heap_base;
extern "C" unsigned char __heap_end;
static unsigned char *heapPtr;

#define WASM_PAGE_SIZE (64 << 10)

extern "C" usize get_page_size_freestanding() {
	return WASM_PAGE_SIZE;
}

extern "C" void* virtual_alloc_freestanding(usize size) {
	auto alignedSize = align(size, WASM_PAGE_SIZE);

	grow_memory(alignedSize / WASM_PAGE_SIZE);

	auto result = heapPtr;
	heapPtr += alignedSize;

	return result;
}

extern "C" bool virtual_try_grow_freestanding(void *addr, usize size, usize nSize) {
	(void)addr;
	(void)size;
	(void)nSize;
	return false;
}

extern "C" void virtual_free_freestanding(void *addr, usize size) {
	(void)addr;
	(void)size;
}

extern "C" i32 commit_region_freestanding(void *addr, usize size) {
	(void)addr;
	(void)size;
	return 0;
}

extern "C" i32 decommit_region_freestanding(void *addr, usize size) {
	(void)addr;
	(void)size;
	return 0;
}

template<typename... TArgs>
void console_fmt(String fmtStr, TArgs&&... args) {
	auto str = fmt(temporaryAllocator, fmtStr, static_cast<TArgs&&>(args)...);
	console_log(str.data, str.count);
}

WASM_EXPORT(c_strlen) size_t c_strlen(char const *ptr) {
	return c_str_len(ptr);
}

namespace {

	Allocator globAlloc;
	Allocator tempAlloc;

	struct VirtualFrame {
		int stagingBuffer;
		int fence;
	};

	enum class EventType {
		MOUSE_MOVE,
		MOUSE_DOWN,
		MOUSE_UP,
	};

	struct Event {
		EventType type;
		int x, y, button;
	};

	struct ElementIndex {
		i32 index = 0;
	};

	struct ElementId {
		u64 id = 0;
	};

	struct ElementPadding {
		f32 right = 0.f;
		f32 top = 0.f;
		f32 left = 0.f;
		f32 bottom = 0.f;
	};

	struct Element {

		enum FlagBits : u32 {
			LAYOUT_AXIS_MAJOR_MASK = 0x3,
			LAYOUT_AXIS_MINOR_MASK = 0xC,
			USE_AUTO_LAYOUT_BIT = 0x10,
		};

		ElementId id;
		Vec2 pos;
		Vec2 alignment;
		Vec2 extent;
		ElementPadding padding;
		u32 flags = 0;

		static constexpr Element from_id(ElementId id) {
			auto result = Element{};
			result.id = id;
			return result;
		}

		constexpr i32 major_axis() const {
			return (flags & LAYOUT_AXIS_MAJOR_MASK);
		}

		constexpr i32 minor_axis() const {
			return (flags & LAYOUT_AXIS_MINOR_MASK) >> 2;
		}
	};

	struct ElementConstraints {
		ElementIndex index;
		Vec2 minExtent;
		Vec2 maxExtent;
	};

	struct ElementTree {

		Element *elements = nullptr;
		ElementIndex *parents = nullptr;
		ElementIndex *firstChildren = nullptr;
		ElementIndex *lastChildren = nullptr;
		ElementIndex *siblings = nullptr;
		Vec2 *positions = nullptr;
		i32 elementCount = 0;
		i32 elementCapacity = 0;

		ElementConstraints *constraints = nullptr;
		i32 constraintCount = 0;
		i32 constraintCapacity = 0;

		void init(Allocator *allocator, i32 capacity);

		void begin_ui();
		void end_ui();

		ElementIndex push_element(ElementIndex parent, Element const& widget);

		void layout();
		void transform();

		Element* operator[](ElementIndex index);
	};

	void ElementTree::init(Allocator *allocator, i32 capacity) {
		elements = allocate<Element>(allocator, capacity);
		parents = allocate<ElementIndex>(allocator, capacity);
		firstChildren = allocate<ElementIndex>(allocator, capacity);
		lastChildren = allocate<ElementIndex>(allocator, capacity);
		siblings = allocate<ElementIndex>(allocator, capacity);
		positions = allocate<Vec2>(allocator, capacity);

		elementCapacity = capacity;
	}

	void ElementTree::begin_ui() {
		elementCount = 0;
	}

	void ElementTree::end_ui() {
		layout();
		transform();
	}

	ElementIndex ElementTree::push_element(ElementIndex parent, Element const& elem) {

		auto result = ElementIndex{ elementCount };
		elements[result.index] = elem;
		parents[result.index] = parent;
		firstChildren[result.index] = {};
		lastChildren[result.index] = {};
		siblings[result.index] = {};

		if (parent.index != -1) {
			if (lastChildren[parent.index].index != -1)
				siblings[lastChildren[parent.index].index] = result;
			lastChildren[parent.index] = result;
			if (firstChildren[parent.index].index == -1)
				firstChildren[parent.index] = result;
		}

		return result;
	}

	void ElementTree::layout() {

		for (i32 i = 0; i < elementCount; ++i) {
		}

	}

	void ElementTree::transform() {
		for (i32 i = 0; i < elementCount; ++i) {
			auto parentOrigin = Vec2{};
			auto parentExtent = Vec2{};
			if (parents[i].index != -1) {
				parentOrigin = positions[parents[i].index];
				parentExtent = elements[parents[i].index].extent;
			}

			positions[i] = parentOrigin + elements[i].pos;
		}
	}

	Element* ElementTree::operator[](ElementIndex index) {
		return elements + index.index;
	}

	struct DrawCommand {
		ElementIndex elementIndex;
		Vec4 color;
	};

	struct Context {
		Array<Event, 64> events;
		FixedArray<VirtualFrame, 3> virtualFrames;
		ElementTree elementTree;
		Vector<DrawCommand> drawCommands;

		i64 virtualFrameIdx;
		int geomBuf;
		int sceneBuf;
		int vao;
		int prog;

		void init(Allocator *allocator);

		int make_shader(String vertSource, String fragSource);

		bool begin_frame();
		void end_frame();
	};

	void Context::init(Allocator *allocator) {
		for (i64 i = 0; i < virtualFrames.capacity; ++i) {
			auto& frame = virtualFrames[i];
			frame.stagingBuffer = gl_create_buffer();
			gl_bind_buffer(GL_COPY_READ_BUFFER, frame.stagingBuffer);
			gl_buffer_data(GL_COPY_READ_BUFFER, 1<<20, GL_STREAM_DRAW);
			frame.fence = 0;
		}
		char const vertexShader[] = R"(#version 300 es
	precision mediump float;

	layout (location = 0) in vec2 vPos;
	layout (location = 1) in vec4 vColor;

	layout(std140) uniform Scene {
		mat4 projView;
	};

	out vec4 sColor;

	void main() {
		gl_Position = projView * vec4(vPos, 0.0, 1.0);

		sColor = vColor;
	}
		)";

		char const fragmentShader[] = R"(#version 300 es
	precision mediump float;

	in vec4 sColor;

	layout (location = 0) out vec4 oColor;

	void main() {
		oColor = sColor;
	}
		)";
		prog = make_shader(vertexShader, fragmentShader);

		Mat4 proj = ortho(0, 800, 0, 600, 1, -1);

		sceneBuf = gl_create_buffer();
		gl_bind_buffer_range(GL_UNIFORM_BUFFER, 0, sceneBuf, 0, sizeof(Mat4));
		gl_buffer_data(GL_UNIFORM_BUFFER, sizeof(Mat4), GL_STATIC_DRAW);
		gl_buffer_sub_data(GL_UNIFORM_BUFFER, 0, &proj, sizeof(Mat4));

		vao = gl_create_vertex_array();
		gl_bind_vertex_array(vao);

		geomBuf = gl_create_buffer();
		gl_bind_buffer(GL_ARRAY_BUFFER, geomBuf);
		gl_buffer_data(GL_ARRAY_BUFFER, 20<<20, GL_STATIC_DRAW);

		gl_enable_vertex_attrib_array(0);
		gl_enable_vertex_attrib_array(1);
		gl_vertex_attrib_pointer(0, 2, GL_FLOAT, 0, 24, 0);
		gl_vertex_attrib_pointer(1, 4, GL_FLOAT, 0, 24, 8);

		drawCommands.reserve(allocator, 512);
	}

	int Context::make_shader(String vertSource, String fragSource) {
		int programId = gl_create_program();

		auto vs = gl_create_shader(GL_VERTEX_SHADER);
		auto fs = gl_create_shader(GL_FRAGMENT_SHADER);

		gl_shader_source(vs, vertSource.data, vertSource.count);
		gl_shader_source(fs, fragSource.data, fragSource.count);

		gl_compile_shader(vs);
		gl_compile_shader(fs);

		gl_attach_shader(programId, vs);
		gl_attach_shader(programId, fs);

		gl_link_program(programId);

		gl_detach_shader(programId, vs);
		gl_detach_shader(programId, fs);

		gl_delete_shader(vs);
		gl_delete_shader(fs);

		return programId;
	}

	bool Context::begin_frame() {
		auto& frame = virtualFrames[virtualFrameIdx];
		if (frame.fence != 0) {
			GLenum result = gl_client_wait_sync(frame.fence, 0, 0);
			if (result == GL_WAIT_FAILED) {
				console_fmt("Wait failed");
				return false;
			}
			if (result == GL_TIMEOUT_EXPIRED) {
				console_fmt("Timeout expired");
				return false;
			}
			gl_delete_sync(frame.fence);
			frame.fence = 0;
		}

		return true;
	}

	void Context::end_frame() {
		auto& frame = virtualFrames[virtualFrameIdx];
		frame.fence = gl_fence_sync(GL_SYNC_GPU_COMMANDS_COMPLETE, 0);
		++virtualFrameIdx;
		if (virtualFrameIdx >= virtualFrames.capacity)
			virtualFrameIdx = 0;
	}

	Context *context = nullptr;

}

void push_rectangle(GLintptr *offset, Vec2 pos, Vec2 extent, Vec4 color) {

	const f32 rectangle[] = {
		pos.x           , pos.y           , color.x, color.y, color.z, color.w,
		pos.x + extent.x, pos.y           , color.x, color.y, color.z, color.w,
		pos.x + extent.x, pos.y + extent.y, color.x, color.y, color.z, color.w,
		pos.x + extent.x, pos.y + extent.y, color.x, color.y, color.z, color.w,
		pos.x           , pos.y + extent.y, color.x, color.y, color.z, color.w,
		pos.x           , pos.y           , color.x, color.y, color.z, color.w,
	};

	gl_buffer_sub_data(GL_COPY_READ_BUFFER, *offset, rectangle, sizeof(rectangle));
	*offset += sizeof(rectangle);
}

#define new_id() ElementId{ hash_combine(hash_int(__LINE__), hash_string(__FILE__)) }

WASM_EXPORT(handleMousemove) void handle_mousemove(int x, int y) {
	push(&context->events, { EventType::MOUSE_MOVE, x, y, -1 });
}

WASM_EXPORT(handleMousedown) void handle_mousedown(int button) {
	push(&context->events, { EventType::MOUSE_DOWN, 0, 0, button });
}

WASM_EXPORT(handleMouseup) void handle_mouseup(int button) {
	push(&context->events, { EventType::MOUSE_UP, 0, 0, button });
}

WASM_EXPORT(c_render) void c_render(f64 timestamp) {

	static f64 lastTimestamp = 0;

	auto dt = timestamp - lastTimestamp;
	lastTimestamp = timestamp;

	if (!context->events.count)
		return;

	(void)dt;

	int mouseX, mouseY;

	context->elementTree.begin_ui();

	auto windowElem = context->elementTree.push_element({ -1 }, Element::from_id(new_id()));
	auto otherElem = context->elementTree.push_element(windowElem, Element::from_id(new_id()));
	context->elementTree[otherElem]->extent = { 32.f, 128.f };

	context->elementTree.end_ui();

	for (auto evt : context->events) {
		switch (evt.type) {
		case EventType::MOUSE_MOVE:
			mouseX = evt.x;
			mouseY = 600 - evt.y;
			break;
		case EventType::MOUSE_DOWN:
			break;
		case EventType::MOUSE_UP:
			break;
		}
	}
	context->events.clear();

	if (1
			&& mouseX >= context->elementTree.elements[otherElem.index].pos.x
			&& mouseX <= context->elementTree.elements[otherElem.index].pos.x
				+ context->elementTree.elements[otherElem.index].extent.x
			&& mouseY >= context->elementTree.elements[otherElem.index].pos.y
			&& mouseY <= context->elementTree.elements[otherElem.index].pos.y
				+ context->elementTree.elements[otherElem.index].extent.y
				) {
		push(&context->drawCommands, { otherElem, { 0.1f, 0.2f, 0.9f, 1.f }});
	} else {
		push(&context->drawCommands, { otherElem, { 1.f }});
	}

	if (!context->begin_frame()) {
		// We may not begin this frame
		return;
	}

	auto const& frame = context->virtualFrames[context->virtualFrameIdx];

	gl_clear_color(0.2f, 0.2f, 0.2f, 1.f);
	gl_clear(GL_COLOR_BUFFER_BIT);

	gl_bind_buffer(GL_COPY_READ_BUFFER, frame.stagingBuffer);
	gl_bind_buffer(GL_COPY_WRITE_BUFFER, context->geomBuf);

	GLintptr offset = 0;

	for (i64 i = 0; i < context->drawCommands.count; ++i) {
		auto drawCmd = &context->drawCommands[i];
		auto const& pos = context->elementTree.positions[drawCmd->elementIndex.index];
		auto const& elem = context->elementTree.elements[drawCmd->elementIndex.index];
		push_rectangle(&offset, pos, elem.extent, drawCmd->color);
	}
	context->drawCommands.clear();

	Vec2 v0 = { -10.f, -10.f };
	Vec2 v1 = { 10.f, -10.f };
	Vec2 v2 = { 0.0f, 10.f };

	v0 = rotate(v0, timestamp);
	v1 = rotate(v1, timestamp);
	v2 = rotate(v2, timestamp);

	const f32 triangle[] = {
		100.f + v0.x, 100.f + v0.y, 1.f, 0.f, 1.f, 1.f,
		100.f + v1.x, 100.f + v1.y, 0.f, 1.f, 1.f, 1.f,
		100.f + v2.x, 100.f + v2.y, 0.f, 0.f, 1.f, 1.f,
	};

	gl_buffer_sub_data(GL_COPY_READ_BUFFER, offset, triangle, sizeof(triangle));
	offset += sizeof(triangle);

	gl_copy_buffer_sub_data(GL_COPY_READ_BUFFER, GL_COPY_WRITE_BUFFER, 0, 0, offset);

	gl_use_program(context->prog);
	gl_draw_arrays(GL_TRIANGLES, 0, offset / 24);

	context->end_frame();

	temporaryAllocator->clear();
}

WASM_EXPORT(c_init) void c_init() {
	heapPtr = &__heap_base;

	globAlloc = make_arena_allocator(1<<20);
	tempAlloc = make_arena_allocator(1<<29);

	globalAllocator = &globAlloc;
	temporaryAllocator = &tempAlloc;

	console_fmt("Hello JS %g\n", 5);

	context = make<Context>(globalAllocator, 1);
	context->init(globalAllocator);

	temporaryAllocator->clear();
}

