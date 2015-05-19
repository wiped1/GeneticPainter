//
// Created by Mckomo on 28.04.15.
//

#pragma once

#include <random>
#include "Ellipse.hpp"

class EllipseGenerator {

private:

    Size positionBound;
    std::mt19937 *prng;
    unsigned int maxDiameter;

    Point generateRandomPosition() const;
    Size generateRandomSize() const;
    Scalar generateRandomColor() const;
    unsigned int generateRandomNonnegative(unsigned int rightBound) const;

public:

    const Size& getPositionBound() const;
    unsigned int getMaxDiameter() const;

    EllipseGenerator(std::mt19937 &prng, cv::Size positionBound, unsigned int maxDiameter);
    Ellipse generateRandom() const;

};
