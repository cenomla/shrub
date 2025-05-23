#pragma once

typedef unsigned int GLuint;
typedef int GLint;
typedef long GLsizei;
typedef long long GLint64;
typedef unsigned long long GLuint64;
typedef long GLsizeiptr;
typedef long GLintptr;
typedef int GLboolean;
typedef float GLclampf;
typedef GLuint GLbitfield;

enum GLenum: GLuint {
	GL_DEPTH_BUFFER_BIT               = 0x00000100,
	GL_STENCIL_BUFFER_BIT             = 0x00000400,
	GL_COLOR_BUFFER_BIT               = 0x00004000,

	/* BeginMode */
	GL_POINTS                         = 0x0000,
	GL_LINES                          = 0x0001,
	GL_LINE_LOOP                      = 0x0002,
	GL_LINE_STRIP                     = 0x0003,
	GL_TRIANGLES                      = 0x0004,
	GL_TRIANGLE_STRIP                 = 0x0005,
	GL_TRIANGLE_FAN                   = 0x0006,

	/* AlphaFunction (not supported in ES20) */
	/*      NEVER */
	/*      LESS */
	/*      EQUAL */
	/*      LEQUAL */
	/*      GREATER */
	/*      NOTEQUAL */
	/*      GEQUAL */
	/*      ALWAYS */

	/* BlendingFactorDest */
	GL_ZERO                           = 0,
	GL_ONE                            = 1,
	GL_SRC_COLOR                      = 0x0300,
	GL_ONE_MINUS_SRC_COLOR            = 0x0301,
	GL_SRC_ALPHA                      = 0x0302,
	GL_ONE_MINUS_SRC_ALPHA            = 0x0303,
	GL_DST_ALPHA                      = 0x0304,
	GL_ONE_MINUS_DST_ALPHA            = 0x0305,

	/* BlendingFactorSrc */
	/*      ZERO */
	/*      ONE */
	GL_DST_COLOR                      = 0x0306,
	GL_ONE_MINUS_DST_COLOR            = 0x0307,
	GL_SRC_ALPHA_SATURATE             = 0x0308,
	/*      SRC_ALPHA */
	/*      ONE_MINUS_SRC_ALPHA */
	/*      DST_ALPHA */
	/*      ONE_MINUS_DST_ALPHA */

	/* BlendEquationSeparate */
	GL_FUNC_ADD                       = 0x8006,
	GL_BLEND_EQUATION                 = 0x8009,
	GL_BLEND_EQUATION_RGB             = 0x8009,   /* same as BLEND_EQUATION */
	GL_BLEND_EQUATION_ALPHA           = 0x883D,

	/* BlendSubtract */
	GL_FUNC_SUBTRACT                  = 0x800A,
	GL_FUNC_REVERSE_SUBTRACT          = 0x800B,

	/* Separate Blend Functions */
	GL_BLEND_DST_RGB                  = 0x80C8,
	GL_BLEND_SRC_RGB                  = 0x80C9,
	GL_BLEND_DST_ALPHA                = 0x80CA,
	GL_BLEND_SRC_ALPHA                = 0x80CB,
	GL_CONSTANT_COLOR                 = 0x8001,
	GL_ONE_MINUS_CONSTANT_COLOR       = 0x8002,
	GL_CONSTANT_ALPHA                 = 0x8003,
	GL_ONE_MINUS_CONSTANT_ALPHA       = 0x8004,
	GL_BLEND_COLOR                    = 0x8005,

	/* Buffer Objects */
	GL_ARRAY_BUFFER                   = 0x8892,
	GL_ELEMENT_ARRAY_BUFFER           = 0x8893,
	GL_ARRAY_BUFFER_BINDING           = 0x8894,
	GL_ELEMENT_ARRAY_BUFFER_BINDING   = 0x8895,

	GL_STREAM_DRAW                    = 0x88E0,
	GL_STATIC_DRAW                    = 0x88E4,
	GL_DYNAMIC_DRAW                   = 0x88E8,

	GL_BUFFER_SIZE                    = 0x8764,
	GL_BUFFER_USAGE                   = 0x8765,

	GL_CURRENT_VERTEX_ATTRIB          = 0x8626,

	/* CullFaceMode */
	GL_FRONT                          = 0x0404,
	GL_BACK                           = 0x0405,
	GL_FRONT_AND_BACK                 = 0x0408,

	/* DepthFunction */
	/*      NEVER */
	/*      LESS */
	/*      EQUAL */
	/*      LEQUAL */
	/*      GREATER */
	/*      NOTEQUAL */
	/*      GEQUAL */
	/*      ALWAYS */

	/* EnableCap */
	/* TEXTURE_2D */
	GL_CULL_FACE                      = 0x0B44,
	GL_BLEND                          = 0x0BE2,
	GL_DITHER                         = 0x0BD0,
	GL_STENCIL_TEST                   = 0x0B90,
	GL_DEPTH_TEST                     = 0x0B71,
	GL_SCISSOR_TEST                   = 0x0C11,
	GL_POLYGON_OFFSET_FILL            = 0x8037,
	GL_SAMPLE_ALPHA_TO_COVERAGE       = 0x809E,
	GL_SAMPLE_COVERAGE                = 0x80A0,

	/* ErrorCode */
	GL_NO_ERROR                       = 0,
	GL_INVALID_ENUM                   = 0x0500,
	GL_INVALID_VALUE                  = 0x0501,
	GL_INVALID_OPERATION              = 0x0502,
	GL_OUT_OF_MEMORY                  = 0x0505,

