#pragma once

#include <vector>
#include "Genotype.hpp"
#include "Ellipse.hpp"

/*!
    Class used to store data about genotypes pool

    Genotypes contained within population will act as a canvas for genetic evolution.
    In course of the program, the genotypes will be selected, crossed-over, mutated
    in order to produce the best possible (albeit local) solution.
 */
template <typename T>
class Population {
private:
    std::vector<Genotype<T>> _genotypes;

public:
    Population();
    Population(unsigned int size);
    Population(const std::vector<Genotype<T>> &genotypes);
    Population(const Population<T> &other);
    Population<T> & operator=(const Population<T> &other);
    /*!
        Method used to return vector of genotypes
     */
    const std::vector<Genotype<T>>& getGenotypes() const;
    virtual ~Population();
};

template <typename T>
Population<T>::Population() : _genotypes() {
    // do nothing
}

template <typename T>
Population<T>::Population(unsigned int size) : _genotypes(size) {
    // do nothing
}

template <typename T>
Population<T>::Population(const std::vector<Genotype<T>> &genotypes) : _genotypes(genotypes) {
    // do nothing
}

template <typename T>
Population<T>::Population(const Population &other) : _genotypes(other.getGenotypes()) {
    // do nothing
}

template <typename T>
Population<T> &Population<T>::operator=(const Population<T> &other) {
    _genotypes = other._genotypes;
    return *this;
}

template <typename T>
const std::vector<Genotype<T>> &Population<T>::getGenotypes() const {
    return _genotypes;
}

template <typename T>
Population<T>::~Population() {
    // do nothing
}
