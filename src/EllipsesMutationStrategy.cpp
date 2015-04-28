//
// Created by Mckomo on 18.04.15.
//

#include <iostream>
#include "EllipsesMutationStrategy.hpp"

EllipsesMutationStrategy::EllipsesMutationStrategy(const EllipseGenerator &ellipseGenerator) : _ellipseGenerator(&ellipseGenerator) {
    // NOTHING TO DO HERE
}

void EllipsesMutationStrategy::mutate(Population<Ellipse> &population) const
{
    std::for_each(population.getGenotypes().begin(), population.getGenotypes().end(), std::bind(&EllipsesMutationStrategy::mutateGenotype, this, std::placeholders::_1));
}

void EllipsesMutationStrategy::mutateGenotype(Genotype<Ellipse> &genotype) const
{
    unsigned int genesCount = genotype.getGenes().size();
    unsigned int mutataionExtent = genesCount * 0.01;

    for (int i = 0; i < mutataionExtent; i++)
    {
        auto radnomIndex = rand() % genesCount;
        genotype.getGenes()[radnomIndex] = _ellipseGenerator->generateRandom();
    }
}


