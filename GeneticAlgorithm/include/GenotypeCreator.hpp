#pragma once

#include "Genotype.hpp"

/*!
    Abstract class used to create Genotype instances
 */
template <typename T,
template <typename, typename = std::allocator<T>> class C = std::vector>
class GenotypeCreator {
public:
    virtual Genotype<T, C> create() const = 0;
};