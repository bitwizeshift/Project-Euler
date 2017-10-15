# Normal Solution
add_executable(cpp-p002 p002.cpp)

add_test( NAME "cpp-p002"
          COMMAND "$<TARGET_FILE:cpp-p002>" )

set_tests_properties(
    "cpp-p002"
  PROPERTIES
    PASS_REGULAR_EXPRESSION "4613732"
)
