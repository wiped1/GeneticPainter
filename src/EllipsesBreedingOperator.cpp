//
// Created by Maciej Komorowski on 09.05.15.
//

#include "EllipsesBreedingOperator.hpp"
#include "EllipsesGenotype.hpp"

using namespace gall;

EllipsesBreedingOperator::EllipsesBreedingOperator(std::mt19937 &prng) : prng(&prng) {
    // DO NOTHING
}

std::vector<EllipsesGenotype::Type> EllipsesBreedingOperator::breed(const Population<EllipsesGenotype::Type> &population) const
{
    std::vector<EllipsesGenotype::Type> parents;
    long populationSize = std::distance(population.cbegin(), population.cend());

    for (unsigned int i = 0; i < 5; i++)
    {
        long randomIndex = (*prng)() % populationSize;
        auto genotype = (*std::next(population.cbegin(), randomIndex)).first;
        parents.push_back(genotype);
    }

    return parents;
}

