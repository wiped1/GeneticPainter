#pragma once

#include <random>
#include <opencv2/core/core.hpp>
#include "GeneticAlgorithm.hpp"

#include "Ellipse.hpp"

using namespace std;
using namespace cv;

class EllipsesInitializer : public GenotypeInitializer<Ellipse> {

private:

    Size _positionBound;
    mt19937 *_prng;
    unsigned int _maxDiameter;

    Ellipse generateRandom() const;
    Point generateRandomPosition() const;
    Size generateRandomSize() const;
    Scalar generateRandomColor() const;
    unsigned int generateRandomNumber(unsigned int rightBound) const;

public:
    EllipsesInitializer(std::mt19937 &prng, cv::Size positionBound, unsigned int maxDiameter);
    void initialize(std::vector<Ellipse> &ellipses) const;
};

