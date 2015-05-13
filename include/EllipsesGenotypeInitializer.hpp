#pragma once

#include <random>
#include <opencv2/core/core.hpp>
#include "GeneticAlgorithm.hpp"
#include "EllipseGenerator.hpp"
#include "EllipsesGenotype.hpp"
#include "Ellipse.hpp"

using namespace cv;
using namespace gall;

class EllipsesGenotypeInitializer : public GenotypeInitializer<EllipsesGenotype::Type> {

private:

    EllipseGenerator *ellipseGenerator;

public:
    EllipsesGenotypeInitializer(EllipseGenerator& ellipseGenerator);
    void initialize(EllipsesGenotype::Collection &ellipses) const;
};

