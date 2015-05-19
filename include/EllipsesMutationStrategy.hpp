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

using namespace gall;

class EllipsesMutationStrategy : public MutationOperator<EllipsesGenotype::Type>
{
private:
    std::mt19937 *prng;
    std::unique_ptr<std::uniform_real_distribution<double>> alterationDistribution;
    std::unique_ptr<std::uniform_real_distribution<double>> alterationRatio;
    EllipseGenerator* ellipseGenerator;
    void alterSize(Ellipse &ellipse) const;
    void alterColor(Ellipse &ellipse) const;
    void alterPosition(Ellipse &ellipse) const;
    void swapWithRandom(Ellipse *ellipse) const;
    double getRandomRatio() const;

public:
    EllipsesMutationStrategy(EllipseGenerator &ellipseGenerator, std::mt19937 &prng);
    void mutate(EllipsesGenotype::Type &population) const;
};
