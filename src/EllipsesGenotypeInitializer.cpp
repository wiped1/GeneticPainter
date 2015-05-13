#include <EllipseGenerator.hpp>
#include "EllipsesGenotypeInitializer.hpp"
#include "EllipsesSizeComparator.hpp"

using namespace cv;

EllipsesGenotypeInitializer::EllipsesGenotypeInitializer(EllipseGenerator& ellipseGenerator) : ellipseGenerator(&ellipseGenerator)
{
    // NOTING TO DO
}

void EllipsesGenotypeInitializer::initialize(EllipsesGenotype::Collection &ellipses) const
{
    for(unsigned int i = 0; i < 100; i++) {
        ellipses.push_back(ellipseGenerator->generateRandom());
    }
}
