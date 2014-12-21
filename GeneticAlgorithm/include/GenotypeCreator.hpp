#pragma once

#include "Genotype.hpp"

/*!
    Abstract class used to create Genotype instances
 */
template <typename G>
class GenotypeCreator {
public:
    virtual G create() const = 0;
};