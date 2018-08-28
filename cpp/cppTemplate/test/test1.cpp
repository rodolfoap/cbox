#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "factorial.h"

Factorial factorial;
TEST_CASE("Factorial tests", "[factorial]") {
   REQUIRE(factorial.get(1) == 1);
   REQUIRE(factorial.get(4) == 24);
}
