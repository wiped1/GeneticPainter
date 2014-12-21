#pragma once

#include <vector>
#include "Genotype.hpp"

/*!
    Class used to store data about genotypes pool

    Genotypes contained within population will act as a canvas for genetic evolution.
    In course of the program, the genotypes will be selected, crossed-over, mutated
    in order to produce the best possible (albeit local) solution.
 */
template <typename G,
template <typename, typename = std::allocator<G>> class C = std::vector>
class Population {
private:
    C<G> _genotypes;

public:
    Population();
    Population(unsigned int size);
    Population(C<G> const &genotypes);
    Population<G, C> operator=(const Population<C<G>> &other);
    /*!
        Method used to return collection of genotypes
     */
    const C<G>& getGenotypes() const;
    virtual ~Population();
};

template <typename G,
template <typename, typename> class C>
Population<G, C>::Population() : _genotypes() {
    // do nothing
}

template <typename G,
template <typename, typename> class C>
Population<G, C>::Population(unsigned int size) : _genotypes(size) {
    // do nothing
}

template <typename G,
template <typename, typename> class C>
Population<G, C>::Population(C<G, std::allocator<G>> const &genotypes) : _genotypes(genotypes) {
    // do nothing
}

template <typename G,
template <typename, typename> class C>
Population<G, C> Population<G, C>::operator=(const Population<C<G, std::allocator<G>>> &other) {
    _genotypes = other._genotypes;
    return *this;
}

template <typename G,
template <typename, typename> class C>
const C<G, std::allocator<G>> &Population<G, C>::getGenotypes() const {
    return _genotypes;
}

template <typename G,
template <typename, typename> class C>
Population<G, C>::~Population() {
    // do nothing
}
