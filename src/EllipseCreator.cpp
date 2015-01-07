#include "EllipseCreator.h"

using namespace cv;

EllipseCreator::EllipseCreator(std::mt19937 &prng, cv::Size position_bound, unsigned int max_diameter)
{
    _prng = prng;
    _position_bound = position_bound;
    _max_diameter = max_diameter;
}

Ellipse EllipseCreator::generateRandom()
{
    return Ellipse(_generateRandomPosition(), _generateRandomSize(), _genrateRandomColor());
}

Point EllipseCreator::_generateRandomPosition()
{
    return Point(
            _generateRandomNumber(_position_bound.width),
            _generateRandomNumber(_position_bound.height));
}

Size EllipseCreator::_generateRandomSize()
{
    return Size(
            _generateRandomNumber(_max_diameter),
            _generateRandomNumber(_max_diameter));
}

Scalar EllipseCreator::_genrateRandomColor()
{
    return Scalar(
            _generateRandomNumber(255),
            _generateRandomNumber(255),
            _generateRandomNumber(255));
}

unsigned int EllipseCreator::_generateRandomNumber(unsigned int right_bound) {
    return _prng() % (right_bound + 1);
}