	/* FrontFaceDirection */
	GL_CW                             = 0x0900,
	GL_CCW                            = 0x0901,

	/* GetPName */
	GL_LINE_WIDTH                     = 0x0B21,
	GL_ALIASED_POINT_SIZE_RANGE       = 0x846D,
	GL_ALIASED_LINE_WIDTH_RANGE       = 0x846E,
	GL_CULL_FACE_MODE                 = 0x0B45,
	GL_FRONT_FACE                     = 0x0B46,
	GL_DEPTH_RANGE                    = 0x0B70,
	GL_DEPTH_WRITEMASK                = 0x0B72,
	GL_DEPTH_CLEAR_VALUE              = 0x0B73,
	GL_DEPTH_FUNC                     = 0x0B74,
	GL_STENCIL_CLEAR_VALUE            = 0x0B91,
	GL_STENCIL_FUNC                   = 0x0B92,
	GL_STENCIL_FAIL                   = 0x0B94,
	GL_STENCIL_PASS_DEPTH_FAIL        = 0x0B95,
	GL_STENCIL_PASS_DEPTH_PASS        = 0x0B96,
	GL_STENCIL_REF                    = 0x0B97,
	GL_STENCIL_VALUE_MASK             = 0x0B93,
	GL_STENCIL_WRITEMASK              = 0x0B98,
	GL_STENCIL_BACK_FUNC              = 0x8800,
	GL_STENCIL_BACK_FAIL              = 0x8801,
	GL_STENCIL_BACK_PASS_DEPTH_FAIL   = 0x8802,
	GL_STENCIL_BACK_PASS_DEPTH_PASS   = 0x8803,
	GL_STENCIL_BACK_REF               = 0x8CA3,
	GL_STENCIL_BACK_VALUE_MASK        = 0x8CA4,
	GL_STENCIL_BACK_WRITEMASK         = 0x8CA5,
	GL_VIEWPORT                       = 0x0BA2,
	GL_SCISSOR_BOX                    = 0x0C10,
	/*      SCISSOR_TEST */
	GL_COLOR_CLEAR_VALUE              = 0x0C22,
	GL_COLOR_WRITEMASK                = 0x0C23,
	GL_UNPACK_ALIGNMENT               = 0x0CF5,
	GL_PACK_ALIGNMENT                 = 0x0D05,
	GL_MAX_TEXTURE_SIZE               = 0x0D33,
	GL_MAX_VIEWPORT_DIMS              = 0x0D3A,
	GL_SUBPIXEL_BITS                  = 0x0D50,
	GL_RED_BITS                       = 0x0D52,
	GL_GREEN_BITS                     = 0x0D53,
	GL_BLUE_BITS                      = 0x0D54,
	GL_ALPHA_BITS                     = 0x0D55,
	GL_DEPTH_BITS                     = 0x0D56,
	GL_STENCIL_BITS                   = 0x0D57,
	GL_POLYGON_OFFSET_UNITS           = 0x2A00,
	/*      POLYGON_OFFSET_FILL */
	GL_POLYGON_OFFSET_FACTOR          = 0x8038,
	GL_TEXTURE_BINDING_2D             = 0x8069,
	GL_SAMPLE_BUFFERS                 = 0x80A8,
	GL_SAMPLES                        = 0x80A9,
	GL_SAMPLE_COVERAGE_VALUE          = 0x80AA,
	GL_SAMPLE_COVERAGE_INVERT         = 0x80AB,

	/* GetTextureParameter */
	/*      TEXTURE_MAG_FILTER */
	/*      TEXTURE_MIN_FILTER */
	/*      TEXTURE_WRAP_S */
	/*      TEXTURE_WRAP_T */

	GL_COMPRESSED_TEXTURE_FORMATS     = 0x86A3,

	/* HintMode */
	GL_DONT_CARE                      = 0x1100,
	GL_FASTEST                        = 0x1101,
	GL_NICEST                         = 0x1102,

	/* HintTarget */
	GL_GENERATE_MIPMAP_HINT            = 0x8192,

	/* DataType */
	GL_BYTE                           = 0x1400,
	GL_UNSIGNED_BYTE                  = 0x1401,
	GL_SHORT                          = 0x1402,
	GL_UNSIGNED_SHORT                 = 0x1403,
	GL_INT                            = 0x1404,
	GL_UNSIGNED_INT                   = 0x1405,
	GL_FLOAT                          = 0x1406,

	/* PixelFormat */
	GL_DEPTH_COMPONENT                = 0x1902,
	GL_ALPHA                          = 0x1906,
	GL_RGB                            = 0x1907,
	GL_RGBA                           = 0x1908,
	GL_LUMINANCE                      = 0x1909,
	GL_LUMINANCE_ALPHA                = 0x190A,

	/* PixelType */
	/*      UNSIGNED_BYTE */
	GL_UNSIGNED_SHORT_4_4_4_4         = 0x8033,
	GL_UNSIGNED_SHORT_5_5_5_1         = 0x8034,
	GL_UNSIGNED_SHORT_5_6_5           = 0x8363,

