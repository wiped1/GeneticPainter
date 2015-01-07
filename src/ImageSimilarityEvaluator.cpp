#include "opencv2/imgproc/imgproc.hpp"
#include "ImageSimilarityEvaluator.h"

ImageSimilarityEvaluator::ImageSimilarityEvaluator(Mat benchmark_image)
{
    _benchmark_image = benchmark_image;

    cvtColor(benchmark_image, _benchmark_image_hsv, COLOR_BGR2HSV);
    _calculateImageHistogram(_benchmark_image_hsv, _benchmark_image_histogram);
}

void ImageSimilarityEvaluator::_calculateImageHistogram(const Mat &image_hsv, MatND &histogram)
{
    calcHist(&image_hsv, 1, _hist_channels, Mat(), histogram, 2, _hist_size, _hist_ranges, true, false);
    normalize(histogram, histogram, 0, 1, NORM_MINMAX, -1, Mat());
}

double ImageSimilarityEvaluator::evaluate(Mat image)
{
    Mat image_hsv;
    MatND image_histogram;

    cvtColor(image, image_hsv, COLOR_BGR2HSV);
    _calculateImageHistogram(image_hsv, image_histogram);

    return compareHist(_benchmark_image_histogram, image_histogram, 0);
}


