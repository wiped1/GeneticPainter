#pragma once

#include <random>
#include <opencv2/core/core.hpp>
#include "Ellipse.hpp"
#include "GeneticAlgorithm.hpp"

using namespace std;
using namespace cv;

class EllipseEvaluator : public Evaluator<Ellipse> {

private:

    const Mat *_benchmarkImage;
    Mat _benchmarkImageHsv;
    MatND _benchmarkImageHistogram;

    const int _histSize[2] = {50, 60};
    const float _histSaturationRange[2] = { 0, 256};
    const float _histHueRange[2] = { 0, 180};
    const float* _histRanges[2] = {_histSaturationRange, _histHueRange};
    const int _histChannels[2] =  {0, 1};

    double benchmark(Mat &image) const;
//    void render(Mat &image, Genotype<Ellipse> &ellipse) const;
    void calculateImageHistogram(const Mat &imageHsv, MatND &histogram) const;

public:

    EllipseEvaluator(const Mat &benchmarkImage);
    virtual double evaluate(Genotype<Ellipse> &ellipse) const;

};

