#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include "EllipseEvaluator.hpp"
#include "EllipsesRenderer.hpp"
#include "GeneticAlgorithm.hpp"

using namespace cv;

EllipseEvaluator::EllipseEvaluator(const Mat &benchmarkImage) : _benchmarkImage(&benchmarkImage)
{
    cvtColor(*_benchmarkImage, _benchmarkImageHsv, COLOR_BGR2HSV);
    calculateImageHistogram(_benchmarkImageHsv, _benchmarkImageHistogram);
}

double EllipseEvaluator::evaluate(Genotype<Ellipse> &genotype) const
{
    Mat candidateImage(_benchmarkImage->size(), CV_8UC3);
    EllipsesRenderer::render(candidateImage, genotype.getGenes());
    return benchmark(candidateImage);
}

void EllipseEvaluator::calculateImageHistogram(const Mat &imageHsv, Mat &histogram) const
{
    calcHist(&imageHsv, 1, _histChannels, Mat(), histogram, 2, _histSize, (const float **) _histRanges, true, false);
    normalize(histogram, histogram, 0, 1, NORM_MINMAX, -1, Mat());
}
//
//void EllipseEvaluator::render(Mat &image, Genotype<Ellipse> &ellipse) const
//{
//    for (Ellipse e : ellipse.getGenes())
//    {
//        cv::ellipse(image, e.position, e.size, 0, 0, 360, e.color, -1, CV_8UC3);
//    }
//}

double EllipseEvaluator::benchmark(Mat &image) const
{
    Mat imageHsv;
    Mat imageHistogram;

    cvtColor(image, imageHsv, COLOR_BGR2HSV);
    calculateImageHistogram(imageHsv, imageHistogram);

    return compareHist(_benchmarkImageHistogram, imageHistogram, 0);
}