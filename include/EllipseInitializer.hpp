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
    mt19937 _prng;
    unsigned int _max_diameter;

    Ellipse _generateRandom();
    Point _generateRandomPosition();
    Size _generateRandomSize();
    Scalar _genrateRandomColor();
    unsigned int _generateRandomNumber(unsigned int right_bound);

public:
    EllipseInitializer(std::mt19937 &prng, cv::Size position_bound, unsigned int max_diameter);
    virtual void initialize(std::vector<Ellipse> &ellipses);
};

