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

EllipsesMutationStrategy::EllipsesMutationStrategy(EllipseGenerator &ellipseGenerator,
       std::mt19937 &prng, unsigned int upperMutationLimit)
: ellipseGenerator(&ellipseGenerator), prng(&prng),
  mutationDistribution(new std::uniform_real_distribution<double>(0.0, 1.0)),
  mutations(prng), upperMutationLimit(upperMutationLimit)
{
    mutations.add(new AlterSizeFunctor(ellipseGenerator, prng), 15);
    mutations.add(new AlterPositionFunctor(ellipseGenerator, prng), 15);
    mutations.add(new AlterColorByRatioFunctor(prng), 16);
    mutations.add(new AlterAlphaByRatioFunctor(prng), 16);
//    mutations.add(new SwapWithRandomFunctor(ellipseGenerator),0.5);
    mutations.add(new AddNewEllipseFunctor(ellipseGenerator), 16);
    mutations.add(new CopyNewEllipseFunctor(ellipseGenerator, prng), 8);
    mutations.add<RemoveFromBackFunctor>(16);
    mutations.add<RemoveFromFrontFunctor>(16);
    mutations.add<RemoveHalfFunctor>(2);
    mutations.add(new RemoveRandomFunctor(prng),14);
}

void EllipsesMutationStrategy::mutate(EllipsesGenotype::Type &genotype) const
{
    std::uniform_int_distribution<unsigned int> numOfMutationsDist(1, upperMutationLimit);
    unsigned int numOfMutations = numOfMutationsDist(*prng);
    for (unsigned int i = 0; i < numOfMutations; i++)
    {
        mutations.draw().mutate(genotype.asCollection());
    }

    std::sort(genotype.asCollection().rbegin(), genotype.asCollection().rend(), EllipsesSizeComparator());
}
