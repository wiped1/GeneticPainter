#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include "EllipsesEvaluator.hpp"
#include "EllipsesRenderer.hpp"
#include "GeneticAlgorithm.hpp"
#include "math.h"

using namespace cv;

EllipsesEvaluator::EllipsesEvaluator(const Mat &benchmarkImage, const EllipsesRenderer &ellipsesRenderer, const ImageComparator &imageComparator)
        : benchmarkImage(&benchmarkImage), ellipsesRenderer(ellipsesRenderer), imageComparator(imageComparator)
{
    cvtColor(benchmarkImage, benchmarkImageHsv, COLOR_BGR2HSV);
    imageComparator.calculateHistogram(benchmarkImageHistogram, benchmarkImageHsv);
}

double EllipsesEvaluator::evaluate(const EllipsesGenotype::Type &genotype) const
{
    Mat candidateImage(benchmarkImage->size(), CV_8UC3, Scalar(0));
    ellipsesRenderer.render(candidateImage, genotype);
    cvtColor(candidateImage, candidateImage, COLOR_BGR2HSV);

    return imageComparator.compareByPixels(candidateImage, benchmarkImageHsv);
}