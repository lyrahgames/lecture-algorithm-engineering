#include <catch/catch.hpp>

#include <fibonacci.h>

TEST_CASE("Fibonacci-sequence is computed", "[fibonacci]") {
  REQUIRE(fibonacci(0) == 0);
  REQUIRE(fibonacci(1) == 1);
  REQUIRE(fibonacci(2) == 1);
  REQUIRE(fibonacci(3) == 2);
  REQUIRE(fibonacci(4) == 3);
  REQUIRE(fibonacci(5) == 5);
  REQUIRE(fibonacci(6) == 8);
  REQUIRE(fibonacci(7) == 13);
  REQUIRE(fibonacci(8) == 21);
  REQUIRE(fibonacci(9) == 34);
  REQUIRE(fibonacci(10) == 55);
  REQUIRE(fibonacci(11) == 89);
}