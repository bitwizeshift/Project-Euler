# Normal Solution
add_executable(cpp-p006 p006.cpp)

# Alternative Solution
add_executable(cpp-p006-alternate p006-templated.cpp)


add_test( NAME "cpp-p006"
          COMMAND "$<TARGET_FILE:cpp-p006>" )

add_test( NAME "cpp-p006-alternate"
          COMMAND "$<TARGET_FILE:cpp-p006-alternate>" )

set_tests_properties(
    "cpp-p006" "cpp-p006-alternate"
  PROPERTIES
    PASS_REGULAR_EXPRESSION "25164150"
)
