//
// Created by Mckomo on 18.04.15.
//

#pragma once

#include <random>
#include "Ellipse.hpp"
#include "MutationStrategy.hpp"

class EllipsesMutationStrategy : public MutationStrategy<Ellipse> {

private:

    std::mt19937 *_prng;

    void mutateGenotype(Genotype<Ellipse> &genotype) const;
    void mutateGene(Ellipse &ellipse) const;
    Size mutateSize(Size size) const;
    Scalar mutateColor(Scalar scalar) const;
    Point mutatePosition(Point point) const;

public:

    EllipsesMutationStrategy(std::mt19937 &prng);
    void mutate(Population<Ellipse>& population) const;

};
