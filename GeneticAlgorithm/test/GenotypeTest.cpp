#include "Catch/catch.hpp"

#include "Genotype.hpp"

SCENARIO( "Genotype contains information about genes", "[genotype]" ) {
    GIVEN( "Genotype instance" ) {
        Genotype<std::vector<int>> genotype;

        WHEN( "It's constructed with an existing vector" ) {
            std::vector<int> vec { 1, 2, 3, 4, 5};
            genotype = Genotype<std::vector<int>>(vec);

            THEN( "It's value is comparable by collection" ) {
                REQUIRE(genotype == vec);
            }
            AND_THEN( "It's value is comparable by object" ) {
                Genotype<std::vector<int>> other(vec);

                REQUIRE(genotype == other);
            }
            AND_THEN( "It's comapred properly" ) {
                std::vector<int> otherVec { 2, 3, 4 };
                Genotype<std::vector<int>> other(otherVec);

                REQUIRE(genotype != other);
                REQUIRE_FALSE(genotype == other);
            }
            AND_THEN( "It's able to be copy constructed") {
                Genotype<std::vector<int>> other(genotype);
            }

        }
    }
}
