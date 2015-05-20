#include <iostream>
#include <opencv2/opencv.hpp>
#include "Ellipse.hpp"
#include "EllipsesRenderer.hpp"
#include "EllipsesGenotype.hpp"

using namespace std;
using namespace cv;
using namespace gall;

int main(int argc, char **argv)
{
    Size size(600, 400);
    cv::namedWindow("Ellipse");
    Mat image(size, CV_8UC3);

    EllipsesRenderer renderer;
    EllipsesGenotype::Collection ellipses;
    Ellipse ellipse(Size(300, 200), Point(300, 200), Scalar(255, 0, 0));

//    ellipse.color = new Scalar(255, 0, 0);
//    ellipse.position = new Point(300, 200);
//    ellipse.size = new Point(300, 200);

    ellipses.push_back(ellipse);

    renderer.render(image, EllipsesGenotype::Type(ellipses));
    Mat img(image.size(), CV_8UC3);
    cv::cvtColor(image, img, CV_RGB2BGR);
    imshow("Ellipse", img);
    waitKey(0);
}
