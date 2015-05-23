//
// Created by Mckomo on 18.04.15.
//

#include <iostream>
#include <random>
#include <functional>
#include <EllipsesSizeComparator.hpp>
#include "EllipsesMutationStrategy.hpp"
#include "EllipsesGenotype.hpp"
#include "MutationFunctor.hpp"
#include "MutationProbabilityDistribution.hpp"

using namespace gall;

struct AlterSizeFunctor;
struct AlterPositionFunctor;
struct AlterColorFunctor;
struct SwapWithRandomFunctor;

EllipsesMutationStrategy::EllipsesMutationStrategy(EllipseGenerator &ellipseGenerator, std::mt19937 &prng)
        : ellipseGenerator(&ellipseGenerator)
        , prng(&prng)
        , alterationDistribution(new std::uniform_real_distribution<double>(0.0, 1.0))
        , alterationRatio(new std::uniform_real_distribution<double>(0.95, 1.05))
        , dist(prng)
{
    dist.add<AlterColorFunctor>(0.1);
    dist.add<AlterPositionFunctor>(0.1);
    dist.add<AlterColorFunctor>(0.1);
    dist.add<SwapWithRandomFunctor>(0.02);
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

struct AlterSizeFunctor : public MutationFunctor<Ellipse> {
    virtual void operator()(Ellipse& ellipse) const {
        ellipse.size.height = std::min<unsigned int>(ellipse.size.height * getRandomRatio(), ellipseGenerator->getMaxDiameter());
        ellipse.size.width = std::min<unsigned int>(ellipse.size.width * getRandomRatio(), ellipseGenerator->getMaxDiameter());
    }
};

//void EllipsesMutationStrategy::alterSize(Ellipse &ellipse) const
//{
//    ellipse.size.height = std::min<unsigned int>(ellipse.size.height * getRandomRatio(), ellipseGenerator->getMaxDiameter());
//    ellipse.size.width = std::min<unsigned int>(ellipse.size.width * getRandomRatio(), ellipseGenerator->getMaxDiameter());
//}
//
//void EllipsesMutationStrategy::alterColor(Ellipse &ellipse) const
//{
//    ellipse.color[0] = (int) (ellipse.color[0] * getRandomRatio()) % 256;
//    ellipse.color[1] = (int) (ellipse.color[1] * getRandomRatio()) % 256;
//    ellipse.color[2] = (int) (ellipse.color[2] * getRandomRatio()) % 256;
//}
//
//void EllipsesMutationStrategy::alterPosition(Ellipse &ellipse) const
//{
//    ellipse.position.x = std::min<unsigned int>(ellipse.position.x * getRandomRatio(), ellipseGenerator->getPositionBound().width);
//    ellipse.position.y = std::min<unsigned int>(ellipse.position.y * getRandomRatio(), ellipseGenerator->getPositionBound().height);
//}
//
//void EllipsesMutationStrategy::swapWithRandom(Ellipse *ellipse) const
//{
//    *ellipse = std::move(ellipseGenerator->generateRandom());
//}
//
//double EllipsesMutationStrategy::getRandomRatio() const {
//    return (*alterationRatio)(*prng);
//}