	/* Shaders */
	GL_FRAGMENT_SHADER                  = 0x8B30,
	GL_VERTEX_SHADER                    = 0x8B31,
	GL_MAX_VERTEX_ATTRIBS               = 0x8869,
	GL_MAX_VERTEX_UNIFORM_VECTORS       = 0x8DFB,
	GL_MAX_VARYING_VECTORS              = 0x8DFC,
	GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS = 0x8B4D,
	GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS   = 0x8B4C,
	GL_MAX_TEXTURE_IMAGE_UNITS          = 0x8872,
	GL_MAX_FRAGMENT_UNIFORM_VECTORS     = 0x8DFD,
	GL_SHADER_TYPE                      = 0x8B4F,
	GL_DELETE_STATUS                    = 0x8B80,
	GL_LINK_STATUS                      = 0x8B82,
	GL_VALIDATE_STATUS                  = 0x8B83,
	GL_ATTACHED_SHADERS                 = 0x8B85,
	GL_ACTIVE_UNIFORMS                  = 0x8B86,
	GL_ACTIVE_ATTRIBUTES                = 0x8B89,
	GL_SHADING_LANGUAGE_VERSION         = 0x8B8C,
	GL_CURRENT_PROGRAM                  = 0x8B8D,

	/* StencilFunction */
	GL_NEVER                          = 0x0200,
	GL_LESS                           = 0x0201,
	GL_EQUAL                          = 0x0202,
	GL_LEQUAL                         = 0x0203,
	GL_GREATER                        = 0x0204,
	GL_NOTEQUAL                       = 0x0205,
	GL_GEQUAL                         = 0x0206,
	GL_ALWAYS                         = 0x0207,

	/* StencilOp */
	/*      ZERO */
	GL_KEEP                           = 0x1E00,
	GL_REPLACE                        = 0x1E01,
	GL_INCR                           = 0x1E02,
	GL_DECR                           = 0x1E03,
	GL_INVERT                         = 0x150A,
	GL_INCR_WRAP                      = 0x8507,
	GL_DECR_WRAP                      = 0x8508,

	/* StringName */
	GL_VENDOR                         = 0x1F00,
	GL_RENDERER                       = 0x1F01,
	GL_VERSION                        = 0x1F02,

	/* TextureMagFilter */
	GL_NEAREST                        = 0x2600,
	GL_LINEAR                         = 0x2601,

	/* TextureMinFilter */
	/*      NEAREST */
	/*      LINEAR */
	GL_NEAREST_MIPMAP_NEAREST         = 0x2700,
	GL_LINEAR_MIPMAP_NEAREST          = 0x2701,
	GL_NEAREST_MIPMAP_LINEAR          = 0x2702,
	GL_LINEAR_MIPMAP_LINEAR           = 0x2703,

	/* TextureParameterName */
	GL_TEXTURE_MAG_FILTER             = 0x2800,
	GL_TEXTURE_MIN_FILTER             = 0x2801,
	GL_TEXTURE_WRAP_S                 = 0x2802,
	GL_TEXTURE_WRAP_T                 = 0x2803,

	/* TextureTarget */
	GL_TEXTURE_2D                     = 0x0DE1,
	GL_TEXTURE                        = 0x1702,

	GL_TEXTURE_CUBE_MAP               = 0x8513,
	GL_TEXTURE_BINDING_CUBE_MAP       = 0x8514,
	GL_TEXTURE_CUBE_MAP_POSITIVE_X    = 0x8515,
	GL_TEXTURE_CUBE_MAP_NEGATIVE_X    = 0x8516,
	GL_TEXTURE_CUBE_MAP_POSITIVE_Y    = 0x8517,
	GL_TEXTURE_CUBE_MAP_NEGATIVE_Y    = 0x8518,
	GL_TEXTURE_CUBE_MAP_POSITIVE_Z    = 0x8519,
	GL_TEXTURE_CUBE_MAP_NEGATIVE_Z    = 0x851A,
	GL_MAX_CUBE_MAP_TEXTURE_SIZE      = 0x851C,

	/* TextureUnit */
	GL_TEXTURE0                       = 0x84C0,
	GL_TEXTURE1                       = 0x84C1,
	GL_TEXTURE2                       = 0x84C2,
	GL_TEXTURE3                       = 0x84C3,
	GL_TEXTURE4                       = 0x84C4,
	GL_TEXTURE5                       = 0x84C5,
	GL_TEXTURE6                       = 0x84C6,
	GL_TEXTURE7                       = 0x84C7,
	GL_TEXTURE8                       = 0x84C8,
	GL_TEXTURE9                       = 0x84C9,
	GL_TEXTURE10                      = 0x84CA,
	GL_TEXTURE11                      = 0x84CB,
	GL_TEXTURE12                      = 0x84CC,
	GL_TEXTURE13                      = 0x84CD,
	GL_TEXTURE14                      = 0x84CE,
	GL_TEXTURE15                      = 0x84CF,
	GL_TEXTURE16                      = 0x84D0,
	GL_TEXTURE17                      = 0x84D1,
	GL_TEXTURE18                      = 0x84D2,
	GL_TEXTURE19                      = 0x84D3,
	GL_TEXTURE20                      = 0x84D4,
	GL_TEXTURE21                      = 0x84D5,
	GL_TEXTURE22                      = 0x84D6,
	GL_TEXTURE23                      = 0x84D7,
	GL_TEXTURE24                      = 0x84D8,
	GL_TEXTURE25                      = 0x84D9,
	GL_TEXTURE26                      = 0x84DA,
	GL_TEXTURE27                      = 0x84DB,
	GL_TEXTURE28                      = 0x84DC,
	GL_TEXTURE29                      = 0x84DD,
	GL_TEXTURE30                      = 0x84DE,
	GL_TEXTURE31                      = 0x84DF,
	GL_ACTIVE_TEXTURE                 = 0x84E0,

	/* TextureWrapMode */
	GL_REPEAT                         = 0x2901,
	GL_CLAMP_TO_EDGE                  = 0x812F,
	GL_MIRRORED_REPEAT                = 0x8370,

