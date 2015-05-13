#pragma once

#include <vector>
#include "Ellipse.hpp"
#include "Genotype.hpp"

using namespace gall;

struct EllipsesGenotype {
    using Collection = std::vector<Ellipse>;
    using Type = Genotype<Collection>;
};

