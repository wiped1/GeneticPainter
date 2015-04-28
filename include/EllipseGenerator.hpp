//
// Created by Mckomo on 28.04.15.
//

#pragma once

#include <random>
#include "Ellipse.hpp"

class EllipseGenerator {

private:

    Size _positionBound;
    std::mt19937 *_prng;
    unsigned int _maxDiameter;

    Point generateRandomPosition() const;
    Size generateRandomSize() const;
    Scalar generateRandomColor() const;
    unsigned int generateRandomNonnegative(unsigned int rightBound) const;

public:

    EllipseGenerator(std::mt19937 &prng, cv::Size positionBound, unsigned int maxDiameter);
    Ellipse generateRandom() const;

};
