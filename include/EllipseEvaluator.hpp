#pragma once

#include <random>
#include <opencv2/core/core.hpp>
#include "Ellipse.hpp"
#include "GeneticAlgorithm.hpp"

using namespace std;
using namespace cv;

class EllipseEvaluator : public Evaluator<Ellipse> {

    Mat _benchmark_image;
    Mat _benchmark_image_hsv;
    MatND _benchmark_image_histogram;

    const int _hist_size[2] = {50, 60};
    const float _hist_saturation_range[2] = { 0, 256};
    const float _hist_hue_range[2] = { 0, 180};
    const float* _hist_ranges[2] = {_hist_saturation_range, _hist_hue_range};
    const int  _hist_channels[2] =  {0, 1};

    double _benchmark(Mat &image) const;
    void _render(Mat &image, Genotype<Ellipse> &ellipse) const;
    void _calculateImageHistogram(const Mat &image, MatND &histogram) const;

public:

    EllipseEvaluator(Mat benchmark_image);
    virtual double evaluate(Genotype<Ellipse> &ellipse) const;

};

