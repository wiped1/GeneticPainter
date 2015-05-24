#pragma once

#include "Ellipse.hpp"

struct EllipsesSizeComparator
{
    bool operator()(const Ellipse &lhs, const Ellipse &rhs) const;
};

