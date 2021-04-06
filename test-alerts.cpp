#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "typewise-alert.h"

TEST_CASE("infers the breach according to lower limits") {
  REQUIRE(inferBreach(12, 20, 30) == TOO_LOW);
}

TEST_CASE("infers the breach according to upper limits") {
  REQUIRE(inferBreach(42, 20, 30) == TOO_HIGH);
}

TEST_CASE("doesn't infers the breach according to limits") {
  REQUIRE(inferBreach(22, 20, 30) == NORMAL);
}
