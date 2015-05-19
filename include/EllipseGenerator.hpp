//
// Created by Mckomo on 28.04.15.
//

#pragma once

#include <random>
#include <memory>
#include "Ellipse.hpp"

class EllipseGenerator {

private:

    Size positionBound;
    std::mt19937 *prng;
    std::unique_ptr<std::uniform_real_distribution<double>> widthHeightRatioDist;
    unsigned int minDiameter;
    unsigned int maxDiameter;

    Point generateRandomPosition() const;
    Size generateRandomSize() const;
    Scalar generateRandomColor() const;
    unsigned int generateRandomNonnegative(unsigned int rightBound) const;
    unsigned int generateRandomRange(unsigned int min, unsigned int max) const;

public:

    const Size& getPositionBound() const;
    unsigned int getMaxDiameter() const;

    EllipseGenerator(std::mt19937 &prng, cv::Size positionBound,
                     unsigned int minDiameter, unsigned int maxDiameter);
    Ellipse generateRandom() const;

};