	/* Uniform Types */
	GL_FLOAT_VEC2                     = 0x8B50,
	GL_FLOAT_VEC3                     = 0x8B51,
	GL_FLOAT_VEC4                     = 0x8B52,
	GL_INT_VEC2                       = 0x8B53,
	GL_INT_VEC3                       = 0x8B54,
	GL_INT_VEC4                       = 0x8B55,
	GL_BOOL                           = 0x8B56,
	GL_BOOL_VEC2                      = 0x8B57,
	GL_BOOL_VEC3                      = 0x8B58,
	GL_BOOL_VEC4                      = 0x8B59,
	GL_FLOAT_MAT2                     = 0x8B5A,
	GL_FLOAT_MAT3                     = 0x8B5B,
	GL_FLOAT_MAT4                     = 0x8B5C,
	GL_SAMPLER_2D                     = 0x8B5E,
	GL_SAMPLER_CUBE                   = 0x8B60,

	/* Vertex Arrays */
	GL_VERTEX_ATTRIB_ARRAY_ENABLED        = 0x8622,
	GL_VERTEX_ATTRIB_ARRAY_SIZE           = 0x8623,
	GL_VERTEX_ATTRIB_ARRAY_STRIDE         = 0x8624,
	GL_VERTEX_ATTRIB_ARRAY_TYPE           = 0x8625,
	GL_VERTEX_ATTRIB_ARRAY_NORMALIZED     = 0x886A,
	GL_VERTEX_ATTRIB_ARRAY_POINTER        = 0x8645,
	GL_VERTEX_ATTRIB_ARRAY_BUFFER_BINDING = 0x889F,

	/* Read Format */
	GL_IMPLEMENTATION_COLOR_READ_TYPE   = 0x8B9A,
	GL_IMPLEMENTATION_COLOR_READ_FORMAT = 0x8B9B,

	/* Shader Source */
	GL_COMPILE_STATUS                 = 0x8B81,

	/* Shader Precision-Specified Types */
	GL_LOW_FLOAT                      = 0x8DF0,
	GL_MEDIUM_FLOAT                   = 0x8DF1,
	GL_HIGH_FLOAT                     = 0x8DF2,
	GL_LOW_INT                        = 0x8DF3,
	GL_MEDIUM_INT                     = 0x8DF4,
	GL_HIGH_INT                       = 0x8DF5,

	/* Framebuffer Object. */
	GL_FRAMEBUFFER                    = 0x8D40,
	GL_RENDERBUFFER                   = 0x8D41,

	GL_RGBA4                          = 0x8056,
	GL_RGB5_A1                        = 0x8057,
	GL_RGBA8                          = 0x8058,
	GL_RGB565                         = 0x8D62,
	GL_DEPTH_COMPONENT16              = 0x81A5,
	GL_STENCIL_INDEX8                 = 0x8D48,
	GL_DEPTH_STENCIL                  = 0x84F9,

	GL_RENDERBUFFER_WIDTH             = 0x8D42,
	GL_RENDERBUFFER_HEIGHT            = 0x8D43,
	GL_RENDERBUFFER_INTERNAL_FORMAT   = 0x8D44,
	GL_RENDERBUFFER_RED_SIZE          = 0x8D50,
	GL_RENDERBUFFER_GREEN_SIZE        = 0x8D51,
	GL_RENDERBUFFER_BLUE_SIZE         = 0x8D52,
	GL_RENDERBUFFER_ALPHA_SIZE        = 0x8D53,
	GL_RENDERBUFFER_DEPTH_SIZE        = 0x8D54,
	GL_RENDERBUFFER_STENCIL_SIZE      = 0x8D55,

	GL_FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE           = 0x8CD0,
	GL_FRAMEBUFFER_ATTACHMENT_OBJECT_NAME           = 0x8CD1,
	GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LEVEL         = 0x8CD2,
	GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_CUBE_MAP_FACE = 0x8CD3,

	GL_COLOR_ATTACHMENT0              = 0x8CE0,
	GL_DEPTH_ATTACHMENT               = 0x8D00,
	GL_STENCIL_ATTACHMENT             = 0x8D20,
	GL_DEPTH_STENCIL_ATTACHMENT       = 0x821A,

	GL_NONE                           = 0,

	GL_FRAMEBUFFER_COMPLETE                      = 0x8CD5,
	GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT         = 0x8CD6,
	GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT = 0x8CD7,
	GL_FRAMEBUFFER_INCOMPLETE_DIMENSIONS         = 0x8CD9,
	GL_FRAMEBUFFER_UNSUPPORTED                   = 0x8CDD,

	GL_FRAMEBUFFER_BINDING            = 0x8CA6,
	GL_RENDERBUFFER_BINDING           = 0x8CA7,
	GL_MAX_RENDERBUFFER_SIZE          = 0x84E8,

	GL_INVALID_FRAMEBUFFER_OPERATION  = 0x0506,

	/* WebGL-specific enums */
	GL_UNPACK_FLIP_Y_WEBGL            = 0x9240,
	GL_UNPACK_PREMULTIPLY_ALPHA_WEBGL = 0x9241,
	GL_CONTEXT_LOST_WEBGL             = 0x9242,
	GL_UNPACK_COLORSPACE_CONVERSION_WEBGL = 0x9243,
	GL_BROWSER_DEFAULT_WEBGL          = 0x9244,


