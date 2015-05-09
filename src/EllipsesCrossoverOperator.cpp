#include <EllipsesSizeComperator.hpp>
#include "EllipsesCrossoverOperator.hpp"

using namespace gall;
using EllipsesGenotype = Genotype<Ellipse, std::set>;

EllipsesCrossoverOperator::EllipsesCrossoverOperator(std::mt19937 &prng) : prng(&prng)
{
    // DO NOTHING
}

EllipsesGenotype EllipsesCrossoverOperator::cross(std::vector<EllipsesGenotype> &parents) const
{
    long geneCount = std::distance(parents.front().cbegin(), parents.front().cend());
    std::vector<Ellipse> childGens;

    for (unsigned int i = 0; i < geneCount; i++)
    {
        EllipsesGenotype donor = parents.at((*prng)() % PARENTS_PER_CHILD);
        auto gene = *std::next(donor.cbegin(), i);
        childGens.push_back(gene);
    }

    return EllipsesGenotype(childGens);
}