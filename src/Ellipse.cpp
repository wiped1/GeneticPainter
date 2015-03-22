#include "Ellipse.hpp"

using namespace cv;

Ellipse::Ellipse(Point position, Size size, Scalar color)
        : position(position), size(size), color(color) {}