	GL_READ_BUFFER                                   = 0x0C02,
	GL_UNPACK_ROW_LENGTH                             = 0x0CF2,
	GL_UNPACK_SKIP_ROWS                              = 0x0CF3,
	GL_UNPACK_SKIP_PIXELS                            = 0x0CF4,
	GL_PACK_ROW_LENGTH                               = 0x0D02,
	GL_PACK_SKIP_ROWS                                = 0x0D03,
	GL_PACK_SKIP_PIXELS                              = 0x0D04,
	GL_COLOR                                         = 0x1800,
	GL_DEPTH                                         = 0x1801,
	GL_STENCIL                                       = 0x1802,
	GL_RED                                           = 0x1903,
	GL_RGB8                                          = 0x8051,
	GL_RGB10_A2                                      = 0x8059,
	GL_TEXTURE_BINDING_3D                            = 0x806A,
	GL_UNPACK_SKIP_IMAGES                            = 0x806D,
	GL_UNPACK_IMAGE_HEIGHT                           = 0x806E,
	GL_TEXTURE_3D                                    = 0x806F,
	GL_TEXTURE_WRAP_R                                = 0x8072,
	GL_MAX_3D_TEXTURE_SIZE                           = 0x8073,
	GL_UNSIGNED_INT_2_10_10_10_REV                   = 0x8368,
	GL_MAX_ELEMENTS_VERTICES                         = 0x80E8,
	GL_MAX_ELEMENTS_INDICES                          = 0x80E9,
	GL_TEXTURE_MIN_LOD                               = 0x813A,
	GL_TEXTURE_MAX_LOD                               = 0x813B,
	GL_TEXTURE_BASE_LEVEL                            = 0x813C,
	GL_TEXTURE_MAX_LEVEL                             = 0x813D,
	GL_MIN                                           = 0x8007,
	GL_MAX                                           = 0x8008,
	GL_DEPTH_COMPONENT24                             = 0x81A6,
	GL_MAX_TEXTURE_LOD_BIAS                          = 0x84FD,
	GL_TEXTURE_COMPARE_MODE                          = 0x884C,
	GL_TEXTURE_COMPARE_FUNC                          = 0x884D,
	GL_CURRENT_QUERY                                 = 0x8865,
	GL_QUERY_RESULT                                  = 0x8866,
	GL_QUERY_RESULT_AVAILABLE                        = 0x8867,
	GL_STREAM_READ                                   = 0x88E1,
	GL_STREAM_COPY                                   = 0x88E2,
	GL_STATIC_READ                                   = 0x88E5,
	GL_STATIC_COPY                                   = 0x88E6,
	GL_DYNAMIC_READ                                  = 0x88E9,
	GL_DYNAMIC_COPY                                  = 0x88EA,
	GL_MAX_DRAW_BUFFERS                              = 0x8824,
	GL_DRAW_BUFFER0                                  = 0x8825,
	GL_DRAW_BUFFER1                                  = 0x8826,
	GL_DRAW_BUFFER2                                  = 0x8827,
	GL_DRAW_BUFFER3                                  = 0x8828,
	GL_DRAW_BUFFER4                                  = 0x8829,
	GL_DRAW_BUFFER5                                  = 0x882A,
	GL_DRAW_BUFFER6                                  = 0x882B,
	GL_DRAW_BUFFER7                                  = 0x882C,
	GL_DRAW_BUFFER8                                  = 0x882D,
	GL_DRAW_BUFFER9                                  = 0x882E,
	GL_DRAW_BUFFER10                                 = 0x882F,
	GL_DRAW_BUFFER11                                 = 0x8830,
	GL_DRAW_BUFFER12                                 = 0x8831,
	GL_DRAW_BUFFER13                                 = 0x8832,
	GL_DRAW_BUFFER14                                 = 0x8833,
	GL_DRAW_BUFFER15                                 = 0x8834,
	GL_MAX_FRAGMENT_UNIFORM_COMPONENTS               = 0x8B49,
	GL_MAX_VERTEX_UNIFORM_COMPONENTS                 = 0x8B4A,
	GL_SAMPLER_3D                                    = 0x8B5F,
	GL_SAMPLER_2D_SHADOW                             = 0x8B62,
	GL_FRAGMENT_SHADER_DERIVATIVE_HINT               = 0x8B8B,
	GL_PIXEL_PACK_BUFFER                             = 0x88EB,
	GL_PIXEL_UNPACK_BUFFER                           = 0x88EC,
	GL_PIXEL_PACK_BUFFER_BINDING                     = 0x88ED,
	GL_PIXEL_UNPACK_BUFFER_BINDING                   = 0x88EF,
	GL_FLOAT_MAT2x3                                  = 0x8B65,
	GL_FLOAT_MAT2x4                                  = 0x8B66,
	GL_FLOAT_MAT3x2                                  = 0x8B67,
	GL_FLOAT_MAT3x4                                  = 0x8B68,
	GL_FLOAT_MAT4x2                                  = 0x8B69,
	GL_FLOAT_MAT4x3                                  = 0x8B6A,
	GL_SRGB                                          = 0x8C40,
	GL_SRGB8                                         = 0x8C41,
	GL_SRGB8_ALPHA8                                  = 0x8C43,
	GL_COMPARE_REF_TO_TEXTURE                        = 0x884E,
	GL_RGBA32F                                       = 0x8814,
	GL_RGB32F                                        = 0x8815,
	GL_RGBA16F                                       = 0x881A,
	GL_RGB16F                                        = 0x881B,
	GL_VERTEX_ATTRIB_ARRAY_INTEGER                   = 0x88FD,
	GL_MAX_ARRAY_TEXTURE_LAYERS                      = 0x88FF,
	GL_MIN_PROGRAM_TEXEL_OFFSET                      = 0x8904,
	GL_MAX_PROGRAM_TEXEL_OFFSET                      = 0x8905,
	GL_MAX_VARYING_COMPONENTS                        = 0x8B4B,
	GL_TEXTURE_2D_ARRAY                              = 0x8C1A,
	GL_TEXTURE_BINDING_2D_ARRAY                      = 0x8C1D,
	GL_R11F_G11F_B10F                                = 0x8C3A,
	GL_UNSIGNED_INT_10F_11F_11F_REV                  = 0x8C3B,
	GL_RGB9_E5                                       = 0x8C3D,
	GL_UNSIGNED_INT_5_9_9_9_REV                      = 0x8C3E,
	GL_TRANSFORM_FEEDBACK_BUFFER_MODE                = 0x8C7F,
	GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS    = 0x8C80,
	GL_TRANSFORM_FEEDBACK_VARYINGS                   = 0x8C83,
	GL_TRANSFORM_FEEDBACK_BUFFER_START               = 0x8C84,
	GL_TRANSFORM_FEEDBACK_BUFFER_SIZE                = 0x8C85,
	GL_TRANSFORM_FEEDBACK_PRIMITIVES_WRITTEN         = 0x8C88,
	GL_RASTERIZER_DISCARD                            = 0x8C89,
	GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS = 0x8C8A,
	GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS       = 0x8C8B,
	GL_INTERLEAVED_ATTRIBS                           = 0x8C8C,
	GL_SEPARATE_ATTRIBS                              = 0x8C8D,
	GL_TRANSFORM_FEEDBACK_BUFFER                     = 0x8C8E,
	GL_TRANSFORM_FEEDBACK_BUFFER_BINDING             = 0x8C8F,
	GL_RGBA32UI                                      = 0x8D70,
	GL_RGB32UI                                       = 0x8D71,
	GL_RGBA16UI                                      = 0x8D76,
	GL_RGB16UI                                       = 0x8D77,
	GL_RGBA8UI                                       = 0x8D7C,
	GL_RGB8UI                                        = 0x8D7D,
	GL_RGBA32I                                       = 0x8D82,
	GL_RGB32I                                        = 0x8D83,
	GL_RGBA16I                                       = 0x8D88,
	GL_RGB16I                                        = 0x8D89,
	GL_RGBA8I                                        = 0x8D8E,
	GL_RGB8I                                         = 0x8D8F,
	GL_RED_INTEGER                                   = 0x8D94,
	GL_RGB_INTEGER                                   = 0x8D98,
	GL_RGBA_INTEGER                                  = 0x8D99,
	GL_SAMPLER_2D_ARRAY                              = 0x8DC1,
	GL_SAMPLER_2D_ARRAY_SHADOW                       = 0x8DC4,
	GL_SAMPLER_CUBE_SHADOW                           = 0x8DC5,
	GL_UNSIGNED_INT_VEC2                             = 0x8DC6,
	GL_UNSIGNED_INT_VEC3                             = 0x8DC7,
	GL_UNSIGNED_INT_VEC4                             = 0x8DC8,
	GL_INT_SAMPLER_2D                                = 0x8DCA,
	GL_INT_SAMPLER_3D                                = 0x8DCB,
	GL_INT_SAMPLER_CUBE                              = 0x8DCC,
	GL_INT_SAMPLER_2D_ARRAY                          = 0x8DCF,
	GL_UNSIGNED_INT_SAMPLER_2D                       = 0x8DD2,
	GL_UNSIGNED_INT_SAMPLER_3D                       = 0x8DD3,
	GL_UNSIGNED_INT_SAMPLER_CUBE                     = 0x8DD4,
	GL_UNSIGNED_INT_SAMPLER_2D_ARRAY                 = 0x8DD7,
	GL_DEPTH_COMPONENT32F                            = 0x8CAC,
	GL_DEPTH32F_STENCIL8                             = 0x8CAD,
	GL_FLOAT_32_UNSIGNED_INT_24_8_REV                = 0x8DAD,
	GL_FRAMEBUFFER_ATTACHMENT_COLOR_ENCODING         = 0x8210,
	GL_FRAMEBUFFER_ATTACHMENT_COMPONENT_TYPE         = 0x8211,
	GL_FRAMEBUFFER_ATTACHMENT_RED_SIZE               = 0x8212,
	GL_FRAMEBUFFER_ATTACHMENT_GREEN_SIZE             = 0x8213,
	GL_FRAMEBUFFER_ATTACHMENT_BLUE_SIZE              = 0x8214,
	GL_FRAMEBUFFER_ATTACHMENT_ALPHA_SIZE             = 0x8215,
	GL_FRAMEBUFFER_ATTACHMENT_DEPTH_SIZE             = 0x8216,
	GL_FRAMEBUFFER_ATTACHMENT_STENCIL_SIZE           = 0x8217,
	GL_FRAMEBUFFER_DEFAULT                           = 0x8218,
	GL_UNSIGNED_INT_24_8                             = 0x84FA,
	GL_DEPTH24_STENCIL8                              = 0x88F0,
	GL_UNSIGNED_NORMALIZED                           = 0x8C17,
	GL_DRAW_FRAMEBUFFER_BINDING                      = 0x8CA6, /* Same as FRAMEBUFFER_BINDING */
	GL_READ_FRAMEBUFFER                              = 0x8CA8,
	GL_DRAW_FRAMEBUFFER                              = 0x8CA9,
	GL_READ_FRAMEBUFFER_BINDING                      = 0x8CAA,
	GL_RENDERBUFFER_SAMPLES                          = 0x8CAB,
	GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LAYER          = 0x8CD4,
	GL_MAX_COLOR_ATTACHMENTS                         = 0x8CDF,
	GL_COLOR_ATTACHMENT1                             = 0x8CE1,
	GL_COLOR_ATTACHMENT2                             = 0x8CE2,
	GL_COLOR_ATTACHMENT3                             = 0x8CE3,
	GL_COLOR_ATTACHMENT4                             = 0x8CE4,
	GL_COLOR_ATTACHMENT5                             = 0x8CE5,
	GL_COLOR_ATTACHMENT6                             = 0x8CE6,
	GL_COLOR_ATTACHMENT7                             = 0x8CE7,
	GL_COLOR_ATTACHMENT8                             = 0x8CE8,
	GL_COLOR_ATTACHMENT9                             = 0x8CE9,
	GL_COLOR_ATTACHMENT10                            = 0x8CEA,
	GL_COLOR_ATTACHMENT11                            = 0x8CEB,
	GL_COLOR_ATTACHMENT12                            = 0x8CEC,
	GL_COLOR_ATTACHMENT13                            = 0x8CED,
	GL_COLOR_ATTACHMENT14                            = 0x8CEE,
	GL_COLOR_ATTACHMENT15                            = 0x8CEF,
	GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE            = 0x8D56,
	GL_MAX_SAMPLES                                   = 0x8D57,
	GL_HALF_FLOAT                                    = 0x140B,
	GL_RG                                            = 0x8227,
	GL_RG_INTEGER                                    = 0x8228,
	GL_R8                                            = 0x8229,
	GL_RG8                                           = 0x822B,
	GL_R16F                                          = 0x822D,
	GL_R32F                                          = 0x822E,
	GL_RG16F                                         = 0x822F,
	GL_RG32F                                         = 0x8230,
	GL_R8I                                           = 0x8231,
	GL_R8UI                                          = 0x8232,
	GL_R16I                                          = 0x8233,
	GL_R16UI                                         = 0x8234,
	GL_R32I                                          = 0x8235,
	GL_R32UI                                         = 0x8236,
	GL_RG8I                                          = 0x8237,
	GL_RG8UI                                         = 0x8238,
	GL_RG16I                                         = 0x8239,
	GL_RG16UI                                        = 0x823A,
	GL_RG32I                                         = 0x823B,
	GL_RG32UI                                        = 0x823C,
	GL_VERTEX_ARRAY_BINDING                          = 0x85B5,
	GL_R8_SNORM                                      = 0x8F94,
	GL_RG8_SNORM                                     = 0x8F95,
	GL_RGB8_SNORM                                    = 0x8F96,
	GL_RGBA8_SNORM                                   = 0x8F97,
	GL_SIGNED_NORMALIZED                             = 0x8F9C,
	GL_COPY_READ_BUFFER                              = 0x8F36,
	GL_COPY_WRITE_BUFFER                             = 0x8F37,
	GL_COPY_READ_BUFFER_BINDING                      = 0x8F36, /* Same as COPY_READ_BUFFER */
	GL_COPY_WRITE_BUFFER_BINDING                     = 0x8F37, /* Same as COPY_WRITE_BUFFER */
	GL_UNIFORM_BUFFER                                = 0x8A11,
	GL_UNIFORM_BUFFER_BINDING                        = 0x8A28,
	GL_UNIFORM_BUFFER_START                          = 0x8A29,
	GL_UNIFORM_BUFFER_SIZE                           = 0x8A2A,
	GL_MAX_VERTEX_UNIFORM_BLOCKS                     = 0x8A2B,
	GL_MAX_FRAGMENT_UNIFORM_BLOCKS                   = 0x8A2D,
	GL_MAX_COMBINED_UNIFORM_BLOCKS                   = 0x8A2E,
	GL_MAX_UNIFORM_BUFFER_BINDINGS                   = 0x8A2F,
	GL_MAX_UNIFORM_BLOCK_SIZE                        = 0x8A30,
	GL_MAX_COMBINED_VERTEX_UNIFORM_COMPONENTS        = 0x8A31,
	GL_MAX_COMBINED_FRAGMENT_UNIFORM_COMPONENTS      = 0x8A33,
	GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT               = 0x8A34,
	GL_ACTIVE_UNIFORM_BLOCKS                         = 0x8A36,
	GL_UNIFORM_TYPE                                  = 0x8A37,
	GL_UNIFORM_SIZE                                  = 0x8A38,
	GL_UNIFORM_BLOCK_INDEX                           = 0x8A3A,
	GL_UNIFORM_OFFSET                                = 0x8A3B,
	GL_UNIFORM_ARRAY_STRIDE                          = 0x8A3C,
	GL_UNIFORM_MATRIX_STRIDE                         = 0x8A3D,
	GL_UNIFORM_IS_ROW_MAJOR                          = 0x8A3E,
	GL_UNIFORM_BLOCK_BINDING                         = 0x8A3F,
	GL_UNIFORM_BLOCK_DATA_SIZE                       = 0x8A40,
	GL_UNIFORM_BLOCK_ACTIVE_UNIFORMS                 = 0x8A42,
	GL_UNIFORM_BLOCK_ACTIVE_UNIFORM_INDICES          = 0x8A43,
	GL_UNIFORM_BLOCK_REFERENCED_BY_VERTEX_SHADER     = 0x8A44,
	GL_UNIFORM_BLOCK_REFERENCED_BY_FRAGMENT_SHADER   = 0x8A46,
	GL_INVALID_INDEX                                 = 0xFFFFFFFF,
	GL_MAX_VERTEX_OUTPUT_COMPONENTS                  = 0x9122,
	GL_MAX_FRAGMENT_INPUT_COMPONENTS                 = 0x9125,
	GL_MAX_SERVER_WAIT_TIMEOUT                       = 0x9111,
	GL_OBJECT_TYPE                                   = 0x9112,
	GL_SYNC_CONDITION                                = 0x9113,
	GL_SYNC_STATUS                                   = 0x9114,
	GL_SYNC_FLAGS                                    = 0x9115,
	GL_SYNC_FENCE                                    = 0x9116,
	GL_SYNC_GPU_COMMANDS_COMPLETE                    = 0x9117,
	GL_UNSIGNALED                                    = 0x9118,
	GL_SIGNALED                                      = 0x9119,
	GL_ALREADY_SIGNALED                              = 0x911A,
	GL_TIMEOUT_EXPIRED                               = 0x911B,
	GL_CONDITION_SATISFIED                           = 0x911C,
	GL_WAIT_FAILED                                   = 0x911D,
	GL_SYNC_FLUSH_COMMANDS_BIT                       = 0x00000001,
	GL_VERTEX_ATTRIB_ARRAY_DIVISOR                   = 0x88FE,
	GL_ANY_SAMPLES_PASSED                            = 0x8C2F,
	GL_ANY_SAMPLES_PASSED_CONSERVATIVE               = 0x8D6A,
	GL_SAMPLER_BINDING                               = 0x8919,
	GL_RGB10_A2UI                                    = 0x906F,
	GL_INT_2_10_10_10_REV                            = 0x8D9F,
	GL_TRANSFORM_FEEDBACK                            = 0x8E22,
	GL_TRANSFORM_FEEDBACK_PAUSED                     = 0x8E23,
	GL_TRANSFORM_FEEDBACK_ACTIVE                     = 0x8E24,
	GL_TRANSFORM_FEEDBACK_BINDING                    = 0x8E25,
	GL_TEXTURE_IMMUTABLE_FORMAT                      = 0x912F,
	GL_MAX_ELEMENT_INDEX                             = 0x8D6B,
	GL_TEXTURE_IMMUTABLE_LEVELS                      = 0x82DF,

