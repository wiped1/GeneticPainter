//
// Created by Mckomo on 28.04.15.
//

#include "EllipseGenerator.hpp"

EllipseGenerator::EllipseGenerator(std::mt19937 &prng, cv::Size positionBound, unsigned int maxDiameter) : prng(&prng), positionBound(positionBound), maxDiameter(maxDiameter)
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
    return Size(
            generateRandomNonnegative(maxDiameter),
            generateRandomNonnegative(maxDiameter));
}

Scalar EllipseGenerator::generateRandomColor() const
{
    return Scalar(
            generateRandomNonnegative(255),
            generateRandomNonnegative(255),
            generateRandomNonnegative(255));
}

unsigned int EllipseGenerator::generateRandomNonnegative(unsigned int rightBound) const
{
    return (*prng)() % (rightBound + 1);
}
