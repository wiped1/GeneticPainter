#pragma once

#include <random>
#include "Ellipse.hpp"
#include "GeneticAlgorithm.hpp"

class EllipsesCrossoverStrategy : public CrossoverStrategy<Ellipse> {

    const unsigned int PARENTS_PER_CHILD = 5;

    std::mt19937 *prng;

private:

    Genotype<Ellipse> breed(
            std::vector<Genotype<Ellipse>> &ellipseGenotypes,
            std::vector<unsigned int> &parentIndexes) const;

    void populateWithRandom(
            std::vector<unsigned int> &vec,
            unsigned int maxValue,
            unsigned int times) const;

public:

    EllipsesCrossoverStrategy(std::mt19937 &prng);
    void cross(Population<Ellipse> &population) const;

};