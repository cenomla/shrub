project('shrub', ['c', 'cpp'],
  default_options : [
    'default_library=static',
    'cpp_eh=none',
    'cpp_rtti=false',
    'cpp_std=c++17',
    'warning_level=3',
    'werror=true',
    'b_ndebug=if-release' ])

add_global_arguments(
  '-nostdlib',
  '-DOAK_UTIL_FREESTANDING',
  language: 'cpp')

cxx = meson.get_compiler('cpp')
cxx_id = cxx.get_id()
if cxx_id == 'gcc'
  add_global_arguments(
    '-Wconversion',
    '-Wdouble-promotion',
    '-Wshadow',
    '-Wno-maybe-uninitialized',
    '-Wno-error=class-memaccess',
    '-Wno-error=shadow',
    '-Wno-error=format-truncation',
    language: 'cpp')
  if get_option('buildtype') == 'release'
    add_global_arguments(
      '-Wno-unused',
      language: 'cpp')
  endif
elif cxx_id == 'clang'
elif cxx_id == 'msvc'
  add_global_arguments(
    '/wd4324', # struct padding
    '/wd4251', # dll interface
    language: 'cpp')
endif

oak_util = subproject('oak_util')
oak_math = subproject('oak_math')

deps = [
  cxx.find_library('m', required: false),
  cxx.find_library('dl', required: false),
  oak_util.get_variable('oak_util_dep'),
  oak_math.get_variable('oak_math_dep'),
]

#shrub_lib = library('shrub', ['shrub.cpp'], install: true)

example = executable(
  'shrub_example',
  ['example.cpp'],
  dependencies: deps,
  install: true)

