//
// Created by Maciej Komorowski on 09.05.15.
//

#pragma once

#include <vector>
#include <random>
#include "Ellipse.hpp"
#include "Genotype.hpp"
#include "Population.hpp"
#include "BreedingOperator.hpp"

using namespace gall;
using EllipsesGenotype = Genotype<Ellipse, std::set>;

class EllipsesBreedingOperator : public BreedingOperator<EllipsesGenotype>
{

private:

    std::mt19937 *prng;

public:

    EllipsesBreedingOperator(std::mt19937 &prng);
    std::vector<EllipsesGenotype> breed(const Population<EllipsesGenotype> &population) const;

};

