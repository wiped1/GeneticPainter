//
// Created by Maciej Komorowski on 24.05.15.
//

#pragma once

#include "json.hpp"
#include "EllipsesGenotype.hpp"
#include "ObservableEvolutionStatus.hpp"

using json = nlohmann::json;

struct EvolvingStatusSerializer
{
public:
    static std::string toJson(ObservableEvolutionStatus<EllipsesGenotype::Type>& status)
    {
        json jsonGenotype;

        std::for_each(
                status.getGenotypeWithBestFitness().cbegin(),
                status.getGenotypeWithBestFitness().cend(),
                [&](auto &ellipse) -> void
                {
                    jsonGenotype.push_back(
                            {
                                    {"position", {ellipse.position.x, ellipse.position.y}},
                                    {"size", {ellipse.size.width, ellipse.size.height}},
                                    {"color", {
                                                      static_cast<int>(ellipse.color[0]),
                                                      static_cast<int>(ellipse.color[1]),
                                                      static_cast<int>(ellipse.color[2]),
                                                      static_cast<float>(ellipse.color[3])}
                                    }
                            });
                });

        json statusJson = {
                {"populationSize",status.getPopulationSize()},
                {"generationNumber", status.getNumberOfGenerations()},
                {"highestFitness", status.getHighestFitness()},
                {"bestGenotype", jsonGenotype}
        };



        return statusJson.dump();
    }
};