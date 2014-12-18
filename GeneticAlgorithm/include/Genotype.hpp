#pragma once

#include <iostream>
#include <vector>

/*!
    Genotype class used to store genes values.
 */
template <typename Collection>
class Genotype {
private:
    Collection _genes;

public:
    Genotype();
    Genotype(const Collection &genes);
    bool operator ==(const Collection &other);
    bool operator ==(const Genotype<Collection> &other);
    bool operator !=(const Collection &other);
    bool operator !=(const Genotype<Collection> &other);
    typename Collection::const_iterator cbegin();
    typename Collection::const_iterator cend();
    virtual ~Genotype();
};

template <typename Collection>
Genotype<Collection>::Genotype() : _genes() {
    // do nothing
}

template <typename Collection>
Genotype<Collection>::Genotype(const Collection &genes) : _genes(genes) {
    // do nothing
}

template <typename Collection>
bool Genotype<Collection>::operator ==(const Collection &other) {
    return _genes == other;
}

template <typename Collection>
bool Genotype<Collection>::operator ==(const Genotype<Collection> &other) {
    return _genes == other._genes;
}

template <typename Collection>
bool Genotype<Collection>::operator !=(const Collection &other) {
    return _genes != other;
}

template <typename Collection>
bool Genotype<Collection>::operator !=(const Genotype<Collection> &other) {
    return _genes != other._genes;
}

template <typename Collection>
typename Collection::const_iterator Genotype<Collection>::cbegin() {
    return _genes.cbegin();
}

template <typename Collection>
typename Collection::const_iterator Genotype<Collection>::cend() {
    return _genes.cend();
}

template <typename Collection>
Genotype<Collection>::~Genotype() {
    // do nothing
}
