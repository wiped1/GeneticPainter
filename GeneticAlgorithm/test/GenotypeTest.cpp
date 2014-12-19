#include "Catch/catch.hpp"

#include <list>

#include "Genotype.hpp"

SCENARIO( "Genotype contains information about genes", "[genotype]" ) {
    GIVEN( "Genotype instance" ) {
        Genotype<int> genotype;

        WHEN( "It's constructed with an existing vector" ) {
            std::vector<int> vec { 1, 2, 3, 4, 5};
            genotype = Genotype<int>(vec);

            THEN( "It's value is comparable by collection" ) {
                REQUIRE(genotype == vec);
            }
            AND_THEN( "It's value is comparable by object" ) {
                Genotype<int> other(vec);

                REQUIRE(genotype == other);
            }
            AND_THEN( "It's comapred properly" ) {
                std::vector<int> otherVec { 2, 3, 4 };
                Genotype<int> other(otherVec);

                REQUIRE(genotype != other);
                REQUIRE_FALSE(genotype == other);
            }
            AND_THEN( "It's size is proper" ) {
                REQUIRE(genotype.getGenes().size() == 5);
            }
            AND_THEN( "It's able to be copy constructed") {
                Genotype<int> other(genotype);
            }
        }
    }
    GIVEN( "A Genotype with non-default collection" ) {
        Genotype<int, std::list> genotype;

        WHEN( "It's constructed with an existing list" ) {
            std::list<int> list = { 1, 2, 3, 4, 5 };
            genotype = Genotype<int, std::list>(list);

            THEN( "Genes type is proper" ) {
                REQUIRE(typeid(genotype.getGenes()) == typeid(std::list<int>));
            }
        }
    }

    // test build in typedefs that describe type and collection
    REQUIRE(typeid(Genotype<int>::type) == typeid(int));
    REQUIRE(typeid(Genotype<int>::collection) == typeid(std::vector<int>));
}
