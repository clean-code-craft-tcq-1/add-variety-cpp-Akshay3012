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


TEST_CASE("checks the temperature breach for passive cooling") {
  REQUIRE(classifyTemperatureBreach(PASSIVE_COOLING, -10.0) == TOO_LOW);
  REQUIRE(classifyTemperatureBreach(PASSIVE_COOLING, 45) == TOO_HIGH);
  REQUIRE(classifyTemperatureBreach(PASSIVE_COOLING, 25) == NORMAL);
  REQUIRE(classifyTemperatureBreach(HI_ACTIVE_COOLING, -5.0) == TOO_LOW);
  REQUIRE(classifyTemperatureBreach(HI_ACTIVE_COOLING, 55) == TOO_HIGH);
  REQUIRE(classifyTemperatureBreach(HI_ACTIVE_COOLING, 30) == NORMAL);
  REQUIRE(classifyTemperatureBreach(MED_ACTIVE_COOLING, -20.0) == TOO_LOW);
  REQUIRE(classifyTemperatureBreach(MED_ACTIVE_COOLING, 60) == TOO_HIGH);
  REQUIRE(classifyTemperatureBreach(MED_ACTIVE_COOLING, 20) == NORMAL);
}

