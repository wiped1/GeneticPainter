#pragma once

#include <opencv2/core/core.hpp>

using namespace cv;

struct Ellipse {

public:

    Point position;
    Size size;
    Scalar color;

    Ellipse(Point position, Size size, Scalar color);
//    Ellipse(const Ellipse& other);
    bool operator<(const Ellipse& other) const;
    bool operator==(const Ellipse& other) const;
};