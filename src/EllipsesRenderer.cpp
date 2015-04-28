//
// Created by Mckomo on 28.04.15.
//

#include "EllipsesRenderer.hpp"

EllipsesRenderer::EllipsesRenderer(Size imageSize) {

}

void EllipsesRenderer::render(Mat &canvas, const std::vector<Ellipse> &ellipses)
{
    for (Ellipse e : ellipses)
    {
        cv::ellipse(canvas, e.position, e.size, 0, 0, 360, e.color, -1, CV_8UC3);
    }
}

