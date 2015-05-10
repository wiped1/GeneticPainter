#pragma once

#include <random>
#include "Ellipse.hpp"
#include "Genotype.hpp"
#include "CrossoverOperator.hpp"
#include "EllipsesBreedingOperator.hpp"
#include "EllipsesGenotype.hpp"

using namespace gall;

class EllipsesCrossoverOperator : public CrossoverOperator<EllipsesGenotype::Type>
{
private:
    const unsigned int PARENTS_PER_CHILD = 5;
    std::mt19937 *prng;

public:
    EllipsesCrossoverOperator(std::mt19937 &prng);
    EllipsesGenotype::Type cross(std::vector<EllipsesGenotype::Type> &parents) const;
};