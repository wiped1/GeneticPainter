#include <opencv2/highgui/highgui.hpp>
#include "opencv2/imgproc/imgproc.hpp"
#include "GeneticAlgorithm.hpp"
#include "EllipseEvaluator.hpp"

using namespace cv;

EllipseEvaluator::EllipseEvaluator(Mat benchmark_image)
{
    _benchmark_image = benchmark_image;

    cvtColor(benchmark_image, _benchmark_image_hsv, COLOR_BGR2HSV);
    _calculateImageHistogram(_benchmark_image_hsv, _benchmark_image_histogram);
}

double EllipseEvaluator::evaluate(Genotype<Ellipse> &ellipse) const
{
    Mat image(Size(600, 400), CV_8UC3);
    _render(image, ellipse);
    return _benchmark(image);
}

void EllipseEvaluator::_calculateImageHistogram(const Mat &image_hsv, Mat &histogram) const
{
    calcHist(&image_hsv, 1, _hist_channels, Mat(), histogram, 2, _hist_size, (const float **) _hist_ranges, true, false);
    normalize(histogram, histogram, 0, 1, NORM_MINMAX, -1, Mat());
}

void EllipseEvaluator::_render(Mat &image, Genotype<Ellipse> &ellipse) const
{
    for (Ellipse e : ellipse.getGenes())
    {
        cv::ellipse(image,
                e.position,
                e.size,
                0,
                0,
                360,
                e.color,
                -1,
                CV_8UC3);
    }
}

double EllipseEvaluator::_benchmark(Mat &image) const
{
    Mat image_hsv;
    Mat image_histogram;

    cvtColor(image, image_hsv, COLOR_BGR2HSV);
    _calculateImageHistogram(image_hsv, image_histogram);

    return compareHist(_benchmark_image_histogram, image_histogram, 0);
}