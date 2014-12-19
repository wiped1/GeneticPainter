#pragma once

#include <iostream>
#include <vector>

/*!
    Genotype template used to store genes values.

    Genotype template can be instantiated interchangeably using only the type of
    stored genes (ex. Genotype<int>) that defaults to Genotype<int, std::vector>,
    or it can be instantiated with collection type, for example Genotype<int, std::list>

    \tparam T type of stored genes
    \tparam C collection that stores genes
 */
template <typename T,
template <typename, typename = std::allocator<T>> class C = std::vector>
class Genotype {
private:
    C<T, std::allocator<T>> _genes;

public:
    typedef T type; //!< The type of specific template implementation
    typedef C<T, std::allocator<T>> collection; //!< The collection of specific template implementation

    Genotype();
    Genotype(const C<T, std::allocator<T>> &genes);
    bool operator ==(const C<T, std::allocator<T>> &other);
    bool operator ==(const Genotype<T, C> &other);
    bool operator !=(const C<T, std::allocator<T>> &other);
    bool operator !=(const Genotype<T, C> &other);
    const C<T, std::allocator<T>>& getGenes() const;
    virtual ~Genotype();
};

template <typename T,
template <typename, typename> class C>
Genotype<T, C>::Genotype() : _genes() {
    // do nothing
}

template <typename T,
template <typename, typename> class C>
Genotype<T, C>::Genotype(const C<T, std::allocator<T>> &genes) : _genes(genes) {
    // do nothing
}

template <typename T,
template <typename, typename> class C>
bool Genotype<T, C>::operator ==(const C<T, std::allocator<T>> &other) {
    return _genes == other;
}

template <typename T,
template <typename, typename> class C>
bool Genotype<T, C>::operator ==(const Genotype<T, C> &other) {
    return _genes == other._genes;
}

template <typename T,
template <typename, typename> class C>
bool Genotype<T, C>::operator !=(const C<T, std::allocator<T>> &other) {
    return _genes != other;
}

template <typename T,
template <typename, typename> class C>
bool Genotype<T, C>::operator !=(const Genotype<T, C> &other) {
    return _genes != other._genes;
}

template <typename T,
template <typename, typename> class C>
const C<T, std::allocator<T>>& Genotype<T, C>::getGenes() const {
    return _genes;
}

template <typename T,
template <typename, typename> class C>
Genotype<T, C>::~Genotype() {
    // do nothing
}
