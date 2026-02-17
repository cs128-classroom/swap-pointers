// clang-format off
/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////
//  Written By : <Your Name>                  Environment : ubuntu:bionic               //
//  Date ......: <00/00/00>                      Compiler ...: clang-10                    //
/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////
// clang-format on
/////////////////////////////////////////////////////////////////////////////////////////////
//                             Framework Set-up //
/////////////////////////////////////////////////////////////////////////////////////////////
#ifndef CATCH_CONFIG_MAIN
#  define CATCH_CONFIG_MAIN
#endif
#include "catch.hpp"
/////////////////////////////////////////////////////////////////////////////////////////////
//                                 Includes //
/////////////////////////////////////////////////////////////////////////////////////////////
#include <stdexcept>

#include "solution.hpp"

/////////////////////////////////////////////////////////////////////////////////////////////
//                             Helpers/Constants //
/////////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////////
//                                Test Cases //
/////////////////////////////////////////////////////////////////////////////////////////////

TEST_CASE("SwapPointers", "[swap_pointers]") {
  SECTION("Swapping ints returns true and swaps values") {
    int first = 3;
    int second = 9;

    bool result = SwapPointers(&first, &second, DataType::INT, DataType::INT);

    REQUIRE(result);
    REQUIRE(first == 9);
    REQUIRE(second == 3);
  }

  SECTION("Swapping strings returns true and swaps values") {
    std::string first = "left";
    std::string second = "right";

    bool result =
        SwapPointers(&first, &second, DataType::STRING, DataType::STRING);

    REQUIRE(result);
    REQUIRE(first == "right");
    REQUIRE(second == "left");
  }

  SECTION("Mismatched types returns false and values are unchanged") {
    int first = 5;
    std::string second = "five";
    int original_first = first;
    std::string original_second = second;

    bool result =
        SwapPointers(&first, &second, DataType::INT, DataType::STRING);

    REQUIRE_FALSE(result);
    REQUIRE(first == original_first);
    REQUIRE(second == original_second);
  }

  SECTION("Either nullptr throws std::invalid_argument") {
    int value = 10;
    std::string text = "ten";

    REQUIRE_THROWS_AS(
        SwapPointers(nullptr, &value, DataType::INT, DataType::INT),
        std::invalid_argument);
    REQUIRE_THROWS_AS(
        SwapPointers(&value, nullptr, DataType::INT, DataType::INT),
        std::invalid_argument);
    REQUIRE_THROWS_AS(
        SwapPointers(nullptr, &text, DataType::STRING, DataType::STRING),
        std::invalid_argument);
  }
}


/////////////////////////////////////////////////////////////////////////////////////////////
