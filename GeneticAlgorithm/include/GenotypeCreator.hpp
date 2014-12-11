#pragma once

#include "Genotype.hpp"

/*!
    Abstract class used to create Genotype instances
 */
template <typename T>
class GenotypeCreator {
public:
    virtual Genotype<T> create() const = 0;
};