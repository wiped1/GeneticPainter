//
// Created by Mckomo on 18.04.15.
//

#include "EllipsesEliminationStrategy.hpp"
#include "EllipsesGenotype.hpp"

using namespace gall;

void EllipsesEliminationStrategy::eliminate(Population<EllipsesGenotype::Type> &population)
{
    long range = static_cast<long>(std::ceil(population.asCollection().size()) / 2.0); /* 2.0 as floating point to prevent cast */
    auto begin = population.asCollection().begin();
    auto end = std::next(begin, range);
    population.asCollection().erase(begin, end);
}