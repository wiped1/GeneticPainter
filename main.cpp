#include <stdio.h>
#include <iostream>
#include <opencv2/opencv.hpp>


#include "ObservableEvolutionStatus.hpp"
#include "Ellipse.hpp"
#include "EllipsesEvaluator.hpp"
#include "EllipsesGenotypeInitializer.hpp"
#include "EllipsesCrossoverOperator.hpp"
#include "EllipsesEliminationStrategy.hpp"
#include "EllipsesMutationStrategy.hpp"
#include "EllipsesRenderer.hpp"

using namespace std;
using namespace cv;
using namespace gall;

int main(int argc, char **argv) {

    string imgPath = "../res/mone.jpeg";

    namedWindow("Mona", WINDOW_AUTOSIZE);// Create a window for display.

    mt19937 prng(time(0));
    Mat benchmarkImage = imread(imgPath, -1);
    EllipseGenerator ellipseGenerator(prng, benchmarkImage.size(), 100);
    EllipsesRenderer ellipsesRenderer;

    EvolvingProcess<EllipsesGenotype::Type> evolvingProcess(100);
    evolvingProcess << new EllipsesGenotypeInitializer(ellipseGenerator)
        << new EllipsesEvaluator(benchmarkImage, ellipsesRenderer)
        << new EllipsesEliminationStrategy()
        << new EllipsesCrossoverOperator(prng)
        << new EllipsesBreedingOperator(prng)
        << new EllipsesMutationStrategy(ellipseGenerator);

    evolvingProcess.evolve([&benchmarkImage, &ellipsesRenderer](ObservableEvolutionStatus<EllipsesGenotype::Type>& status) -> bool {
        cout << status.getNumberOfGenerations() << std::endl;
        cout << status.getHighestFitness() << std::endl;

        if (status.getNumberOfGenerations() >= 1000)
        {
            Mat image(benchmarkImage.size(), CV_8UC3);
            ellipsesRenderer.render(image, status.getGenotypeWithBestFitness());
            imshow("Mone", image);
            waitKey(0);                                          // Wait for a keystroke in the window
            return true;
        }
    });

    return 0;
}