//
// Created by Mckomo on 28.04.15.
//

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "EllipsesRenderer.hpp"



void EllipsesRenderer::render(Mat &canvas, const EllipsesGenotype::Type &genotype) const
{
    canvas = backgroundColor;

    std::for_each(genotype.cbegin(), genotype.cend(), [&](auto &e)
    {
        cv::Mat overlay = canvas.clone();
        cv::ellipse(overlay, e.position, e.size, 0, 0, 360, e.color, -1, CV_AA);
        cv::addWeighted(overlay, e.color[3], canvas, 1.0 - e.color[3] , 0.0, canvas);
    });
}

EllipsesRenderer::EllipsesRenderer(Scalar &backgroundColor) : backgroundColor(backgroundColor)
{
    // Nothing to do
}
