//
// Created by Mckomo on 28.04.15.
//

#pragma once

#include <opencv2/core/core.hpp>
#include "Genotype.hpp"
#include "EllipsesGenotype.hpp"

using namespace cv;
using namespace gall;

class EllipsesRenderer
{

const Scalar backgroundColor;

public:

    EllipsesRenderer(Scalar &backgroundColor);
    void render(Mat &canvas, const EllipsesGenotype::Type &ellipses) const;

};


