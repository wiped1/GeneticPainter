#include <EllipseGenerator.hpp>
#include "EllipsesGenotypeInitializer.hpp"
#include "EllipsesSizeComperator.hpp"

using namespace cv;

EllipsesGenotypeInitializer::EllipsesGenotypeInitializer(EllipseGenerator& ellipseGenerator) : _ellipseGenerator(&ellipseGenerator)
{
    // NOTING TO DO
}

void EllipsesGenotypeInitializer::initialize(std::vector<Ellipse> &ellipses) const
{
    ellipses.reserve(100);

    for(unsigned int i = 0; i < 100; i++)
    {
        ellipses.push_back(_ellipseGenerator->generateRandom());
    }
}
