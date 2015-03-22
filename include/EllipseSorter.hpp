#pragma once

#include "Ellipse.hpp"

class EllipseSorter {

public:

    struct SortEllipseBySizeDesc { bool operator()(Ellipse * e1, Ellipse * e2) const; };

};
