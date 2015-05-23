//
// Created by Maciej Komorowski on 20.05.15.
//

#pragma once

#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include <cmath>

using namespace cv;

class ImageComparator {

private:

    const int histSize[2] = {50, 60};
    const float histSaturationRange[2] = {0, 256};
    const float histHueRange[2] = {0, 180};
    const float histValueRange[2] = {0, 100};

    const float* histRanges[3] = {histSaturationRange, histHueRange, histValueRange};
    const int histChannels[3] =  {0, 1, 2};

//    void calculateBGRHistograms(vector<SparseMat> &histograms, const Mat &image)
//    {
////        calcHist(&imageHsv, 1, histChannels, Mat(), histograms, 2, histSize, (const float **) histRanges, true, false);
////        normalize(histogram, histogram, 0, 1, NORM_MINMAX, 1, Mat());
//    }

public:

    double compareByPixels(const Mat &lhs, const Mat &rhs) const
    {
        if (lhs.rows != rhs.rows || lhs.cols != rhs.cols)
            throw std::invalid_argument("Images must have same size");

        Vec3b lhsPx;
        Vec3b rhsPx;

        double differenceSum = 0.0;

        for (int i = 0; i < lhs.cols; i++)
        {
            for (int j = 0; j < lhs.rows; j++)
            {
                lhsPx = lhs.at<Vec3b>(j, i);
                rhsPx = rhs.at<Vec3b>(j, i);

                int differenceProduct = 1;

                for(int k = 0; k < lhs.channels(); k++)
                {
                    differenceProduct *= abs(rhsPx.val[k] - lhsPx.val[k]) + 1;
                }

                differenceSum += std::pow(differenceProduct, 1.0/lhs.channels());
            }
        }

//        std::cout << differenceSum << std::endl;

        return (double) differenceSum / (double) (lhs.rows * lhs.cols * 255);

        // Calculate the L2 relative error between images.
        double errorL2 = norm(lhs, rhs, NORM_INF);
        // Convert to a reasonable scale, since L2 error is summed across all pixels of the image.
        return errorL2 / (double)(lhs.rows * lhs.cols);
    }

    double compareHistograms(Mat &lhs, Mat &rhs)
    {
        Mat lhsHsv;
        MatND lhsHistogram, rhsHistogram;
    }




};
