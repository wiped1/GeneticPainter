#include "Catch/catch.hpp"

#include "PopulationCreator.hpp"
#include "Population.hpp"

// anonymous namespace to prevent linker errors
namespace {
    class IntegerGenotypeCreator : public GenotypeCreator<Genotype<int>> {
    private:
        unsigned int _size;
    public:
        IntegerGenotypeCreator(unsigned int size) : _size(size) {
            // do nothing
        }
        virtual Genotype<int> create() const {
            std::vector<int> genes(_size);
            for ( int gene : genes ) {
                gene = rand() % 100;
            }
            return Genotype<int>(genes);
        }
    };
}

SCENARIO( "PopulationCreator is used to create Population instances", "[population creator]") {
    GIVEN( "An empty Population instance" ) {
        Population<Genotype<int>> population;

        WHEN( "Population is created" ) {
            const unsigned int POPULATION_SIZE = 10;
            const unsigned int GENOTYPE_SIZE = 50;
            IntegerGenotypeCreator genotypeCreator(GENOTYPE_SIZE);

            population = PopulationCreator::createWithSize<Genotype<int>>(POPULATION_SIZE, genotypeCreator);

            THEN( "The population size is correct" ) {
                REQUIRE(population.getGenotypes().size() == POPULATION_SIZE);
            }
            AND_THEN( "The population genotypes have correct size" ) {
                for ( unsigned int i = 0; i < POPULATION_SIZE; i++ ) {
                    REQUIRE(population.getGenotypes()[i].getGenes().size() == GENOTYPE_SIZE);
                }
            }
        }
    }
}
