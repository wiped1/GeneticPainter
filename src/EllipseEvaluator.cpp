#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include "opencv2/imgproc/imgproc.hpp"
#include "GeneticAlgorithm.hpp"
#include "EllipseEvaluator.hpp"

using namespace cv;

EllipseEvaluator::EllipseEvaluator(Mat benchmarkImage)
{
    benchmarkImage = benchmarkImage;

    cvtColor(benchmarkImage, benchmarkImageHsv, COLOR_BGR2HSV);
    calculateImageHistogram(benchmarkImageHsv, benchmarkImageHistogram);
}

double EllipseEvaluator::evaluate(Genotype<Ellipse> &ellipse) const
{
    Mat image(Size(600, 400), CV_8UC3);
    render(image, ellipse);
    return benchmark(image);
}

void EllipseEvaluator::calculateImageHistogram(const Mat &image_hsv, Mat &histogram) const
{
    calcHist(&image_hsv, 1, histChannels, Mat(), histogram, 2, histSize, (const float **) histRanges, true, false);
    normalize(histogram, histogram, 0, 1, NORM_MINMAX, -1, Mat());
}

void EllipseEvaluator::render(Mat &image, Genotype<Ellipse> &ellipse) const
{
    for (Ellipse e : ellipse.getGenes())
    {
        cv::ellipse(image, e.position, e.size, 0, 0, 360, e.color, -1, CV_8UC3);
    }
}

double EllipseEvaluator::benchmark(Mat &image) const
{
    Mat image_hsv;
    Mat image_histogram;

    cvtColor(image, image_hsv, COLOR_BGR2HSV);
    calculateImageHistogram(image_hsv, image_histogram);

    return compareHist(benchmarkImageHistogram, image_histogram, 0);
}