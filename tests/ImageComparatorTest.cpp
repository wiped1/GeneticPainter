//
// Created by Maciej Komorowski on 23.05.15.
//

#include "Catch/catch.hpp"
#include "ImageComparator.hpp"

SCENARIO("ImageComparator compares two images", "[imageComparator]") {

    ImageComparator imageComparator;

    GIVEN("two images with oposite colors") {

        cv::Size size(200, 200);
        Mat blue(size, CV_8UC3, Scalar(90, 100, 100));
        Mat red(size, CV_8UC3, Scalar(0, 100, 100));

        WHEN("comparing them by pixels") {

            double result = imageComparator.compareByPixels(blue, red);

            THEN("It should return 0") {
                REQUIRE(result == 0);
            }
        }
    }

    GIVEN("same two images") {

        cv::Mat image = imread("../res/monet.png");
        cvtColor(image, image, COLOR_HSV2BGR);

        WHEN("comparing them by pixels") {

            double result = imageComparator.compareByPixels(image, image);

            THEN("It should return 1") {
                REQUIRE(result == 1);
            }
        }
    }

    GIVEN("two images with oposite colors and masking one with the half of the other") {

        cv::Size size(800, 800);
        cv::Mat blue(size, CV_8UC3, Scalar(90, 0, 0));
        cv::Mat halfRed(size, CV_8UC3, Scalar(90, 0, 0));
        cv::rectangle(halfRed, cv::Point(0, 0), cv::Point(size.width/2, size.height), cv::Scalar(0, 0, 0), -1);

        WHEN("comparing them by pixels") {

            double result = imageComparator.compareByPixels(blue, halfRed);

            THEN("It should return value around 0.5") {
                REQUIRE(result > 0.49);
                REQUIRE(result < 0.51);
            }
        }
    }

}
