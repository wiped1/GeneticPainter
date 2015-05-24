//
// Created by Maciej Komorowski on 24.05.15.
//

#include <algorithm>
#include "Catch/catch.hpp"
#include "EllipsesCrossoverOperator.hpp"

using namespace cv;

SCENARIO("EllipesCorssoverOperator merges two genotypes into one", "[imageComparator]") {

    std::mt19937 prng(time(0));
    EllipsesCrossoverOperator crossoverOperator(prng);

    GIVEN("two parent genotypes filled times with alarge number of two different ellipses") {

        unsigned long genotypeSize = 10000;

        Ellipse blueEllipse(Point(0, 0), Size(100, 100), Scalar(255, 0, 0));
        Ellipse redEllipse(Point(0, 0), Size(100, 100), Scalar(0, 0, 255));

        EllipsesGenotype::Collection blueEllipses(genotypeSize, blueEllipse);
        EllipsesGenotype::Collection redEllipses(genotypeSize, redEllipse);

        EllipsesGenotype::Type blueGenotype(blueEllipses);
        EllipsesGenotype::Type redGenotype(redEllipses);
        std::vector<EllipsesGenotype::Type> parents = {blueGenotype, redGenotype};

        WHEN("crossed") {

            EllipsesGenotype::Type child = crossoverOperator.cross(parents);

            THEN("new genotype should have the same large number of genes") {
                REQUIRE(std::distance(child.cbegin(), child.cend()) == genotypeSize);
            }

            THEN("new genotype should have equal number of gens from both parents")
            {
                long blueCounter = count(child.cbegin(), child.cend(), blueEllipse);
                long redCounter = count(child.cbegin(), child.cend(), redEllipse);

                REQUIRE(blueCounter == redCounter);
            }

            THEN("new genotype corssed fragments average length should be a quoter of the large number value")
            {
                long currentLength = 1;
                Ellipse currentFragmentEllipse = blueEllipse;
                std::vector<long> fragmentsLength;

                for (auto& ellipse : child)
                {
                    if (!(ellipse == currentFragmentEllipse))
                    {
                        fragmentsLength.push_back(currentLength);
                        currentFragmentEllipse = ellipse;
                        currentLength = 1;
                    }

                    currentLength++;
                }

                long meanLength = std::accumulate(fragmentsLength.begin(), fragmentsLength.end(), 0.0) / fragmentsLength.size();

                REQUIRE(meanLength == genotypeSize / 4);
            }

        }
    }

}
