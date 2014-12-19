#include "Catch/catch.hpp"

#include <list>

#include "GenotypeCreator.hpp"

// anonymous namespace to prevent linker errors
namespace {
    class IntegerGenotypeCreator : public GenotypeCreator<int> {
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

    class IntegerListGenotypeCreator : public GenotypeCreator<int, std::list> {
    private:
        unsigned int _size;
    public:
        IntegerListGenotypeCreator(unsigned int size) : _size(size) {
            // do nothing
        }
        virtual Genotype<int, std::list> create() const {
            std::list<int> genes(_size);
            for ( int gene : genes ) {
                gene = rand() % 100;
            }
            return Genotype<int, std::list>(genes);
        }
    };
}

SCENARIO( "GenotypeCreator is used to create Genotype instances" ) {
    GIVEN( "A constant genotype size" ) {
        const unsigned int SIZE = 50;

        WHEN( "A genotype is instantiated using factory" ) {
            IntegerGenotypeCreator genotypeCreator(SIZE);
            Genotype<int> genotype = genotypeCreator.create();

            THEN( "The constructed genotype has correct size" ) {
                REQUIRE(genotype.getGenes().size() == SIZE);
            }
        }
        WHEN( "A genotype is instantiated with non-default collection using factory") {
            IntegerListGenotypeCreator genotypeCreator(SIZE);
            Genotype<int, std::list> genotype = genotypeCreator.create();

            THEN( "The constructed genotype genes have correct type" ) {
                REQUIRE(typeid(genotype.getGenes()) == typeid(std::list<int>));
            }
        }
    }
}

