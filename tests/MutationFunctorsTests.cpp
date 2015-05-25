#include "Catch/catch.hpp"

#include "EllipsesMutationFunctors.hpp"

SCENARIO("MutatorFunctors are used in MutationStrategy for Ellipse mutation")
{
    GIVEN("An SwapRandomEllipsesFunctor")
    {
        std::mt19937 prng;
        SwapRandomEllipsesFunctor f(prng);

        WHEN("Vector with one ellipse is given")
        {
            cv::Point pos(0, 0);
            cv::Size size(0, 0);
            cv::Scalar color(0);
            std::vector<Ellipse> vec {Ellipse(pos, size, color)};

            THEN("Swap does not occur ") {
                f(vec, *vec.begin());
                REQUIRE(vec.begin()->position == pos);
                REQUIRE(vec.begin()->size == size);
                REQUIRE(vec.begin()->color == color);
            }
        }

        WHEN("Vector with two ellipses is given") {

        }
    }
}