#include <EllipseGenerator.hpp>
#include "EllipsesGenotypeInitializer.hpp"
#include "EllipsesSizeComparator.hpp"
#include "EvolvingEnvironment.hpp"

using namespace cv;

EllipsesGenotypeInitializer::EllipsesGenotypeInitializer(EllipseGenerator& ellipseGenerator) : ellipseGenerator(&ellipseGenerator)
{
    // NOTING TO DO
}

void EllipsesGenotypeInitializer::initialize(EllipsesGenotype::Collection &ellipses) const
{
//    for(unsigned int i = 0; i < EvolvingEnvironmentProvider::getInstance().genesCount; i++) {
//        ellipses.emplace_back(ellipseGenerator->generateRandom());
//    }
    for(unsigned int i = 0; i < 1; i++) {
        ellipses.emplace_back(ellipseGenerator->generateRandom());
    }
}
