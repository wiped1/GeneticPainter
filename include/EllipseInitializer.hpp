#pragma once

#include <random>
#include <opencv2/core/core.hpp>
#include "GeneticAlgorithm.hpp"

#include "Ellipse.hpp"

using namespace std;
using namespace cv;

class EllipseInitializer : public GenotypeInitializer<Ellipse> {

private:

    Size _position_bound;
    mt19937 *_prng;
    unsigned int _max_diameter;

    Ellipse _generateRandom() const;
    Point _generateRandomPosition() const;
    Size _generateRandomSize() const;
    Scalar _genrateRandomColor() const;
    unsigned int _generateRandomNumber(unsigned int rightBound) const;

public:
    EllipseInitializer(std::mt19937 &prng, cv::Size position_bound, unsigned int max_diameter);
    void initialize(std::vector<Ellipse> &ellipses) const;
};

