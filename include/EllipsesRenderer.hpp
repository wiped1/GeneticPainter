//
// Created by Mckomo on 28.04.15.
//

#pragma once

#include <opencv2/opencv.hpp>
#include "Ellipse.hpp"

using namespace cv;

class EllipsesRenderer {

private:

    Size _imageSize;

public:

    EllipsesRenderer(Size imageSize);
    void static render(Mat &canvas, const std::vector<Ellipse> &ellipses);

};


