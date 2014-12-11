#include "Catch/catch.hpp"

#include "GenotypeCreator.hpp"

#ifndef INTEGER_GENOTYPE_CREATOR_H
#define INTEGER_GENOTYPE_CREATOR_H
// BEGINNING of test class definition
class IntegerGenotypeCreator : public GenotypeCreator<int> {
private:
    unsigned int _size;
public:
    IntegerGenotypeCreator(unsigned int size);
    virtual Genotype<int> create() const;
};

IntegerGenotypeCreator::IntegerGenotypeCreator(unsigned int size) : _size(size) {
    // do nothing
}

Genotype<int> IntegerGenotypeCreator::create() const {
    std::vector<int> genes(_size);
    for ( int gene : genes ) {
        gene = rand() % 100;
    }
    return Genotype<int>(genes);
}
// END of test class definition
#endif

SCENARIO( "GenotypeCreator is used to create Genotype instances" ) {
    GIVEN( "An GenotypeCreator implementation" ) {
        const unsigned int SIZE = 50;
        IntegerGenotypeCreator genotypeCreator(SIZE);

        WHEN( "A genotype is instantiated using factory" ) {
            Genotype<int> genotype = genotypeCreator.create();

            THEN( "The constructed genotype has correct size" ) {
                REQUIRE(genotype.getGenes().size() == SIZE);
            }
        }
    }
}


