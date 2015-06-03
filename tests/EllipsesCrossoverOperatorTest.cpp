//
// Created by Maciej Komorowski on 24.05.15.
//

#include <algorithm>
#include <cmath>
#include "Catch/catch.hpp"
#include "EllipsesCrossoverOperator.hpp"

using namespace cv;

SCENARIO("EllipesCorssoverOperator merges two genotypes into one", "[imageComparator]") {

    std::mt19937 prng(time(0));
    EllipsesCrossoverOperator crossoverOperator(prng);

    GIVEN("two parent genotypes filled times with alarge number of two different ellipses") {

        unsigned long genotypeSize = 200000;

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
                REQUIRE(child.asCollection().size() == genotypeSize);
            }

            THEN("new genotype should have similar number of gens from both parents")
            {
                long blueCounter = static_cast<double>(count(child.asCollection().cbegin(), child.asCollection().cend(), blueEllipse));
                long redCounter = static_cast<double>(count(child.asCollection().cbegin(), child.asCollection().cend(), redEllipse));
                double colorDelta = static_cast<double>(std::abs(blueCounter - redCounter)) / genotypeSize;

                REQUIRE(colorDelta < 0.5);
            }

            THEN("new genotype corssed fragments average length should be a around quoter of the large number value")
            {
                long currentLength = 1;
                std::vector<long> fragmentsLength;
                Ellipse currentFragmentEllipse = *child.asCollection().begin();

                for (auto& ellipse : child.asCollection())
                {
                    if (!(ellipse == currentFragmentEllipse))
                    {
                        fragmentsLength.push_back(currentLength);
                        currentFragmentEllipse = ellipse;
                        currentLength = 1;
                    }

                    currentLength++;
                }

                long quoterSize = genotypeSize / 4;
                long meanLength = std::accumulate(fragmentsLength.begin(), fragmentsLength.end(), 0.0) / fragmentsLength.size();
                long meanDelta = std::abs(quoterSize - meanLength);

                REQUIRE(meanDelta < quoterSize / 1.5);
            }

        }
    }

}
