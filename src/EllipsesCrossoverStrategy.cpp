#include "EllipsesCrossoverStrategy.hpp"


//using namespace std;

EllipsesCrossoverStrategy::EllipsesCrossoverStrategy(std::mt19937 &prng) : _prng(prng)
{
    // do nothing
}

void EllipsesCrossoverStrategy::cross(Population<Ellipse> &population)
{
//    std::cout << 1;

//    auto ellipseGenotypes = population.getGenotypes();
    std::vector<unsigned int> parentIndexes;
    unsigned long populationSize = population.getGenotypes().size();

//    std::cout << ellipseGenotypes.size() << std::endl;

    for (unsigned int i = 0; i < populationSize; i++)
    {
//        std::cout << i << std::endl;
        _fillWithRandomValues(parentIndexes, (unsigned  int) populationSize, PARENTS_PER_CHILD);
        population.getGenotypes().push_back(_breed(population.getGenotypes(), parentIndexes));
    }
}

void EllipsesCrossoverStrategy::_fillWithRandomValues(
        std::vector<unsigned int>& vec,
        unsigned int maxValue,
        unsigned int times)
{
    vec.clear();

    for (unsigned int i = 0; i < times; i++)
    {
        vec.push_back(_prng() % maxValue);
    }
}

Genotype<Ellipse> EllipsesCrossoverStrategy::_breed(
        std::vector<Genotype<Ellipse>>& ellipseGenotypes,
        std::vector<unsigned int>& parentIndexes)
{
    unsigned long geneCount = ellipseGenotypes.front().getGenes().size();
    std::vector<Ellipse> childGens;

    for (unsigned int i = 0; i < geneCount; i++)
    {
        childGens.push_back(ellipseGenotypes.at(_prng() % PARENTS_PER_CHILD).getGenes().at(i));
    }

    return Genotype<Ellipse>(childGens);
}

