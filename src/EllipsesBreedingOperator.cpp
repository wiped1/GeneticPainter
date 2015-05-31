//
// Created by Maciej Komorowski on 09.05.15.
//

#include "EllipsesBreedingOperator.hpp"
#include "EllipsesGenotype.hpp"
#include "EvolvingEnvironment.hpp"

using namespace gall;

EllipsesBreedingOperator::EllipsesBreedingOperator(std::mt19937 &prng) : prng(&prng) {
    // DO NOTHING
}

std::vector<EllipsesGenotype::Type> EllipsesBreedingOperator::breed(const Population<EllipsesGenotype::Type> &population) const
{
    std::vector<EllipsesGenotype::Type> parents;
    long populationSize = population.asCollection().size();
    for (unsigned int i = 0; i < EvolvingEnvironmentProvider::getInstance().parentsPerChild; i++)
    {
        /* populationSize - 1 to prevent randomIndex reaching end iterator */
        long randomIndex = (*prng)() % (populationSize - 1);
        auto genotype = (*std::next(population.asCollection().cbegin(), randomIndex)).first;
        parents.push_back(genotype);
    }

    return parents;
}

