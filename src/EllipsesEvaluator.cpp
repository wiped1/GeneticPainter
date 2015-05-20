#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include "EllipsesEvaluator.hpp"
#include "EllipsesRenderer.hpp"
#include "GeneticAlgorithm.hpp"
#include "math.h"

using namespace cv;

EllipsesEvaluator::EllipsesEvaluator(const Mat &benchmarkImage, const EllipsesRenderer &ellipsesRenderer) : benchmarkImage(&benchmarkImage), ellipsesRenderer(ellipsesRenderer)
{
    cvtColor(benchmarkImage, benchmarkImageHsv, COLOR_BGR2HSV);
    calculateHistogram(benchmarkImageHistogram, benchmarkImageHsv);
}

double EllipsesEvaluator::evaluate(const EllipsesGenotype::Type &genotype) const
{
    Mat candidateImage(benchmarkImage->size(), CV_8UC3);
    ellipsesRenderer.render(candidateImage, genotype);
    return benchmark(candidateImage);
}

void EllipsesEvaluator::calculateHistogram(MatND &histogram, const Mat &imageHsv) const
{
    calcHist(&imageHsv, 1, histChannels, Mat(), histogram, 2, histSize, (const float **) histRanges, true, false);
    normalize(histogram, histogram, 0, 1, NORM_MINMAX, -1, Mat());
}

double EllipsesEvaluator::benchmark(const Mat &image) const
{
    Mat imageHsv;
    Mat imageHistogram;

    cvtColor(image, imageHsv, CV_BGR2HSV);
    calculateHistogram(imageHistogram, imageHsv);

    // Calculate the L2 relative error between images.
    double errorL2 = norm(image, *benchmarkImage, CV_L2);
    // Convert to a reasonable scale, since L2 error is summed across all pixels of the image.
    double similarity = errorL2 / (double)( image.rows * image.cols );
//    return similarity;

    double histSimilarity = compareHist(benchmarkImageHistogram, imageHistogram, 0);

    return histSimilarity;
    return (similarity + histSimilarity) / 2;
}