	/* WebGL-specific enums */
	GL_MAX_CLIENT_WAIT_TIMEOUT_WEBGL                 = 0x9247,
};

#define GL_TIMEOUT_IGNORED                              = -1;

#define WEBGL_IMPORT(name) extern "C" __attribute__((import_module("gl"), import_name(#name)))

WEBGL_IMPORT(createVertexArray) int gl_create_vertex_array();
WEBGL_IMPORT(deleteVertexArray) void gl_delete_vertex_array(int vao);
WEBGL_IMPORT(bindVertexArray) void gl_bind_vertex_array(int vao);
WEBGL_IMPORT(enableVertexAttribArray) void gl_enable_vertex_attrib_array(GLuint idx);
WEBGL_IMPORT(disableVertexAttribArray) void gl_disable_vertex_attrib_array(GLuint idx);
WEBGL_IMPORT(vertexAttribPointer) void gl_vertex_attrib_pointer(
		GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, GLintptr offset);

WEBGL_IMPORT(createBuffer) int gl_create_buffer();
WEBGL_IMPORT(deleteBuffer) void gl_delete_buffer(int buffer);
WEBGL_IMPORT(bindBuffer) void gl_bind_buffer(GLenum target, int buffer);
WEBGL_IMPORT(bindBufferRange) void gl_bind_buffer_range(
		GLenum target, GLuint index, int buffer, GLintptr offset, GLsizeiptr size);
