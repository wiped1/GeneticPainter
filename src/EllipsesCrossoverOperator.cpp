#include "EllipsesSizeComparator.hpp"
#include "EllipsesCrossoverOperator.hpp"
#include "EvolvingEnvironment.hpp"

using namespace gall;

EllipsesCrossoverOperator::EllipsesCrossoverOperator(std::mt19937 &prng) : prng(&prng)
{
    // DO NOTHING
}

EllipsesGenotype::Type EllipsesCrossoverOperator::cross(std::vector<EllipsesGenotype::Type> &parents) const
{
    EllipsesGenotype::Collection childGens;

    for (unsigned int i = 0; i < EvolvingEnvironmentProvider::getInstance().genesCount; i++)
    {
        auto donor = parents.at((*prng)() % EvolvingEnvironmentProvider::getInstance().parentsPerChild);
        auto gene = *std::next(donor.cbegin(), i);
        childGens.push_back(gene);
    }

    return EllipsesGenotype::Type(childGens);
}