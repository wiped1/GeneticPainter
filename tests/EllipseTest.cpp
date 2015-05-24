#include "Catch/catch.hpp"

#include "Ellipse.hpp"

SCENARIO("Ellipse contains data about diameter and color", "[ellipse]") {

    WHEN("an Ellipse is initialized with position, size and color") {

        cv::Point position(300, 200);
        cv::Size  size(600, 400);
        cv::Scalar color(255, 0, 0, 1.0);

        Ellipse ellipse(position, size, color);

        THEN("it store supplied position") {
            REQUIRE(ellipse.position == position);
        }
        THEN("it store supplied size") {
            REQUIRE(ellipse.size == size);
        }
        THEN("it store supplied color") {
            REQUIRE(ellipse.color == color);
        }
    }
}
