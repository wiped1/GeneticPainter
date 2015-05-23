//
// Created by Maciej Komorowski on 20.05.15.
//

#pragma once

#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <cmath>

using namespace cv;

class ImageComparator
{
private:

    const int histSize[3] = {60, 32, 32};
    const float histSaturationRange[2] = {0, 256};
    const float histHueRange[2] = {0, 180};
    const float histValueRange[2] = {0, 256};
    const float* histRanges[3] = {histHueRange, histSaturationRange, histValueRange};
    const int histChannels[3] =  {0, 1, 2};

public:

    double compareByPixels(const Mat &lhsHsv, const Mat &rhsHsv) const;
    double compareHistograms(MatND &lhs, MatND &rhs);
    void calculateHistogram(MatND &histogram, const Mat &imageHsv) const;
};
