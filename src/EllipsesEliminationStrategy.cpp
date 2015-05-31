//
// Created by Mckomo on 18.04.15.
//

#include "EllipsesEliminationStrategy.hpp"
#include "EllipsesGenotype.hpp"

using namespace gall;

EllipsesEliminationStrategy::EllipsesEliminationStrategy(int fallout, std::mt19937& prng, int tournamentSize)
        : fallout(fallout), prng(&prng), tournamentSize(tournamentSize) {
    // do nothing
}

void EllipsesEliminationStrategy::eliminate(Population<EllipsesGenotype::Type> &population)
{
    long range = static_cast<long>(std::ceil(population.asCollection().size()) / 2.0); /* 2.0 as floating point to prevent cast */
    auto begin = population.asCollection().begin();
    auto end = std::next(begin, range);
    population.asCollection().erase(begin, end);

    int currentPopulationSize = static_cast<int>(population.asCollection().size());
    int targetPopulationSize = currentPopulationSize / 2;
    std::vector<Population<EllipsesGenotype::Type>::ValueType> newGenotypes;
    for (int i = 0; i < targetPopulationSize; i++) {
       auto bestGenotype = std::next(population.asCollection().begin(), (*prng)() % currentPopulationSize);
       for (int j = 0; j < tournamentSize; j++) {
               auto candidate = std::next(population.asCollection().begin(), (*prng)() % currentPopulationSize);
               if (candidate->second > bestGenotype->second) {
                       bestGenotype = candidate;
               }
       }
       newGenotypes.push_back(*bestGenotype);
    }
    population.asCollection().erase(
            population.asCollection().begin(), population.asCollection().end());
    for (auto pair : newGenotypes) {
            population.asCollection().insert(std::move(pair));
    }
}