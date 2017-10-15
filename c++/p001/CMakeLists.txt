# Normal Solution
add_executable(cpp-p001 p001.cpp)

# Alternative Solution
add_executable(cpp-p001-alternate p001-templated.cpp)

add_test( NAME "cpp-p001"
          COMMAND "$<TARGET_FILE:cpp-p001>" )

add_test( NAME "cpp-p001-alternate"
          COMMAND "$<TARGET_FILE:cpp-p001-alternate>" )

set_tests_properties(
    "cpp-p001" "cpp-p001-alternate"
  PROPERTIES
    PASS_REGULAR_EXPRESSION "233168"
)
