#include "EllipsesSizeComparator.hpp"
#include "EllipsesCrossoverOperator.hpp"

using namespace gall;

EllipsesCrossoverOperator::EllipsesCrossoverOperator(std::mt19937 &prng) : prng(&prng)
{
    // DO NOTHING
}

EllipsesGenotype::Type EllipsesCrossoverOperator::cross(std::vector<EllipsesGenotype::Type> &parents) const
{
    long geneCount = std::distance(parents.front().cbegin(), parents.front().cend());
    EllipsesGenotype::Collection childGens;

    for (unsigned int i = 0; i < geneCount; i++)
    {
        auto donor = parents.at((*prng)() % PARENTS_PER_CHILD);
        auto gene = *std::next(donor.cbegin(), i);
        childGens.push_back(gene);
    }

    return EllipsesGenotype::Type(childGens);
}