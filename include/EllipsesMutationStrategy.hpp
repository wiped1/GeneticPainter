//
// Created by Mckomo on 18.04.15.
//

#pragma once

#include <random>
#include "Ellipse.hpp"
#include "MutationStrategy.hpp"
#include "EllipseGenerator.hpp"

class EllipsesMutationStrategy : public MutationStrategy<Ellipse> {

private:

    const EllipseGenerator *_ellipseGenerator;

    void mutateGenotype(Genotype<Ellipse> &genotype) const;
    void mutateGene(Ellipse &ellipse) const;
    Size mutateSize(Size size) const;
    Scalar mutateColor(Scalar scalar) const;
    Point mutatePosition(Point point) const;

public:

    EllipsesMutationStrategy(const EllipseGenerator &ellipseGenerator);
    void mutate(Population<Ellipse>& population) const;

};
