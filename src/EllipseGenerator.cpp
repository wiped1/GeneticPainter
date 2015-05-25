//
// Created by Mckomo on 28.04.15.
//

#include <iostream>
#include "EllipseGenerator.hpp"

const double MIN_WIDTH_HEIGHT_RATIO = 0.8;
const double MAX_WIDTH_HEIGHT_RATIO = 1.2;

EllipseGenerator::EllipseGenerator(std::mt19937 &prng,
                                   cv::Size positionBound,
                                   unsigned int minDiameter, unsigned int maxDiameter,
                                   double minWidthHeightRatio, double maxWidthHeightRatio) :
        prng(&prng), positionBound(positionBound), minDiameter(minDiameter), maxDiameter(maxDiameter),
        widthHeightRatioDist(new std::uniform_real_distribution<double>(minWidthHeightRatio, maxWidthHeightRatio))
{
    // NOTHING TO DO
}

Ellipse EllipseGenerator::generateRandom() const
{
    return Ellipse(generateRandomPosition(), generateRandomSize(), generateRandomColor());
}

Point EllipseGenerator::generateRandomPosition() const
{
    return Point(
            generateRandomNonnegative(positionBound.width),
            generateRandomNonnegative(positionBound.height));
}

Size EllipseGenerator::generateRandomSize() const
{
    int height = generateRandomRange(minDiameter, maxDiameter);
    double ratio = (*widthHeightRatioDist)(*prng);
    int width = static_cast<int>(height * ratio);
    if ( height < 0 && width < 0 ) {
        std::cout << "What the fuck" << std::endl;
    }
    return Size(
            width,
            height);
}

Scalar EllipseGenerator::generateRandomColor() const
{
    return Scalar(
            generateRandomNonnegative(255),
            generateRandomNonnegative(255),
            generateRandomNonnegative(255),
            1 * generateRandomNonnegative(255) / 255.0);
}

unsigned int EllipseGenerator::generateRandomNonnegative(unsigned int rightBound) const
{
    return (*prng)() % (rightBound + 1);
}

unsigned int EllipseGenerator::generateRandomRange(unsigned int min, unsigned int max) const {
    return min + ((*prng)() % (int)(max - min + 1));
}

const Size &EllipseGenerator::getPositionBound() const {
    return positionBound;
}

unsigned int EllipseGenerator::getMaxDiameter() const {
    return maxDiameter;
}
