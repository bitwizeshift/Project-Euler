# Normal Solution
add_executable(cpp-p005 p005.cpp)

add_test( NAME "cpp-p005"
          COMMAND "$<TARGET_FILE:cpp-p005>" )

set_tests_properties(
    "cpp-p005"
  PROPERTIES
    PASS_REGULAR_EXPRESSION "232792560"
)
