#include <stdio.h>
#include <iostream>
#include <opencv2/opencv.hpp>
#include "EllipseEvaluator.hpp"

#include "Ellipse.hpp"
#include "EllipseInitializer.hpp"
#include "EllipsesCrossoverStrategy.hpp"
#include "EllipseSelectionStrategy.hpp"
#include "EllipsesMutationStrategy.hpp"

using namespace std;
using namespace cv;

int main(int argc, char **argv) {
    string imgPath = "../res/mona.jpg";

    Size windowSize(600, 400);
    mt19937 prng(time(0));

    Mat benchmarkImage = imread(imgPath, 1);


    EvolvingProcess<Ellipse> evolvingProcess(100);
    evolvingProcess << new EllipseInitializer(prng, windowSize, 100)
    << new EllipseEvaluator(benchmarkImage)
    << new EllipsesCrossoverStrategy(prng)
    << new EllipsesMutationStrategy()
    << new EllipseSelectionStrategy();

    evolvingProcess.evolve([](const Population<Ellipse>& pop, unsigned int generationNumber) -> bool {
        return generationNumber >= 10;
    });

    return 0;
}