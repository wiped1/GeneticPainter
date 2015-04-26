#include "EllipsesInitializer.hpp"
#include "EllipsesSizeComperator.hpp"

using namespace cv;

EllipsesInitializer::EllipsesInitializer(std::mt19937 &prng, cv::Size positionBound, unsigned int maxDiameter)
{
    _prng = &prng;
    _positionBound = positionBound;
    _maxDiameter = maxDiameter;
}

void EllipsesInitializer::initialize(std::vector<Ellipse> &ellipses) const
{
    ellipses.reserve(100);

    for(unsigned int i = 0; i < 100; i++)
    {
        ellipses.push_back(generateRandom());
    }
}

Ellipse EllipsesInitializer::generateRandom() const
{
    return Ellipse(generateRandomPosition(), generateRandomSize(), generateRandomColor());
}

Point EllipsesInitializer::generateRandomPosition() const
{
    return Point(
            generateRandomNumber(_positionBound.width),
            generateRandomNumber(_positionBound.height));
}

Size EllipsesInitializer::generateRandomSize() const
{
    return Size(
            generateRandomNumber(_maxDiameter),
            generateRandomNumber(_maxDiameter));
}

Scalar EllipsesInitializer::generateRandomColor() const
{
    return Scalar(
            generateRandomNumber(255),
            generateRandomNumber(255),
            generateRandomNumber(255));
}

unsigned int EllipsesInitializer::generateRandomNumber(unsigned int rightBound) const {
    return (*_prng)() % (rightBound + 1);
}

