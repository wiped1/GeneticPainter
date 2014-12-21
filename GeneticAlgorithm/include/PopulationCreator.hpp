#pragma once

#include <vector>

#include "Population.hpp"
#include "GenotypeCreator.hpp"

/*!
    Class used to produce Population instances
 */
class PopulationCreator {
private:
    /*!
        Private constructor to prevent unwanted initialization
     */
    PopulationCreator() { }
    /*!
        Private copy constructor to prevent unwanted initialization
     */
    PopulationCreator(const PopulationCreator&) { }

public:
    static PopulationCreator& instance();
    template <typename TGenotype,
    template <typename, typename = std::allocator<TGenotype>> class TCollection = std::vector>
    Population<TGenotype, TCollection> createWithSize(unsigned int populationSize,
            const GenotypeCreator<TGenotype>  &genotypeCreator);
};

PopulationCreator& PopulationCreator::instance() {
    static PopulationCreator instance;
    return instance;
}

template <typename TGenotype,
template <typename, typename> class TCollection>
Population<TGenotype, TCollection> PopulationCreator::createWithSize(unsigned int populationSize,
        const GenotypeCreator<TGenotype> &genotypeCreator) {
    TCollection<TGenotype, std::allocator<TGenotype>> genotypes;
    for ( int i = 0; i < populationSize; i++ ) {
        genotypes.push_back(genotypeCreator.create());
    }
    return Population<TGenotype, TCollection>(genotypes);
}
