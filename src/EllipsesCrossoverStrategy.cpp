#include <EllipsesSizeComperator.hpp>
#include "EllipsesCrossoverStrategy.hpp"


//using namespace std;

EllipsesCrossoverStrategy::EllipsesCrossoverStrategy(std::mt19937 &prng) : _prng(&prng)
{
    // do nothing
}

void EllipsesCrossoverStrategy::cross(Population<Ellipse> &population) const
{
    std::vector<unsigned int> parentIndices;
    unsigned long populationSize = population.getGenotypes().size();


    for (unsigned int i = 0; i < populationSize; i++)
    {
        populateWithRandom(parentIndices, (unsigned int) populationSize, PARENTS_PER_CHILD);
        population.getGenotypes().push_back(breed(population.getGenotypes(), parentIndices));
    }
}

void EllipsesCrossoverStrategy::populateWithRandom(
        std::vector<unsigned int> &vec,
        unsigned int maxValue,
        unsigned int times) const
{
    vec.clear();

    for (unsigned int i = 0; i < times; i++)
    {
        vec.push_back((*_prng)() % maxValue);
    }
}

Genotype<Ellipse> EllipsesCrossoverStrategy::breed(
        std::vector<Genotype<Ellipse>> &ellipsesGenotypes,
        std::vector<unsigned int> &parentIndexes) const
{
    unsigned long geneCount = ellipsesGenotypes.front().getGenes().size();
    std::vector<Ellipse> childGens;

    for (unsigned int i = 0; i < geneCount; i++)
    {
        childGens.push_back(ellipsesGenotypes.at((*_prng)() % PARENTS_PER_CHILD).getGenes().at(i));
    }

    return Genotype<Ellipse>(childGens);
}

