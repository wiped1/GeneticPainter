#include <stdio.h>
#include <iostream>
#include <opencv2/opencv.hpp>

#include "EllipseEvaluator.hpp"
#include "EllipsesInitializer.hpp"
#include "EllipsesCrossoverStrategy.hpp"
#include "EllipsesSelectionStrategy.hpp"
#include "EllipsesMutationStrategy.hpp"

using namespace std;
using namespace cv;

int main(int argc, char **argv) {

    string imgPath = "../res/mona.jpg";

    Size windowSize(600, 400);
    mt19937 prng(time(0));
    Mat benchmarkImage = imread(imgPath, -1);

    EvolvingProcess<Ellipse> evolvingProcess(100);
    evolvingProcess << new EllipsesInitializer(prng, windowSize, 100)
        << new EllipseEvaluator(benchmarkImage)
        << new EllipsesSelectionStrategy()
        << new EllipsesCrossoverStrategy(prng)
        << new EllipsesMutationStrategy(prng);

    evolvingProcess.evolve([](const Population<Ellipse> &population, unsigned int generationNumber) -> bool {
        cout << generationNumber << std::endl;
        return generationNumber >= 10;
    });

    return 0;
}