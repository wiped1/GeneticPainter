#pragma once

#include <random>
#include <opencv2/core/core.hpp>
#include "GeneticAlgorithm.hpp"
#include "EllipseGenerator.hpp"

#include "Ellipse.hpp"

using namespace cv;
using namespace gall;
using EllipsesGenotype = Genotype<Ellipse, std::set>;

class EllipsesGenotypeInitializer : public GenotypeInitializer<EllipsesGenotype> {

private:

    EllipseGenerator *ellipseGenerator;

public:
    EllipsesGenotypeInitializer(EllipseGenerator& ellipseGenerator);
    void initialize(std::vector<Ellipse> &ellipses) const;
};

