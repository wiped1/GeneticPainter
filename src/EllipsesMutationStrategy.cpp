//
// Created by Mckomo on 18.04.15.
//

#include <iostream>
#include "EllipsesMutationStrategy.hpp"

EllipsesMutationStrategy::EllipsesMutationStrategy(std::mt19937 &prng) : _prng(&prng) {
    // NOTHING TO DO HERE
}

void EllipsesMutationStrategy::mutate(Population<Ellipse> &population) const
{
    std::for_each(population.getGenotypes().begin(), population.getGenotypes().end(), std::bind(&EllipsesMutationStrategy::mutateGenotype, this, std::placeholders::_1));
}

void EllipsesMutationStrategy::mutateGenotype(Genotype<Ellipse> &genotype) const
{
    unsigned int genesCount = genotype.getGenes().size();
    unsigned int mutataionExtent = genesCount * 0.1;

    for (int i = 0; i < mutataionExtent; i++)
    {
        mutateGene(genotype.getGenes().at(rand() % genesCount));
    }
}

void EllipsesMutationStrategy::mutateGene(Ellipse &gene) const
{
    gene.size = mutateSize(gene.size);
    gene.color = mutateColor(gene.color);
    gene.position = mutatePosition(gene.position);
}

Size EllipsesMutationStrategy::mutateSize(Size size) const {
    return cv::Size_<int>();
}

Scalar EllipsesMutationStrategy::mutateColor(Scalar scalar) const {
    return cv::Scalar_<double>();
}

Point EllipsesMutationStrategy::mutatePosition(Point point) const {
    return cv::Point_<int>();
}

