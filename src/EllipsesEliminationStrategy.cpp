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
//    auto falloutIt = std::prev(population.cend(), fallout);
//    std::vector<EllipsesGenotype::Type> falloutGenotypes;
//    std::for_each(falloutIt, population.end(), [&](auto pair){
//        falloutGenotypes.push_back(pair.first);
//    });
//
//    long range = static_cast<long>(std::ceil(std::distance(population.cbegin(), population.cend()) / 2.0)); /* 2.0 as floating point to prevent cast */
//    auto begin = population.begin();
//    auto end = std::next(begin, range);
//    population.erase(begin, end);
//    population.insert(falloutGenotypes.begin(), falloutGenotypes.end());

    int currentPopulationSize = static_cast<int>(std::distance(population.cbegin(), population.cend()));
    int targetPopulationSize = currentPopulationSize / 2;
    std::vector<Population<EllipsesGenotype::Type>::ValueType> newGenotypes;
    for (int i = 0; i < targetPopulationSize; i++) {
        auto bestGenotype = std::next(population.begin(), (*prng)() % currentPopulationSize);
        for (int i = 0; i < tournamentSize; i++) {
            auto candidate = std::next(population.begin(), (*prng)() % currentPopulationSize);
            if (candidate->second > bestGenotype->second) {
                bestGenotype = candidate;
            }
        }
        newGenotypes.push_back(*bestGenotype);
    }
    population.erase(population.begin(), population.end());
    for (auto pair : newGenotypes) {
        population.insert(std::move(pair));
    }
}
