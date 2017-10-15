# Normal Solution
add_executable(cpp-p007 p007.cpp)

add_test( NAME "cpp-p007"
          COMMAND "$<TARGET_FILE:cpp-p007>" )

set_tests_properties(
    "cpp-p007"
  PROPERTIES
    PASS_REGULAR_EXPRESSION "104743"
)
