#include "EllipsesCrossoverOperator.hpp"

using namespace gall;

EllipsesCrossoverOperator::EllipsesCrossoverOperator(std::mt19937 &prng)
    : prng(&prng)
    , rd(new std::uniform_real_distribution<float>(0.0, 1.0))
{
    // DO NOTHING
}

EllipsesGenotype::Type EllipsesCrossoverOperator::cross(std::vector<EllipsesGenotype::Type> &parents) const
{
    EllipsesGenotype::Collection childGens;
    unsigned long donerIndex = 0;
    long geneCount = std::distance((parents.at(donerIndex)).begin(), (parents.at(donerIndex)).end());
    double crossingProbability = geneCount / 400;

    for (unsigned int i = 0; i < geneCount; i++)
    {
        if ((*rd)(*prng) < crossingProbability)
            donerIndex = (donerIndex + 1) % 2;

        auto &donor = parents.at(donerIndex);
        auto gene = *std::next(donor.cbegin(), i % std::distance(donor.cbegin(), donor.cend()));
        childGens.push_back(gene);
    }

    return EllipsesGenotype::Type(childGens);
}