#include <iostream>
#include "EllipsesSizeComparator.hpp"

bool EllipsesSizeComparator::operator()(const Ellipse& lhs, const Ellipse& rhs) const
{
    return lhs.size.area() < rhs.size.area();
}