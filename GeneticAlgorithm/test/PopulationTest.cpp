#include "Catch/catch.hpp"

#include "Population.hpp"
#include "GenotypeCreator.hpp"

//#ifndef INTEGER_GENOTYPE_CREATOR_H
//#define INTEGER_GENOTYPE_CREATOR_H
//// BEGINNING of test class definition
//class IntegerGenotypeCreator : public GenotypeCreator<int> {
//private:
//    unsigned int _size;
//public:
//    IntegerGenotypeCreator(unsigned int size);
//    virtual Genotype<int> create() const;
//};
//
//IntegerGenotypeCreator::IntegerGenotypeCreator(unsigned int size) : _size(size) {
//    // do nothing
//}
//
//Genotype<int> IntegerGenotypeCreator::create() const {
//    std::vector<int> genes(_size);
//    for ( int gene : genes ) {
//        gene = rand() % 100;
//    }
//    return Genotype<int>(genes);
//}
//// END of test class definition
//#endif

// BEGINNING of test class definition
class AnotherIntegerGenotypeCreator : public GenotypeCreator<int> {
private:
    unsigned int _size;
public:
    AnotherIntegerGenotypeCreator(unsigned int size);
    virtual Genotype<int> create() const;
};

AnotherIntegerGenotypeCreator::AnotherIntegerGenotypeCreator(unsigned int size) : _size(size) {
    // do nothing
}

Genotype<int> AnotherIntegerGenotypeCreator::create() const {
    std::vector<int> genes(_size);
    for ( int gene : genes ) {
        gene = rand() % 100;
    }
    return Genotype<int>(genes);
}
// END of test class definition


SCENARIO( "Population contains collection of genotypes", "[population]" ) {
    GIVEN( "An empty Population of type int" ) {
        Population<int> pop;

        WHEN( "Population is created with size constructor" ) {
            const unsigned int SIZE = 50;
            pop = Population<int>(SIZE);

            THEN( "Population size is correct" ) {
                REQUIRE(pop.getGenotypes().size() == SIZE);
            }
        }
        WHEN( "Population is constructed using existing vector" ) {
            const unsigned int POPULATION_SIZE = 10;
            const unsigned int GENOTYPE_SIZE = 50;
            std::vector<Genotype<int>> genotypes(POPULATION_SIZE);
            AnotherIntegerGenotypeCreator genotypeCreator(GENOTYPE_SIZE);

            for ( int i = 0; i < POPULATION_SIZE; i++ ) {
                genotypes[i] = genotypeCreator.create();
            }

            pop = Population<int>(genotypes);
            THEN( "The constructed population has correct size" ) {
                REQUIRE(pop.getGenotypes().size() == POPULATION_SIZE);
            }
            AND_THEN( "The constructed population genotypes have correct sizes" ) {
                for ( int i = 0; i < POPULATION_SIZE; i++ ) {
                    REQUIRE(pop.getGenotypes()[i].getGenes().size() == GENOTYPE_SIZE);
                }
            }
        }
    }
}
