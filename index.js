

class WasmWrapper {

  constructor(wasm) {
    this.wasm = wasm;
    this.textDecoder = new TextDecoder();
    for (const elem of Object.entries(this.wasm.instance.exports)) {
      if (typeof elem[1] === 'function') {
        this[elem[0]] = elem[1];
      }
    }
  }

  cStrToString = (cstr) => {
    const length = this.wasm.instance.exports.c_strlen(cstr);
    const array = new Uint8Array(this.wasm.instance.exports.memory.buffer, cstr, length);
    return this.textDecoder.decode(array);
  }

  memToString = (str, length) => {
    const array = new Uint8Array(this.wasm.instance.exports.memory.buffer, str, length);
    return this.textDecoder.decode(array);
  }

  memToByteArray = (ptr, length) => {
    return new Uint8Array(this.wasm.instance.exports.memory.buffer, ptr, length);
  }

  growMemory = (pages) => {
    this.wasm.instance.exports.memory.grow(pages);
    console.log("grow memory, buffer length: ", this.wasm.instance.exports.memory.buffer.byteLength);
  }

};

class Application {

  constructor(canvas) {
    this.canvas = canvas;
    this.wasm = undefined;
    this.glIdMap = new Array();
    this.glIdFreelist = new Array();
    this.glIdMap.push(null);

    this.gl = canvas.getContext('webgl2');
  }

  init = async () => {

    await this.initWasm();

    this.canvas.addEventListener('mousemove', (evt) => {
      this.wasm.handleMousemove(evt.offsetX, evt.offsetY);
    });
    this.canvas.addEventListener('mousedown', (evt) => {
      this.wasm.handleMousedown(evt.button);
    });
    this.canvas.addEventListener('mouseup', (evt) => {
      this.wasm.handleMouseup(evt.button);
    });

    window.requestAnimationFrame(this.render);
  }

