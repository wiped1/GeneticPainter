//
// Created by Maciej Komorowski on 20.05.15.
//

#include "ImageComparator.hpp"


double ImageComparator::compareHistograms(MatND &lhs, MatND &rhs)
{
    return cv::compareHist(lhs, rhs, 0);
}

void ImageComparator::calculateHistogram(MatND &histogram, const Mat &imageHsv) const
{
    calcHist(&imageHsv, 1, histChannels, Mat(), histogram, 3, histSize, (const float **) histRanges, true, false);
}

double ImageComparator::compareByPixels(const Mat &lhsHsv, const Mat &rhsHsv) const
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
        }
    }

    return differenceSum / (lhsHsv.cols * lhsHsv.rows * 23409000.0); // 0.0 to 1.0
}