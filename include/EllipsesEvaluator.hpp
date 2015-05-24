#pragma once

#include <random>
#include <opencv2/core/core.hpp>
#include "Ellipse.hpp"
#include "Genotype.hpp"
#include "EllipsesRenderer.hpp"
#include "Evaluator.hpp"
#include "EllipsesGenotype.hpp"
#include "ImageComparator.hpp"

using namespace std;
using namespace cv;
using namespace gall;

class EllipsesEvaluator : public Evaluator<EllipsesGenotype::Type>
{

private:

    ImageComparator imageComparator;
    EllipsesRenderer ellipsesRenderer;

    const Mat *benchmarkImage;
    Mat benchmarkImageHsv;
    MatND benchmarkImageHistogram;

    const int histSize[3] = {32, 60, 8};
    const float histSaturationRange[2] = {0, 256};
    const float histHueRange[2] = {0, 180};
    const float histValueRange[2] = {0, 100};

    const float* histRanges[3] = {histSaturationRange, histHueRange, histValueRange};
    const int histChannels[3] =  {0, 1, 2};

public:

    EllipsesEvaluator(const Mat &benchmarkImage, const EllipsesRenderer &ellipsesRenderer, const ImageComparator &imageComparator);
    virtual double evaluate(const EllipsesGenotype::Type &ellipse) const;

};

