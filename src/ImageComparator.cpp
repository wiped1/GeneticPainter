//
// Created by Maciej Komorowski on 20.05.15.
//

#include "ImageComparator.hpp"


double ImageComparator::compareHistograms(MatND &lhs, MatND &rhs)
{
//    double fitness = 0;
//    for (int cols = 0; cols < lhs.cols; cols++) {
//        for (int rows = 0; rows < lhs.rows; rows++) {
//            Scalar lhsColor = lhs.at<Scalar>(cols, rows);
//            Scalar rhsColor = rhs.at<Scalar>(cols, rows);
//
//            double deltaGreen = lhsColor[0] - rhsColor[0];
//            double deltaBlue  = lhsColor[1] - rhsColor[1];
//            double deltaRed   = lhsColor[2] - rhsColor[2];
//
//            double pixelFitness =
//                    std::pow(deltaGreen, 2) +
//                    std::pow(deltaBlue, 2) +
//                    std::pow(deltaRed, 2);
//
//            fitness += pixelFitness;
//        }
//    }
//    return 1 - fitness;
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

    double similaritySum = 0.0;
    double hueSimilarity, saturationSimilarity, valueSimilarity;

    for (int i = 0; i < lhsHsv.cols; i++)
    {
        for (int j = 0; j < lhsHsv.rows; j++)
        {
            lhsPx = lhsHsv.at<Vec3b>(j, i);
            rhsPx = rhsHsv.at<Vec3b>(j, i);

            hueSimilarity = std::abs(std::abs(rhsPx.val[0] - lhsPx.val[0]) - 127.0) / 127.0;
            saturationSimilarity = (255 - std::abs(rhsPx.val[1] - lhsPx[1])) / 255.0;
            valueSimilarity = (255 - std::abs(rhsPx.val[2] - lhsPx[2])) / 255.0;

            similaritySum += hueSimilarity * saturationSimilarity * valueSimilarity * valueSimilarity;
        }
    }
    double returnValue = similaritySum / (lhsHsv.cols * lhsHsv.rows);
    return returnValue; // 0.0 to 1.0
}