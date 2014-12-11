#include "Catch/catch.hpp"

#include "Genotype.hpp"

SCENARIO( "Genotype contains information about genes", "[genotype]" ) {
    GIVEN( "Empty Genotype instance" ) {
        Genotype<int> genotype;

        WHEN( "It's constructed with a existing vector" ) {
            std::vector<int> vec { 1, 2, 3, 4, 5};
            genotype = Genotype<int>(vec);

            THEN( "Values are the same" ) {
                REQUIRE(genotype.getGenes() == vec);
            }
        }
    }
}