  initWasm = async () => {
    const importObject = {
      env: {
        growMemory: (pages) => {
          this.wasm.growMemory(pages);
        },
        assertFail: (expr, file, line, func) => {
          const funcStr = this.wasm.cStrToString(func);
          const fileStr = this.wasm.cStrToString(file);
          const exprStr = this.wasm.cStrToString(expr);
          window.alert(`Assertion failed in ${funcStr},${fileStr}:${line}: ${exprStr}`);
        },
        consoleLog: (str, len) => {
          const string = this.wasm.memToString(str, len);
          console.log(string);
        },
        performanceNow: () => {
          return performance.now();
        },
        sin: (a) => {
          return Math.sin(a);
        },
        cos: (a) => {
          return Math.cos(a);
        },
      },
      gl: {
        createVertexArray: () => {
          const buf = this.gl.createVertexArray();
          return this.webglIdNew(buf);
        },
        deleteVertexArray: (id) => {
          const vao = this.glIdMap[id];
          this.webglIdRemove(id);
          this.gl.deleteVertexArray(vao);
        },
        bindVertexArray: (id) => {
          const vao = this.glIdMap[id];
          this.gl.bindVertexArray(vao);
        },
        enableVertexAttribArray: (idx) => {
          this.gl.enableVertexAttribArray(idx);
        },
        disableVertexAttribArray: (idx) => {
          this.gl.disableVertexAttribArray(idx);
        },
        vertexAttribPointer: (index, size, type, normalized, stride, offset) => {
          this.gl.vertexAttribPointer(index, size, type, normalized, stride, offset);
        },

        createBuffer: () => {
          const buf = this.gl.createBuffer();
          return this.webglIdNew(buf);
        },
        deleteBuffer: (id) => {
          const buf = this.glIdMap[id];
          this.webglIdRemove(id);
          this.gl.deleteBuffer(buf);
        },
        bindBuffer: (target, id) => {
          const buf = this.glIdMap[id];
          this.gl.bindBuffer(target, buf);
        },
        bindBufferRange: (target, index, id, offset, size) => {
          const buf = this.glIdMap[id];
          this.gl.bindBufferRange(target, index, buf, offset, size);
        },
        bufferData: (target, size, usage) => {
          this.gl.bufferData(target, size, usage);
        },
        bufferSubData: (target, offset, ptr, length) => {
          this.gl.bufferSubData(target, offset, this.wasm.memToByteArray(ptr, length), 0);
        },
        copyBufferSubData: (readTarget, writeTarget, readOffset, writeOffset, size) => {
          this.gl.copyBufferSubData(readTarget, writeTarget, readOffset, writeOffset, size);
        },

        attachShader: (programId, shaderId) => {
          const program = this.glIdMap[programId];
          const shader = this.glIdMap[shaderId];
          this.gl.attachShader(program, shader);
        },
        compileShader: (shaderId) => {
          const shader = this.glIdMap[shaderId];
          this.gl.compileShader(shader);
          if (!this.gl.getShaderParameter(shader, this.gl.COMPILE_STATUS)) {
            console.error("Shader compilation error:", this.gl.getShaderInfoLog(shader));
          }
        },
        createProgram: () => {
          const program = this.gl.createProgram();
          return this.webglIdNew(program);
        },
        createShader: (type) => {
          const shader = this.gl.createShader(type);
          return this.webglIdNew(shader);
        },
        deleteProgram: (programId) => {
          const program = this.glIdMap[programId];
          this.webglIdRemove(programId);
          this.gl.deleteProgram(program);
        },
        deleteShader: (shaderId) => {
          const shader = this.glIdMap[shaderId];
          this.webglIdRemove(shaderId);
          this.gl.deleteShader(shader);
        },
        detachShader: (programId, shaderId) => {
          const program = this.glIdMap[programId];
          const shader = this.glIdMap[shaderId];
          this.gl.detachShader(program, shader);
        },
        linkProgram: (programId) => {
          const program = this.glIdMap[programId];
          this.gl.linkProgram(program);
          if (!this.gl.getProgramParameter(program, this.gl.LINK_STATUS)) {
              console.error("Program linking error:", this.gl.getProgramInfoLog(program));
          }
        },
        shaderSource: (shaderId, source, length) => {
          const shader = this.glIdMap[shaderId];
          const sourceStr = this.wasm.memToString(source, length);
          console.log(sourceStr);
          this.gl.shaderSource(shader, sourceStr);
        },
        useProgram: (programId) => {
          const program = this.glIdMap[programId];
          this.gl.useProgram(program);
        },

        clear: (mask) => {
          this.gl.clear(mask);
        },
        clearColor: (red, green, blue, alpha) => {
          this.gl.clearColor(red, green, blue, alpha);
        },
        clearDepth: (depth) => {
          this.gl.clearDepth(depth);
        },
        clearStencil: (stencil) => {
          this.gl.clearStencil(stencil);
        },
        drawArrays: (mode, first, count) => {
          this.gl.drawArrays(mode, first, count);
        },

        fenceSync: (condition, flags) => {
          const sync = this.gl.fenceSync(condition, flags);
          return this.webglIdNew(sync);
        },
        deleteSync: (syncId) => {
          const sync = this.glIdMap[syncId];
          this.webglIdRemove(syncId);
          this.gl.deleteSync(sync);
        },
        clientWaitSync: (syncId, flags, timeout) => {
          const sync = this.glIdMap[syncId];
          const result = this.gl.clientWaitSync(sync, flags, Number(timeout));
          return result;
        },
      },
    };

    const wasm = await WebAssembly.instantiateStreaming(fetch("dist/bin/shrub_example.wasm"), importObject);
    this.wasm = new WasmWrapper(wasm);

    this.wasm.c_init();
  }

  render = (timestamp) => {
    this.wasm.c_render(timestamp*0.001);

    window.requestAnimationFrame(this.render);
  }

  webglIdNew = (obj) => {
    if (this.glIdFreelist.length == 0) {
      this.glIdMap.push(obj);
      return this.glIdMap.length - 1;
    } else {
      const id = this.glIdFreelist.shift();
      this.glIdMap[id] = obj;
      return id;
    }
  }

  webglIdRemove = (id) => {
    delete this.glIdMap[id];
    this.glIdFreelist.push(id);
  }

};

const init = async () => {

  const canvas = document.createElement("canvas");
  canvas.width = 800;
  canvas.height = 600;
  document.body.appendChild(canvas);

  const application = new Application(canvas);
  application.init();

}
init();

