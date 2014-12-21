#include "Catch/catch.hpp"

#include "Population.hpp"
#include "Genotype.hpp"

SCENARIO( "Population contains collection of genotypes", "[population]" ) {
    GIVEN( "Population instance" ) {
        Population<Genotype<int>> population;

        WHEN( "Population is constructed with size" ) {
            const unsigned int SIZE = 10;
            population = Population<Genotype<int>>(SIZE);

            THEN( "The collection size is proper" ) {
                REQUIRE(population.getGenotypes().size() == SIZE);
            }
        }
        WHEN( "Population is constructed with existing genotype vector" ) {
            std::vector<int> vec { 1, 2, 3, 4, 5 };
            std::vector<Genotype<int>> genotypes(1);
            genotypes.emplace_back(Genotype<int>(vec));

            population = Population<Genotype<int>>(genotypes);

            THEN( "The constructed genotypes are equal" ) {
                REQUIRE(population.getGenotypes()[0] == genotypes[0]);
            }
            AND_THEN( "The size is proper" ) {
                REQUIRE(population.getGenotypes().size() == genotypes.size());
            }
        }
        WHEN( "Population is assigned a existing instance" ) {
            std::vector<int> vec { 1, 2, 3, 4, 5 };
            std::vector<Genotype<int>> genotypes(1);
            genotypes.emplace_back(Genotype<int>(vec));
            Population<Genotype<int>> other = Population<Genotype<int>>(genotypes);

            population = other;

            THEN( "They are equal when comparing by genotypes" ) {
                REQUIRE(population.getGenotypes() == other.getGenotypes());
            }
        }
    }
}

