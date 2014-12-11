#include <Population.hpp>
#include "PopulationCreator.hpp"

PopulationCreator &PopulationCreator::instance() {
    static PopulationCreator instance;
    return instance;
}

template <typename T>
Population<T> PopulationCreator::create(unsigned int populationSize, const GenotypeCreator<T> &genotypeCreator) {
    std::vector<T> genotypes;
    for ( int i = 0; i < populationSize; i++ ) {
        genotypes.push_back(genotypeCreator.create());
    }
    return Population<T>(genotypes);
}
