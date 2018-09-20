#include "catch.hpp"
#include "block.hpp"

TEST_CASE("Testing block class") {
    Block block = Block(Vector2f(100, 100), Vector2f(100, 100), 9);
    
    SECTION("constructor") {
        INFO("Using Block") // Only appears on a FAIL
        CAPTURE(block.getShape().getFillColor()); // Displays this variable on a FAIL
        CHECK(block.getShape().getFillColor() == GREY);
    }
}
