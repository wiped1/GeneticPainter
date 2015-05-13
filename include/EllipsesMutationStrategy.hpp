//
// Created by Mckomo on 18.04.15.
//

#pragma once

#include <random>
#include "Ellipse.hpp"
#include "MutationOperator.hpp"
#include "EllipseGenerator.hpp"
#include "EllipsesGenotype.hpp"

using namespace gall;

class EllipsesMutationStrategy : public MutationOperator<EllipsesGenotype::Type>
{
private:
    EllipseGenerator ellipseGenerator;

public:
    EllipsesMutationStrategy(EllipseGenerator &ellipseGenerator);
    void mutate(EllipsesGenotype::Type &population) const;
};
