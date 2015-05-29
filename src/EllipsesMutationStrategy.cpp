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
    /* transformation 40 */
    dist.add(new AlterSizeFunctor(ellipseGenerator, prng),15);
//    dist.add(new MakeSmallerFunctor(ellipseGenerator, prng), 10);
//    dist.add(new MakeBiggerFunctor(ellipseGenerator, prng), 10);
    dist.add(new AlterPositionFunctor(ellipseGenerator, prng), 15);

    /* alter color 39*/
    dist.add(new AlterColorByRatioFunctor(prng), 16);
//    dist.add(new AlterColorBySumFunctor(prng), 13);
    dist.add(new AlterAlphaByRatioFunctor(prng), 16);

//    dist.add(new SwapWithRandomFunctor(ellipseGenerator),0.1);
    /* addition 32 */
    dist.add(new AddNewEllipseFunctor(ellipseGenerator), 16);
    dist.add(new CopyNewEllipseFunctor(ellipseGenerator, prng), 15);

    /* deletion 13.5 */
    dist.add<RemoveFromBackFunctor>(16);
    dist.add<RemoveFromFrontFunctor>(16);
    dist.add<RemoveHalfFunctor>(2);
    dist.add(new RemoveRandomFunctor(prng), 14);

//    dist.add(new SwapRandomEllipsesFunctor(prng), 10);
}

void EllipsesMutationStrategy::mutate(EllipsesGenotype::Type &genotype) const
{
    /* preprocessor refactoring */
    #define mutations dist
    std::uniform_int_distribution<int> distr(1, 4);
    int mutationsCount = static_cast<int>(distr(*prng));
    for (int i = 0; i < mutationsCount; i++) {
        if (std::distance(genotype.cbegin(), genotype.cend()) > 0) {
            auto ellipse = genotype.collection().at(((*prng)() % std::distance(genotype.cbegin(), genotype.cend())));

            mutations.draw()(genotype.collection(), ellipse); // mutate
        }
    }
//    for(Ellipse& ellipse : genotype) {
//        double roll = (*mutationDistribution)(*prng);
//
//        if (roll <= 0.01)
//        {
//            dist.draw()(genotype.collection(), ellipse); // mutate
//        }
//    }

    //std::sort(genotype.rbegin(), genotype.rend(), EllipsesSizeComparator());
}
