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
#include "EllipsesGenotype.hpp"

using namespace gall;

class EllipsesBreedingOperator : public BreedingOperator<EllipsesGenotype::Type>
{

private:

    std::mt19937 *prng;

public:

    EllipsesBreedingOperator(std::mt19937 &prng);
    std::vector<EllipsesGenotype::Type> breed(const Population<EllipsesGenotype::Type> &population) const;

};

