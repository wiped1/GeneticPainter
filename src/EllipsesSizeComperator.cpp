#include <iostream>
#include "EllipsesSizeComperator.hpp"

bool EllipsesSizeComperator::operator()(const Ellipse& lhs, const Ellipse& rhs)  {
    return lhs.size.area() >= rhs.size.area();
}