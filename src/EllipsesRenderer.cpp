//
// Created by Mckomo on 28.04.15.
//

#include "EllipsesRenderer.hpp"

void EllipsesRenderer::render(Mat &canvas, const EllipsesGenotype::Type &genotype) const
{
    std::for_each(genotype.cbegin(), genotype.cend(), [&canvas](auto &e){
        cv::ellipse(canvas, e.position, e.size, 0, 0, 360, e.color, -1, CV_8UC3);
    });
}

