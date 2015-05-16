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
    if (argc < 5) {
        std::cout << "Usage: GeneticPainter [image path] [output directory]"
                     "[number of generations] [render frequency] [numberOfThreads = 1]" << std::endl;
        return 1;
    }
    string imgPath = argv[1];
    string outputDirectory = argv[2];
    int numberOfGenerations = std::atoi(argv[3]);
    int renderFrequency = std::atoi(argv[4]);
    int numberOfThreads = 1;
    if (argv[5]) {
        numberOfThreads = std::atoi(argv[5]);
    }

    namedWindow("Mona", WINDOW_AUTOSIZE);// Create a window for display.

    mt19937 prng(time(0));
    Mat benchmarkImage = imread(imgPath, -1);
    EllipseGenerator ellipseGenerator(prng, benchmarkImage.size(), 100);
    EllipsesRenderer ellipsesRenderer;

    EvolvingProcess<EllipsesGenotype::Type> evolvingProcess(100, numberOfThreads);
    evolvingProcess << new EllipsesGenotypeInitializer(ellipseGenerator)
        << new EllipsesEvaluator(benchmarkImage, ellipsesRenderer)
        << new EllipsesEliminationStrategy()
        << new EllipsesCrossoverOperator(prng)
        << new EllipsesBreedingOperator(prng)
        << new EllipsesMutationStrategy(ellipseGenerator);

    evolvingProcess.evolve([&](ObservableEvolutionStatus<EllipsesGenotype::Type>& status) -> bool {
        cout << status.getNumberOfGenerations() << std::endl;
        cout << status.getHighestFitness() << std::endl;

        if (status.getNumberOfGenerations() % renderFrequency == 0) {
            Mat image(benchmarkImage.size(), CV_8UC3);
            ellipsesRenderer.render(image, status.getGenotypeWithBestFitness());
            std::time_t timestamp = std::time(nullptr);
            char* result = std::asctime(std::localtime(&timestamp));
            std::stringstream filename; //{"./result" + result + ".jpg"};
            filename << outputDirectory << "/" << "result" << timestamp << ".jpg";
            imwrite(filename.str(), image);
        }
        return status.getNumberOfGenerations() >= numberOfGenerations;
    });

    return 0;
}