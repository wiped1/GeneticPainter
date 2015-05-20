#pragma once

#include <random>
#include <opencv2/core/core.hpp>
#include "Ellipse.hpp"
#include "Genotype.hpp"
#include "EllipsesRenderer.hpp"
#include "Evaluator.hpp"
#include "EllipsesGenotype.hpp"

using namespace std;
using namespace cv;
using namespace gall;

class EllipsesEvaluator : public Evaluator<EllipsesGenotype::Type> {

private:

    EllipsesRenderer ellipsesRenderer;
    const Mat *benchmarkImage;
    Mat benchmarkImageHsv;
    MatND benchmarkImageHistogram;

    const int histSize[2] = {50, 60};
    const float histSaturationRange[2] = { 0, 256};
    const float histHueRange[2] = { 0, 180};
    const float* histRanges[2] = {histSaturationRange, histHueRange};
    const int histChannels[2] =  {0, 1};

    double benchmark(const Mat &image) const;
    void calculateHistogram(MatND &histogram, const Mat &imageHsv) const;

public:

    EllipsesEvaluator(const Mat &benchmarkImage, const EllipsesRenderer &ellipsesRenderer);
    virtual double evaluate(const EllipsesGenotype::Type &ellipse) const;

};

