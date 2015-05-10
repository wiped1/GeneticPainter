//
// Created by Mckomo on 18.04.15.
//

#include "EllipsesEliminationStrategy.hpp"
#include "EllipsesGenotype.hpp"

using namespace gall;

void EllipsesEliminationStrategy::eliminate(Population<EllipsesGenotype::Type> &population)
{
    long range = static_cast<long>(std::ceil(std::distance(population.cbegin(), population.cend()) / 2.0)); /* 2.0 as floating point to prevent cast */
    auto begin = population.begin();
    auto end = std::next(begin, range);
    population.erase(begin, end);
}