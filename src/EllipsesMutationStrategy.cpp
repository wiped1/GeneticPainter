//
// Created by Mckomo on 18.04.15.
//

#include <iostream>
#include <random>
#include <functional>
#include <EllipsesSizeComparator.hpp>
#include <EvolvingEnvironment.hpp>
#include "EllipsesMutationStrategy.hpp"
#include "EllipsesGenotype.hpp"
#include "EllipsesMutationFunctors.hpp"
#include "MutationProbabilityDistribution.hpp"

using namespace gall;

EllipsesMutationStrategy::EllipsesMutationStrategy(EllipseGenerator &ellipseGenerator, std::mt19937 &prng)
        : ellipseGenerator(&ellipseGenerator)
        , prng(&prng)
        , mutationDistribution(new std::uniform_real_distribution<double>(0.0, 1.0))
        , dist(prng)
{
    dist.add(new AlterSizeFunctor(ellipseGenerator, prng),10);
    dist.add(new AlterPositionFunctor(ellipseGenerator, prng),10);
    dist.add(new AlterColorByRatioFunctor(prng),10);
    dist.add(new AlterColorBySumFunctor(prng),10);
    dist.add(new SwapWithRandomFunctor(ellipseGenerator),0.5);
    dist.add(new AddNewEllipseFunctor(ellipseGenerator),6);
    dist.add(new CopyNewEllipseFunctor(ellipseGenerator, prng), 3);
    dist.add<RemoveFromBackFunctor>(3);
    dist.add<RemoveFromFrontFunctor>(3);
    dist.add(new RemoveRandomFunctor(prng),1);
}

void EllipsesMutationStrategy::mutate(EllipsesGenotype::Type &genotype) const
{
    std::for_each(genotype.begin(), genotype.end(), [&](auto &ellipse)
    {
        double result = (*mutationDistribution)(*prng);

        if (result >= 0.5)
        {
            dist.draw()(genotype.collection(), ellipse); // mutate
        }
    });

    std::sort(genotype.rbegin(), genotype.rend(), EllipsesSizeComparator());
}
