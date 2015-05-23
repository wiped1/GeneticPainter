#include "Catch/catch.hpp"

#include "Ellipse.hpp"

SCENARIO("Ellipse contains data about diameter and color", "[ellipse]") {
    GIVEN("A pseudorandom engine") {
        WHEN("An Ellipse is initialized with position, size and color") {

            cv::Point position(300, 200);
            cv::Size  size(600, 400);
            cv::Scalar color(255, 0, 0);

            Ellipse ellipse(position, size, color);

            THEN("It has supplied position") {
                REQUIRE(ellipse.position == position);
            }
            THEN("It has supplied size") {
                REQUIRE(ellipse.size == size);
            }
            THEN("It has supplied color") {
                REQUIRE(ellipse.color == color);
            }
        }
    }
}
