//
// Created by Mckomo on 18.04.15.
//

#pragma once

#include <random>
#include "Ellipse.hpp"
#include "MutationOperator.hpp"
#include "EllipseGenerator.hpp"

using namespace gall;
using EllipsesGenotype = Genotype<Ellipse, std::set>;

class EllipsesMutationStrategy : public MutationOperator<EllipsesGenotype>
{
private:
    EllipseGenerator ellipseGenerator;

public:
    EllipsesMutationStrategy(EllipseGenerator &ellipseGenerator);
    void mutate(EllipsesGenotype &population) const;
};
