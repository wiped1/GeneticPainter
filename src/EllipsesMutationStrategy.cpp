//
// Created by Mckomo on 18.04.15.
//

#include <iostream>
#include <random>
#include <functional>
#include <EllipsesSizeComparator.hpp>
#include "EllipsesMutationStrategy.hpp"
#include "EllipsesGenotype.hpp"

using namespace gall;

EllipsesMutationStrategy::EllipsesMutationStrategy(EllipseGenerator &ellipseGenerator, std::mt19937 &prng)
        : ellipseGenerator(ellipseGenerator)
        , prng(&prng)
        , alterationDistribution(new std::uniform_real_distribution<double>(0.0, 1.0))
        , alterationRatio(new std::uniform_real_distribution<double>(0.95, 1.05))
{
    // Nothing to do
}

void EllipsesMutationStrategy::mutate(EllipsesGenotype::Type &genotype) const
{
    std::for_each(genotype.begin(), genotype.end(), [&](auto &ellipse)
    {
        double result = (*alterationDistribution)(*prng);

        if (result >= 0.5 && result < 0.6)
        {
            this->alterSize(ellipse);
            return;
        }
        if (result >= 0.6 && result < 0.7)
        {
            this->alterPosition(ellipse);
            return;
        }
        if (result >= 0.7 && result < 0.8)
        {
            this->alterColor(ellipse);
            return;
        }
        if (result >= 0.8 && result < 0.82)
        {
            this->swapWithRandom(&ellipse);
            return;
        }
    });

    std::sort(genotype.rbegin(), genotype.rend(), EllipsesSizeComparator());
}

void EllipsesMutationStrategy::alterSize(Ellipse &ellipse) const
{
    ellipse.size.height = std::min<unsigned int>(ellipse.size.height * getRandomRatio(), ellipseGenerator.getMaxDiameter());
    ellipse.size.width = std::min<unsigned int>(ellipse.size.width * getRandomRatio(), ellipseGenerator.getMaxDiameter());
}

void EllipsesMutationStrategy::alterColor(Ellipse &ellipse) const
{
    for (int i = 0; i < 2; ++i)
    {
        ellipse.color[i] = (int) (ellipse.color[i] * getRandomRatio()) % 256;
    }
}

void EllipsesMutationStrategy::alterPosition(Ellipse &ellipse) const
{
    ellipse.position.x = std::min<unsigned int>(ellipse.position.x * getRandomRatio(), ellipseGenerator.getPositionBound().width);
    ellipse.position.y = std::min<unsigned int>(ellipse.position.y * getRandomRatio(), ellipseGenerator.getPositionBound().height);
}

void EllipsesMutationStrategy::swapWithRandom(Ellipse *ellipse) const
{
    *ellipse = std::move(ellipseGenerator.generateRandom());
}

double EllipsesMutationStrategy::getRandomRatio() const {
    return (*alterationRatio)(*prng);
}
