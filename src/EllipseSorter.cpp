#include "EllipseSorter.hpp"

bool EllipseSorter::SortEllipseBySizeDesc::operator()(Ellipse *e1, Ellipse *e2) const {
    return e1->size.area() >= e2->size.area();
}