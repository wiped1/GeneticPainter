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
public:
    void eliminate(Population<EllipsesGenotype::Type> &population);
};
