#include <iostream>
#include "EllipsesSizeComperator.hpp"
#include <opencv2/core/core.hpp>


bool EllipsesSizeComperator::operator()(const Ellipse& lhs, const Ellipse& rhs) const {
    return lhs.position.x * lhs.position.y > rhs.position.x * rhs.position.y;
}