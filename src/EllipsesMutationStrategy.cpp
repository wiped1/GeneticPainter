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

template <typename Distribution>
double getRandomRatio(Distribution& dist, std::mt19937& prng) {
    return dist(prng);
}

struct AlterSizeFunctor : public MutationFunctor<Ellipse> {
    const EllipseGenerator *ellipseGenerator;
    std::mt19937* prng;
    const std::unique_ptr<std::uniform_real_distribution<double>> alterationRatio;
    AlterSizeFunctor(const EllipseGenerator &ellipseGenerator, std::mt19937 &prng)
    : ellipseGenerator(&ellipseGenerator), prng(&prng), alterationRatio(
            new std::uniform_real_distribution<double>(0.95, 1.05)) {
        // do nothing
    }
    virtual void operator()(Ellipse& ellipse) const {
        ellipse.size.height = std::min<int>(static_cast<int>(static_cast<double>(ellipse.size.height)
                * getRandomRatio(*alterationRatio, *prng)), ellipseGenerator->getMaxDiameter());
        ellipse.size.width = std::min<int>(static_cast<int>(static_cast<double>(ellipse.size.width)
                * getRandomRatio(*alterationRatio, *prng)), ellipseGenerator->getMaxDiameter());
    }
};

struct AlterColorFunctor : public MutationFunctor<Ellipse> {
    std::mt19937* prng;
    const std::unique_ptr<std::uniform_real_distribution<double>> alterationRatio;
    AlterColorFunctor(std::mt19937& prng) : prng(&prng),
            alterationRatio(new std::uniform_real_distribution<double>(0.95, 1.05)) {
        // do nothing
    }
    virtual void operator()(Ellipse& ellipse) const {
        ellipse.color[0] = (int) (ellipse.color[0] * getRandomRatio(*alterationRatio, *prng)) % 256;
        ellipse.color[1] = (int) (ellipse.color[1] * getRandomRatio(*alterationRatio, *prng)) % 256;
        ellipse.color[2] = (int) (ellipse.color[2] * getRandomRatio(*alterationRatio, *prng)) % 256;
    }
};

struct AlterPositionFunctor : public MutationFunctor<Ellipse> {
    const EllipseGenerator *ellipseGenerator;
    std::mt19937* prng;
    const std::unique_ptr<std::uniform_real_distribution<double>> alterationRatio;
    AlterPositionFunctor(const EllipseGenerator &ellipseGenerator, std::mt19937 &prng)
    : ellipseGenerator(&ellipseGenerator), prng(&prng), alterationRatio(
            new std::uniform_real_distribution<double>(0.95, 1.05)) {
        // do nothing
    }
    virtual void operator()(Ellipse& ellipse) const {
        ellipse.position.x = std::min<int>(static_cast<int>(static_cast<double>(ellipse.position.x)
                * getRandomRatio(*alterationRatio, *prng)), ellipseGenerator->getPositionBound().width);
        ellipse.position.y = std::min<int>(static_cast<int>(static_cast<double>(ellipse.position.y)
                * getRandomRatio(*alterationRatio, *prng)), ellipseGenerator->getPositionBound().height);
    }
};

struct SwapWithRandomFunctor : MutationFunctor<Ellipse> {
    const EllipseGenerator *ellipseGenerator;
    SwapWithRandomFunctor(const EllipseGenerator &ellipseGenerator)
    : ellipseGenerator(&ellipseGenerator) {
        // do nothing
    }
    virtual void operator()(Ellipse& ellipse) const {
        ellipse = std::move(ellipseGenerator->generateRandom());
    }
};

EllipsesMutationStrategy::EllipsesMutationStrategy(EllipseGenerator &ellipseGenerator, std::mt19937 &prng)
        : ellipseGenerator(&ellipseGenerator)
        , prng(&prng)
        , alterationDistribution(new std::uniform_real_distribution<double>(0.0, 1.0))
        , alterationRatio(new std::uniform_real_distribution<double>(0.95, 1.05))
        , dist(prng)
{
    dist.add(new AlterSizeFunctor(ellipseGenerator, prng), 0.1);
    dist.add(new AlterColorFunctor(prng), 0.1);
    dist.add(new AlterPositionFunctor(ellipseGenerator, prng), 0.1);
    dist.add(new SwapWithRandomFunctor(ellipseGenerator), 0.02);
}

void EllipsesMutationStrategy::mutate(EllipsesGenotype::Type &genotype) const
{
    std::for_each(genotype.begin(), genotype.end(), [&](auto &ellipse)
    {
        double result = (*alterationDistribution)(*prng);
        if (result >= 0.5) {
            // mutate
            dist.draw()(ellipse);
        }
    });

    std::sort(genotype.rbegin(), genotype.rend(), EllipsesSizeComparator());
}
