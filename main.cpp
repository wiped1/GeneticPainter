#include <fstream>
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
#include "EvolvingStatusSerializer.hpp"

using namespace std;
using namespace cv;
using namespace gall;

int main(int argc, char **argv) {
    if (argc < 5) {
        std::cout << "Usage: GeneticPainter [image path] [output directory]"
                     "[number of generations] [render frequency] [number of threads = 1] [show image = 1]" << std::endl;
        return 1;
    }
    string imgPath = argv[1];
    string outputDirectory = argv[2];
    int numberOfGenerations = std::atoi(argv[3]);
    int renderFrequency = std::atoi(argv[4]);
    int numberOfThreads = 1;
    int showImage = 1;

    if (argv[5])
        numberOfThreads = std::atoi(argv[5]);
    if (argv[6])
        showImage = std::atoi(argv[6]);

    EvolvingEnvironmentProvider::getInstance().populationSize = 50;
    EvolvingEnvironmentProvider::getInstance().genesCount = 150;
    EvolvingEnvironmentProvider::getInstance().numberOfThreads = numberOfThreads;
    EvolvingEnvironmentProvider::getInstance().targetGenerationsCount = numberOfGenerations;
    EvolvingEnvironmentProvider::getInstance().parentsPerChild = 5;

    std::mt19937 prng(time(0));
    cv::Mat benchmarkImage = imread(imgPath);
    cv::Scalar averageColor = cv::mean(benchmarkImage, Mat());
    EllipseGenerator ellipseGenerator(prng, benchmarkImage.size(), 5, 100, 0.8, 1.2);
    EllipsesRenderer ellipsesRenderer(averageColor);
    ImageComparator imageComparator;

    if (showImage > 0) {
        namedWindow("Result", WINDOW_AUTOSIZE);// Create a window for display.
        cv::imshow("Benchmark image", benchmarkImage);
        cv::waitKey(1);
    }

    EvolvingProcess<EllipsesGenotype::Type, std::mt19937> evolvingProcess(prng);
    evolvingProcess << new EllipsesGenotypeInitializer(ellipseGenerator)
        << new EllipsesEvaluator(benchmarkImage, ellipsesRenderer, imageComparator)
        << new DefaultEliminationStrategy<EllipsesGenotype::Type>
        << new EllipsesCrossoverOperator(prng)
        << new EllipsesBreedingOperator(prng)
        << new EllipsesMutationStrategy(ellipseGenerator, prng, 5);
    evolvingProcess.setCrossoverProbability(0.5);
    evolvingProcess.evolve([&](ObservableEvolutionStatus<EllipsesGenotype::Type>& status) -> bool {

        cv::Mat image(benchmarkImage.size(), CV_8UC3, Scalar(0));

        std::cout << status.getNumberOfGenerations() << std::endl;
        std::cout << status.getHighestFitness() << std::endl;
        std::cout << "Num. of genes: " <<
                status.getGenotypeWithBestFitness().asCollection().size() << std::endl;

        ellipsesRenderer.render(image, status.getGenotypeWithBestFitness());

        if (showImage > 0) {
            cv::imshow("Result", image);
            cv::waitKey(1);
        }

        if (status.getNumberOfGenerations() % renderFrequency == 0)
        {
            std::time_t timestamp = std::time(nullptr);
            char* result = std::asctime(std::localtime(&timestamp));
            std::stringstream filename, imageFile, jsonFile; //{"./result" + result + ".jpg"};

            filename << outputDirectory << "/" << "result" << timestamp;
            imageFile << filename.str() << ".png";
            jsonFile << filename.str() << ".json";

            cv::imwrite(imageFile.str(), image);
            std::ofstream jsonOut(jsonFile.str());
            jsonOut << EvolvingStatusSerializer::toJson(status);
            jsonOut.close();
        }

        return status.getNumberOfGenerations() >= EvolvingEnvironmentProvider::getInstance().targetGenerationsCount;
    });

    return 0;
}
