#include "Ellipse.hpp"

using namespace cv;

Ellipse::Ellipse(Point position, Size size, Scalar color)
        : position(position), size(size), color(color) {}

bool Ellipse::operator==(const Ellipse &rhs) const {
    return size == rhs.size && position == rhs.position && color == rhs.color;
}
bool Ellipse::operator<(const Ellipse &rhs) const {
        return size.area() > rhs.size.area();
}

Ellipse::Ellipse(const Ellipse &other) {
    position = other.position;
    size = other.size;
    color = other.color;
}
