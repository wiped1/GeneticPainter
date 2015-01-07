#pragma once

#include <random>
#include <opencv2/core/core.hpp>

#include "Ellipse.h"

using namespace std;
using namespace cv;

class EllipseCreator {

    Size _position_bound;
    mt19937 _prng;
    unsigned int _max_diameter;

    Point _generateRandomPosition();
    Size _generateRandomSize();
    Scalar _genrateRandomColor();
    unsigned int _generateRandomNumber(unsigned int right_bound);

public:
    EllipseCreator(std::mt19937 &prng, cv::Size position_bound, unsigned int max_diameter);
    Ellipse generateRandom();
};

