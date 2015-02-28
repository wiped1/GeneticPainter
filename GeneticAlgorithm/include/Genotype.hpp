#pragma once

#include <vector>

template <typename T>
class Genotype {
private:
    std::vector<T> _genes;
    Genotype() { }

public:
    Genotype(const std::vector<T>& _genes);
    const std::vector<T>& getGenes() const;
};

template <typename T>
Genotype<T>::Genotype(const std::vector<T>& genes) : _genes(genes) {
    // do nothing
}

template <typename T>
const std::vector<T>& Genotype<T>::getGenes() const {
    return _genes;
}
