#include <stdio.h>
#include <iostream>
#include <opencv2/opencv.hpp>
#include "EllipseEvaluator.hpp"

#include "Ellipse.hpp"
#include "EllipseInitializer.hpp"
#include "EllipsesCrossoverStrategy.hpp"

using namespace std;
using namespace cv;

int main(int argc, char **argv) {
        string imgPath = "../res/mona.jpg";

        Size windowSize(600, 400);
        mt19937 prng(time(0));

        Mat benchmarkImage = imread(imgPath, 1);
    //    namedWindow("Display Image", WINDOW_AUTOSIZE);

        EllipseInitializer ellipseInitializer(prng, windowSize, 100);
        EllipseEvaluator evaluator(benchmarkImage);

        std::vector<Genotype<Ellipse>> genotypes;

        PopulationInitializer<Ellipse> populationInitializer(ellipseInitializer, 100);
        Population<Ellipse> ellipsePopulation(populationInitializer);
        SelectionStrategy<Ellipse> selectionStrategy(evaluator);
        EllipsesCrossoverStrategy crossoverStrategy(prng);

        cout << ellipsePopulation.getGenotypes().size() << endl;

        while (true) {

            try
            {
                selectionStrategy.eliminate(ellipsePopulation);

                cout << evaluator.evaluate(ellipsePopulation.getGenotypes().front()) << endl;

                crossoverStrategy.cross(ellipsePopulation);

                cout << ellipsePopulation.getGenotypes().size() << endl;
            }
            catch (const exception& e)
            {

                cout << e.what();
            }
        }


    //    int thickness = 2;
    //    int lineType = 8;

//        cout << evaluator.evaluate(ellipsePopulation.getGenotypes().front());

    //    for (int k=0; k < 100000; k++)
    //    {
    //        cout << evaluator.evaluate(ellipses);
    //
    //        if (0 == k%10)
    //        {
    //            imshow("Display Image", benchmarkImage);
    //        }
    //    }



        return 0;
}