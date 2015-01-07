#pragma once

#include <opencv2/core/core.hpp>

using namespace cv;

struct Ellipse {

    Point position;
    Size size;
    Scalar color;

public:
    Ellipse(Point position, Size size, Scalar color);

};