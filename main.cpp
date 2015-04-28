#include <stdio.h>
#include <iostream>
#include <opencv2/opencv.hpp>


#include "ObservableEvolutionStatus.hpp"
#include "Ellipse.hpp"
#include "EllipseEvaluator.hpp"
#include "EllipsesGenotypeInitializer.hpp"
#include "EllipsesCrossoverStrategy.hpp"
#include "EllipsesSelectionStrategy.hpp"
#include "EllipsesMutationStrategy.hpp"
#include "EllipsesRenderer.hpp"
using namespace std;
using namespace cv;

int main(int argc, char **argv) {

    string imgPath = "../res/mone.jpeg";

    namedWindow("Mona", WINDOW_AUTOSIZE );// Create a window for display.

    Size windowSize(600, 400);
    mt19937 prng(time(0));
    Mat benchmarkImage = imread(imgPath, -1);
    EllipseGenerator ellipseGenerator(prng, benchmarkImage.size(), 100);

    EvolvingProcess<Ellipse> evolvingProcess(100);
    evolvingProcess << new EllipsesGenotypeInitializer(ellipseGenerator)
        << new EllipseEvaluator(benchmarkImage)
        << new EllipsesSelectionStrategy()
        << new EllipsesCrossoverStrategy(prng)
        << new EllipsesMutationStrategy(ellipseGenerator);

    evolvingProcess.evolve([&benchmarkImage](ObservableEvolutionStatus<Ellipse>& status) -> bool {
        cout << status.getNumberOfGenerations() << std::endl;
        cout << status.getHighestFitness() << std::endl;

        if (status.getNumberOfGenerations() >= 10)
        {
            Mat image(benchmarkImage.size(), CV_8UC3);
            EllipsesRenderer::render(image, const_cast<Genotype<Ellipse>&>(status.getGenotypeWithBestFitness()).getGenes());
            imshow("Mona", image);
            imwrite("./result.jpg", image);
            waitKey(0);                                          // Wait for a keystroke in the window
            return true;
        }
    });

    return 0;
}