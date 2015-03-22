#pragma once

#include <random>
#include "Ellipse.hpp"
#include "GeneticAlgorithm.hpp"

class EllipsesCrossoverStrategy : CrossoverStrategy<Ellipse> {

    const unsigned int PARENTS_PER_CHILD = 5;

    std::mt19937 _prng;

private:

    Genotype<Ellipse> _breed(
            std::vector<Genotype<Ellipse>>& ellipseGenotypes,
            std::vector<unsigned int>& parentIndexes);

    void _fillWithRandomValues(
            std::vector<unsigned int>& vec,
            unsigned int maxValue,
            unsigned int times);

public:

    EllipsesCrossoverStrategy(std::mt19937 &prng);
    virtual void cross(Population<Ellipse> &population);

};