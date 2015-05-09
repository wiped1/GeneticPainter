//
// Created by Mckomo on 28.04.15.
//

#pragma once

#include <opencv2/opencv.hpp>
#include "Genotype.hpp"
#include "Ellipse.hpp"

using namespace cv;
using namespace gall;

using EllipsesGenotype = Genotype<Ellipse, std::set>;

class EllipsesRenderer
{

public:

    void render(Mat &canvas, const EllipsesGenotype &ellipses) const;

};


