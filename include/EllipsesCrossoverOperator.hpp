#pragma once

#include <random>
#include "Ellipse.hpp"
#include "Genotype.hpp"
#include "CrossoverOperator.hpp"
#include "EllipsesBreedingOperator.hpp"

using namespace gall;

using EllipsesGenotype = Genotype<Ellipse, std::set>;

class EllipsesCrossoverOperator : public CrossoverOperator<EllipsesGenotype>
{
private:
    const unsigned int PARENTS_PER_CHILD = 5;
    std::mt19937 *prng;

public:
    EllipsesCrossoverOperator(std::mt19937 &prng);
    EllipsesGenotype cross(std::vector<EllipsesGenotype> &parents) const;
};