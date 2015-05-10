//
// Created by Mckomo on 18.04.15.
//

#include <iostream>
#include <functional>
#include "EllipsesMutationStrategy.hpp"
#include "EllipsesGenotype.hpp"

using namespace gall;

EllipsesMutationStrategy::EllipsesMutationStrategy(EllipseGenerator &ellipseGenerator) : ellipseGenerator(ellipseGenerator) {
    // NOTHING TO DO HERE
}

void EllipsesMutationStrategy::mutate(EllipsesGenotype::Type &genotype) const
{
    long genesCount = std::distance(genotype.begin(), genotype.end());
    long mutationRange = static_cast<long>(genesCount * 0.01);

    for (int i = 0; i < 2; i++)
    {
        long randomIndex = rand() % genesCount;
        *std::next(genotype.begin(), randomIndex) = ellipseGenerator.generateRandom();
    }
}


