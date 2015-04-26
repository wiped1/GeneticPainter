//
// Created by Mckomo on 18.04.15.
//

#include "EllipsesSelectionStrategy.hpp"
#include "Ranking.hpp"
#include "Population.hpp"


void EllipsesSelectionStrategy::eliminate(Population<Ellipse> &population, typename Ranking<Ellipse>::Type ranking)
{
    auto& genotypes = population.getGenotypes();
    std::vector<Genotype<Ellipse>> afterElimination;

    // iterate through half with higher values
    // and populate new vector
    auto it = ranking.begin();
    std::cout << (*it).second << std::endl;
    typename std::vector<Genotype<Ellipse>>::size_type i;
    for (i = 0; i < genotypes.size() / 2; i++) {
        afterElimination.push_back(std::move(*(*it).first));
        it++;
    }

    genotypes = std::move(afterElimination);
}