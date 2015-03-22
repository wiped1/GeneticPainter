#pragma once

#include <opencv2/core/core.hpp>

using namespace cv;

struct Ellipse {

public:

    Point position;
    Size size;
    Scalar color;

    Ellipse() = default;

    Ellipse(Point position, Size size, Scalar color);

};