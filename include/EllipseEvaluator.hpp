#pragma once

#include <random>
#include <opencv2/core/core.hpp>
#include "Ellipse.hpp"
#include "GeneticAlgorithm.hpp"

using namespace std;
using namespace cv;

class EllipseEvaluator : public Evaluator<Ellipse> {

    Mat benchmarkImage;
    Mat benchmarkImageHsv;
    MatND benchmarkImageHistogram;

    const int histSize[2] = {50, 60};
    const float histSaturationRange[2] = { 0, 256};
    const float histHueRange[2] = { 0, 180};
    const float* histRanges[2] = {histSaturationRange, histHueRange};
    const int  histChannels[2] =  {0, 1};

    double benchmark(Mat &image) const;
    void render(Mat &image, Genotype<Ellipse> &ellipse) const;
    void calculateImageHistogram(const Mat &image, MatND &histogram) const;

public:

    EllipseEvaluator(Mat benchmarkImage);
    virtual double evaluate(Genotype<Ellipse> &ellipse) const;

};

