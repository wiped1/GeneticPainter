#include <iostream>
#include <opencv2/opencv.hpp>
#include "Ellipse.hpp"
#include "EllipsesRenderer.hpp"
#include "EllipsesGenotype.hpp"
#include "ImageComparator.hpp"

using namespace std;
using namespace cv;
using namespace gall;

int main(int argc, char **argv)
{
    cv::namedWindow("Ellipse");
    ImageComparator imgCmp;

    Mat benchmarkImage = imread("../res/blue.jpg");
    cvtColor(benchmarkImage, benchmarkImage, CV_BGR2RGB);
    Size size(benchmarkImage.cols, benchmarkImage.rows);

    Mat image(size, CV_8UC3, Scalar(0));

    cv::rectangle(image, Point(0,0), Point(400, 400), Scalar(255, 0, 0), CV_FILLED);

    EllipsesRenderer renderer;
    EllipsesGenotype::Collection ellipses;
    Ellipse ellipse(Point(200, 200), Size(600, 600), Scalar(255, 0, 0));
    ellipses.push_back(ellipse);

    renderer.render(image, EllipsesGenotype::Type(ellipses));


    Vec3b px = image.at<Vec3b>(25, 25);

//    cout << (double) px.val[0] << (double)  px.val[1] << (double) px.val[2] << endl;


    px = benchmarkImage.at<Vec3b>(25, 25);

//    cout << (double) px.val[0] << (double)  px.val[1] << (double) px.val[2];

    std::cout << imgCmp.compareByPixels(benchmarkImage, image);
    cv::rectangle(image, Point(0,0), Point(400, 400), Scalar(0, 0, 255), CV_FILLED);


    imshow("Ellipse", image);
    waitKey(0);
}
