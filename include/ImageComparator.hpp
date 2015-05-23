//
// Created by Maciej Komorowski on 20.05.15.
//

#pragma once

#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <cmath>

using namespace cv;

class ImageComparator {

private:

    const int histSize[3] = {60, 32, 32};
    const float histSaturationRange[2] = {0, 256};
    const float histHueRange[2] = {0, 180};
    const float histValueRange[2] = {0, 256};

    const float* histRanges[3] = {histHueRange, histSaturationRange, histValueRange};
    const int histChannels[3] =  {0, 1, 2};

public:

    double compareByPixels(const Mat &lhsHsv, const Mat &rhsHsv) const
    {
        if (lhsHsv.rows != rhsHsv.rows || lhsHsv.cols != rhsHsv.cols)
            throw std::invalid_argument("Images must have same size");

        Vec3b lhsPx;
        Vec3b rhsPx;

        double differenceSum = 0.0;
        int hueDiff, saturationDiff, valueDiff;

        for (int i = 0; i < lhsHsv.cols; i++)
        {
            for (int j = 0; j < lhsHsv.rows; j++)
            {
                lhsPx = lhsHsv.at<Vec3b>(j, i);
                rhsPx = rhsHsv.at<Vec3b>(j, i);

                hueDiff = (90 - std::abs(rhsPx.val[0] - lhsPx.val[0]) % 91) * 4; // 0 to 360
                saturationDiff = 255 - std::abs(rhsPx.val[1] - lhsPx[1]); // 0 to 255
                valueDiff = 255 - std::abs(rhsPx.val[2] - lhsPx[2]); // 0 to 255

                differenceSum += hueDiff * saturationDiff * valueDiff;

//                std::cout << "Hue: " << (int) rhsPx.val[0] << ", " << (int) lhsPx.val[0] << std::endl;
//                std::cout << "Saturation: " << (int) rhsPx.val[1] << ", " << (int) lhsPx.val[1] << std::endl;
//                std::cout << hueDiff * saturationDiff * valueDiff / 23409000.0 << std::endl;
//                std::cout << hueDiff << ", " << saturationDiff << ", " << valueDiff << std::endl;

            }
        }

        return differenceSum / (lhsHsv.cols * lhsHsv.rows * 23409000.0); // 0.0 to 1.0
    }

    double compareHistograms(MatND &lhs, MatND &rhs)
    {
        return cv::compareHist(lhs, rhs, 0);
    }

    void calculateHistogram(MatND &histogram, const Mat &imageHsv) const;

};
