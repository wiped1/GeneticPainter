#pragma once

#include <iostream>
#include <vector>

#include "Ellipse.hpp"

/*!
    Genotype class used to store genes values.

    Values are encoded as vector of Ellipse structs.
 */
template <typename T>
class Genotype {
private:
    std::vector<T> _genes;

public:
    Genotype();
    /*!
        Constructor used to initialize genes with existing ones
     */
    Genotype(const std::vector<T> &genes);
    Genotype<T> & operator=(const Genotype<T> &other);
    /*!
        Method used to return vector of genes
     */
    const std::vector<T>& getGenes() const;
    virtual ~Genotype();
};
template <typename T>
Genotype<T>::Genotype() : _genes() {
    // do nothing
}

template <typename T>
Genotype<T>::Genotype(const std::vector<T> &genes) : _genes(genes) {
    // do nothing
}

template <typename T>
Genotype<T> & Genotype<T>::operator=(const Genotype<T> &other) {
    _genes = other._genes;
    return *this;
}

template <typename T>
const std::vector<T> & Genotype<T>::getGenes() const {
    return _genes;
}

template <typename T>
Genotype<T>::~Genotype() {
    // do nothing
}
