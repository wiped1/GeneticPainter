//
// Created by Mckomo on 18.04.15.
//

#pragma once

#include <set>
#include "Ellipse.hpp"
#include "Genotype.hpp"
#include "Population.hpp"
#include "EliminationStrategy.hpp"
#include "EllipsesGenotype.hpp"

using namespace gall;

class EllipsesEliminationStrategy : public EliminationStrategy<EllipsesGenotype::Type>
{
private:
    /* number of unfit genotypes to be included in next generation */
    int fallout;
    std::mt19937* prng;
    int tournamentSize;
public:
    EllipsesEliminationStrategy(int fallout, std::mt19937& prng, int tournamentSize);
    void eliminate(Population<EllipsesGenotype::Type> &population);
};
