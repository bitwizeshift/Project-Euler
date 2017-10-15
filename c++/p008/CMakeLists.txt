# Normal Solution
add_executable(cpp-p008 p008.cpp)

add_test( NAME "cpp-p008"
          COMMAND "$<TARGET_FILE:cpp-p008>" )

set_tests_properties(
    "cpp-p008"
  PROPERTIES
    PASS_REGULAR_EXPRESSION "23514624000"
)
