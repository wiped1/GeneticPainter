#include "EllipseInitializer.hpp"
#include "EllipseSorter.hpp"

using namespace cv;

EllipseInitializer::EllipseInitializer(std::mt19937 &prng, cv::Size position_bound, unsigned int max_diameter)
{
    _prng = &prng;
    _position_bound = position_bound;
    _max_diameter = max_diameter;
}

void EllipseInitializer::initialize(std::vector<Ellipse> &ellipses) const
{
    ellipses.reserve(100);

    for(unsigned int i = 0; i < 100; i++)
    {
        ellipses.push_back(_generateRandom());
    }

//    std::sort(ellipses.begin(), ellipses.end(), EllipseSorter::SortEllipseBySizeDesc);
}

Ellipse EllipseInitializer::_generateRandom() const
{
    return Ellipse(_generateRandomPosition(), _generateRandomSize(), _genrateRandomColor());
}

Point EllipseInitializer::_generateRandomPosition() const
{
    return Point(
            _generateRandomNumber(_position_bound.width),
            _generateRandomNumber(_position_bound.height));
}

Size EllipseInitializer::_generateRandomSize() const
{
    return Size(
            _generateRandomNumber(_max_diameter),
            _generateRandomNumber(_max_diameter));
}

Scalar EllipseInitializer::_genrateRandomColor() const
{
    return Scalar(
            _generateRandomNumber(255),
            _generateRandomNumber(255),
            _generateRandomNumber(255));
}

unsigned int EllipseInitializer::_generateRandomNumber(unsigned int rightBound) const {
    return (*_prng)() % (rightBound + 1);
}

