#pragma once

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
    PopulationCreator(const PopulationCreator &) { }

public:
    static PopulationCreator & instance();
    template <typename T>
    Population<T> createWithSize(unsigned int populationSize, const GenotypeCreator<T> & genotypeCreator);
};
