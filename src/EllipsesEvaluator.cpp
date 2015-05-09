#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include "EllipsesEvaluator.hpp"
#include "EllipsesRenderer.hpp"
#include "GeneticAlgorithm.hpp"

using namespace cv;
using EllipsesGenotype = Genotype<Ellipse, std::set>;

EllipsesEvaluator::EllipsesEvaluator(const Mat &benchmarkImage, const EllipsesRenderer &ellipsesRenderer) : benchmarkImage(&benchmarkImage), ellipsesRenderer(ellipsesRenderer)
{
    cvtColor(benchmarkImage, benchmarkImageHsv, COLOR_BGR2HSV);
    calculateHistogram(benchmarkImageHistogram, benchmarkImageHsv);
}

double EllipsesEvaluator::evaluate(const EllipsesGenotype &genotype) const
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

double EllipsesEvaluator::benchmark(Mat &image) const
{
    Mat imageHsv;
    Mat imageHistogram;

    cvtColor(image, imageHsv, COLOR_BGR2HSV);
    calculateHistogram(imageHistogram, imageHsv);

    return compareHist(benchmarkImageHistogram, imageHistogram, 0);
}