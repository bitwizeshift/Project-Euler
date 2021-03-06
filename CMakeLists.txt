cmake_minimum_required (VERSION 2.6)
enable_testing()
project(Project-Euler)

# Make everything output to /bin
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Options
option(EULER_COMPILE_C_SOLUTIONS "Enable C solutions" off)
option(EULER_COMPILE_CXX_SOLUTIONS "Enable C++ solutions (on by default)" on)
option(EULER_COMPILE_SWIFT_SOLUTIONS "Enable swift solutions" off)
option(EULER_COMPILE_RUST_SOLUTIONS "Enable rust solutions" off)
option(EULER_COMPILE_PYTHON_SOLUTIONS "Enable python solutions" off)

# Determine languages to build based on options
if(EULER_COMPILE_C_SOLUTIONS)
  enable_language(C)
  add_subdirectory(c)
endif()
if(EULER_COMPILE_CXX_SOLUTIONS)
  enable_language(CXX)
  add_subdirectory(c++)
endif()
if(EULER_COMPILE_SWIFT_SOLUTIONS)
  enable_language(Swift)
  add_subdirectory(swift)
endif()
if(EULER_COMPILE_RUST_SOLUTIONS)
  enable_language(Rust)
  add_subdirectory(rust)
endif()
if(EULER_COMPILE_PYTHON_SOLUTIONS)
  enable_language(Python)
  add_subdirectory(python)
endif()
