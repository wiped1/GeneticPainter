//
// Created by Mckomo on 18.04.15.
//

#pragma once

#include <set>
#include "Ellipse.hpp"
#include "Genotype.hpp"
#include "Population.hpp"
#include "EliminationStrategy.hpp"

using namespace gall;
using EllipsesGenotype = Genotype<Ellipse, std::set>;

class EllipsesEliminationStrategy : public EliminationStrategy<EllipsesGenotype>
{
private:
public:
    void eliminate(Population<EllipsesGenotype> &population);
};
