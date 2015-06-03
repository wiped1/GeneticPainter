//
// Created by Mckomo on 18.04.15.
//

#pragma once

#include <random>
#include <memory>
#include "Ellipse.hpp"
#include "MutationOperator.hpp"
#include "EllipseGenerator.hpp"
#include "EllipsesGenotype.hpp"
#include "MutationProbabilityDistribution.hpp"

using namespace gall;

class EllipsesMutationStrategy : public MutationOperator<EllipsesGenotype::Type>
{
private:
    std::mt19937 *prng;
    std::unique_ptr<std::uniform_real_distribution<double>> mutationDistribution;
    EllipseGenerator* ellipseGenerator;
    MutationProbabilityDistribution<EllipsesGenotype::Collection, std::mt19937> mutations;
    unsigned int upperMutationLimit;

public:
    EllipsesMutationStrategy(EllipseGenerator &ellipseGenerator, std::mt19937 &prng,
            unsigned int upperMutationLimit);
    void mutate(EllipsesGenotype::Type &population) const;
};
