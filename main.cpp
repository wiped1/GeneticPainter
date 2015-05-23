#include <stdio.h>
#include <iostream>
#include <opencv2/opencv.hpp>

//#define GALL_USE_TIMER
#include "ObservableEvolutionStatus.hpp"
#include "Ellipse.hpp"
#include "EllipsesEvaluator.hpp"
#include "EllipsesGenotypeInitializer.hpp"
#include "EllipsesCrossoverOperator.hpp"
#include "EllipsesEliminationStrategy.hpp"
#include "DefaultEliminationStrategy.hpp"
#include "EllipsesMutationStrategy.hpp"
#include "EllipsesRenderer.hpp"
#include "EvolvingEnvironment.hpp"

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

    EvolvingEnvironmentProvider::getInstance().populationSize = 100;
    EvolvingEnvironmentProvider::getInstance().genesCount = 50;
    EvolvingEnvironmentProvider::getInstance().numberOfThreads = numberOfThreads;
    EvolvingEnvironmentProvider::getInstance().targetGenerationsCount = numberOfGenerations;
    EvolvingEnvironmentProvider::getInstance().parentsPerChild = 5;

    mt19937 prng(time(0));
    Mat benchmarkImage = imread(imgPath, -1);
    EllipseGenerator ellipseGenerator(prng, benchmarkImage.size(), 5, 100, 0.8, 1.2);
    EllipsesRenderer ellipsesRenderer;
    ImageComparator imageComparator;

    Mat image(benchmarkImage.size(), CV_8UC3);
    namedWindow("Result", WINDOW_AUTOSIZE);// Create a window for display.
    cv::imshow("Benchmark image", benchmarkImage);
    cv::waitKey(1);

    EvolvingProcess<EllipsesGenotype::Type> evolvingProcess;
    evolvingProcess << new EllipsesGenotypeInitializer(ellipseGenerator)
        << new EllipsesEvaluator(benchmarkImage, ellipsesRenderer, imageComparator)
        << new DefaultEliminationStrategy<EllipsesGenotype::Type>
        << new EllipsesCrossoverOperator(prng)
        << new EllipsesBreedingOperator(prng)
        << new EllipsesMutationStrategy(ellipseGenerator, prng);

    evolvingProcess.evolve([&](ObservableEvolutionStatus<EllipsesGenotype::Type>& status) -> bool {

        cout << status.getNumberOfGenerations() << std::endl;
        cout << status.getHighestFitness() << std::endl;

        ellipsesRenderer.render(image, status.getGenotypeWithBestFitness());
//        cv::cvtColor(image, image, CV_BGR2RGB);
        cv::imshow("Result", image);
        cv::waitKey(1);


        if (status.getNumberOfGenerations() % renderFrequency == 0) {
            std::time_t timestamp = std::time(nullptr);
            char* result = std::asctime(std::localtime(&timestamp));
            std::stringstream filename; //{"./result" + result + ".jpg"};
            filename << outputDirectory << "/" << "result" << timestamp << ".jpg";
            imwrite(filename.str(), image);
        }

        return status.getNumberOfGenerations() >= EvolvingEnvironmentProvider::getInstance().targetGenerationsCount;
    });

    return 0;
}
