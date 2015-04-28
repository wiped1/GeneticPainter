#pragma once

#include <random>
#include <opencv2/core/core.hpp>
#include "GeneticAlgorithm.hpp"
#include "EllipseGenerator.hpp"

#include "Ellipse.hpp"

using namespace std;
using namespace cv;

class EllipsesGenotypeInitializer : public GenotypeInitializer<Ellipse> {

private:

    EllipseGenerator* _ellipseGenerator;

    Ellipse generateRandom() const;
    Point generateRandomPosition() const;
    Size generateRandomSize() const;
    Scalar generateRandomColor() const;
    unsigned int generateRandomNumber(unsigned int rightBound) const;

public:
    EllipsesGenotypeInitializer(EllipseGenerator& ellipseGenerator);
    void initialize(std::vector<Ellipse> &ellipses) const;
};