WEBGL_IMPORT(bufferData) void gl_buffer_data(GLenum target, GLsizeiptr size, GLenum usage);
WEBGL_IMPORT(bufferSubData) void gl_buffer_sub_data(
		GLenum target, GLintptr offset, void const *data, GLsizeiptr size);
WEBGL_IMPORT(copyBufferSubData) void gl_copy_buffer_sub_data(
		GLenum readTarget, GLenum writeTarget, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size);

WEBGL_IMPORT(attachShader) void gl_attach_shader(int program, int shader);
WEBGL_IMPORT(compileShader) void gl_compile_shader(int shader);
WEBGL_IMPORT(createProgram) int gl_create_program();
WEBGL_IMPORT(createShader) int gl_create_shader(GLenum type);
WEBGL_IMPORT(deleteProgram) void gl_delete_program(int program);
WEBGL_IMPORT(deleteShader) void gl_delete_shader(int shader);
WEBGL_IMPORT(detachShader) void gl_detach_shader(int program, int shader);
WEBGL_IMPORT(linkProgram) void gl_link_program(int program);
WEBGL_IMPORT(shaderSource) void gl_shader_source(int shader, char const *source, GLsizeiptr length);
WEBGL_IMPORT(useProgram) void gl_use_program(int program);

WEBGL_IMPORT(clear) void gl_clear(GLbitfield mask);
WEBGL_IMPORT(clearColor) void gl_clear_color(GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha);
WEBGL_IMPORT(clearDepth) void gl_clear_depth(GLclampf depth);
WEBGL_IMPORT(clearStencil) void gl_clear_stencil(GLint s);
WEBGL_IMPORT(drawArrays) void gl_draw_arrays(GLenum mode, GLint first, GLsizei count);

WEBGL_IMPORT(fenceSync) int gl_fence_sync(GLenum condition, GLbitfield flags);
WEBGL_IMPORT(deleteSync) void gl_delete_sync(int sync);
WEBGL_IMPORT(clientWaitSync) GLenum gl_client_wait_sync(int sync, GLbitfield flags, GLuint64 timeout);

