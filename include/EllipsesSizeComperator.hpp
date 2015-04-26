#pragma once

#include "Ellipse.hpp"

struct EllipsesSizeComperator {
    bool operator()(const Ellipse& lhs, const Ellipse& rhs);
};

