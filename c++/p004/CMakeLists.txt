# Normal Solution
add_executable(cpp-p004 p004.cpp)

add_test( NAME "cpp-p004"
          COMMAND "$<TARGET_FILE:cpp-p004>" )

set_tests_properties(
    "cpp-p004"
  PROPERTIES
    PASS_REGULAR_EXPRESSION "906609"
)
