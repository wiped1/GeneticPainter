#include <stdio.h>
#include <iostream>
#include <opencv2/opencv.hpp>
#include <ImageSimilarityEvaluator.h>

#include "Ellipse.h"
#include "EllipseCreator.h"

using namespace std;
using namespace cv;

int main(int argc, char **argv) {
    string imgPath = "../res/mona.jpg";

    Size windowSize(600, 400);
    mt19937 prng(time(0));

    Mat src_base = imread(imgPath, 1);

    int thickness = 2;
    int lineType = 8;

    EllipseCreator ellipse_generator(prng, windowSize, 100);

    Mat image(windowSize, CV_8UC3);

    for (int k=0; k < 100000; k++)
    {
        for (int i = 0; i < 200; i++)
        {
            Ellipse ellipse = ellipse_generator.generateRandom();

            cv::ellipse(image,
                    ellipse.position,
                    ellipse.size,
                    0,
                    0,
                    360,
                    ellipse.color,
                    -1,
                    CV_8UC3);
        }

        namedWindow("Display Image", WINDOW_AUTOSIZE);

        ImageSimilarityEvaluator evaluator(src_base);

        if (0 == k%100)
            cout <<  evaluator.evaluate(src_base) << endl;
    }

    waitKey(0);

    return 0;
}