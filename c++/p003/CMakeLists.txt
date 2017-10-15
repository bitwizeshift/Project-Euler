# Normal Solution
add_executable(cpp-p003 p003.cpp)

add_test( NAME "cpp-p003"
          COMMAND "$<TARGET_FILE:cpp-p003>" )

set_tests_properties(
    "cpp-p003"
  PROPERTIES
    PASS_REGULAR_EXPRESSION "6857"
)
