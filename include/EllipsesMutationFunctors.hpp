//
// Created by Mckomo on 23.05.15.
//

#pragma once

#include <random>
#include "MutationFunctor.hpp"
#include "EllipsesGenotype.hpp"
#include "EllipseGenerator.hpp"
#include "EvolvingEnvironment.hpp"

struct AlterSizeFunctor : public MutationFunctor<EllipsesGenotype::Collection>
{
    const EllipseGenerator *ellipseGenerator;
    const std::unique_ptr<std::uniform_real_distribution<double>> rd;
    std::mt19937* prng;

    AlterSizeFunctor(const EllipseGenerator &ellipseGenerator, std::mt19937 &prng);
    void mutate(EllipsesGenotype::Collection& genes) const;
};

struct MakeSmallerFunctor : public MutationFunctor<EllipsesGenotype::Collection> {
    const EllipseGenerator *ellipseGenerator;
    const std::unique_ptr<std::uniform_real_distribution<double>> rd;
    std::mt19937* prng;

    MakeSmallerFunctor(const EllipseGenerator &ellipseGenerator, std::mt19937 &prng);
    void mutate(EllipsesGenotype::Collection& genes) const;
};

struct MakeBiggerFunctor : public MutationFunctor<EllipsesGenotype::Collection>
{
    const EllipseGenerator *ellipseGenerator;
    const std::unique_ptr<std::uniform_real_distribution<double>> rd;
    std::mt19937* prng;

    MakeBiggerFunctor(const EllipseGenerator &ellipseGenerator, std::mt19937 &prng);
    void mutate(EllipsesGenotype::Collection& genes) const;
};

struct AlterColorByRatioFunctor : public MutationFunctor<EllipsesGenotype::Collection>
{
    const std::unique_ptr<std::uniform_real_distribution<double>> rd;
    std::mt19937* prng;

    AlterColorByRatioFunctor(std::mt19937& prng);
    void mutate(EllipsesGenotype::Collection& genes) const;
};

struct AlterAlphaByRatioFunctor : public MutationFunctor<EllipsesGenotype::Collection>
{
    const std::unique_ptr<std::uniform_real_distribution<double>> rd;
    std::mt19937* prng;

    AlterAlphaByRatioFunctor(std::mt19937& prng);
    void mutate(EllipsesGenotype::Collection& genes) const;
};

struct AlterColorBySumFunctor : public MutationFunctor<EllipsesGenotype::Collection>
{
    std::mt19937* prng;
    const std::unique_ptr<std::uniform_real_distribution<double>> rd;

    AlterColorBySumFunctor(std::mt19937& prng);
    void mutate(EllipsesGenotype::Collection& genes) const;
};

struct AlterPositionFunctor : public MutationFunctor<EllipsesGenotype::Collection>
{
    const EllipseGenerator *ellipseGenerator;
    std::mt19937* prng;
    const std::unique_ptr<std::uniform_real_distribution<double>> rd;

    AlterPositionFunctor(const EllipseGenerator &ellipseGenerator, std::mt19937 &prng);
    void mutate(EllipsesGenotype::Collection& genes) const;
};

struct SwapWithRandomFunctor : MutationFunctor<EllipsesGenotype::Collection>
{
    const EllipseGenerator *ellipseGenerator;

    SwapWithRandomFunctor(const EllipseGenerator &ellipseGenerator);
    void mutate(EllipsesGenotype::Collection& genes) const;
};

struct AddNewEllipseFunctor : MutationFunctor<EllipsesGenotype::Collection>
{
    const EllipseGenerator *ellipseGenerator;

    AddNewEllipseFunctor(const EllipseGenerator& ellipseGenerator);
    void mutate(EllipsesGenotype::Collection& genes) const;
};

struct CopyNewEllipseFunctor : MutationFunctor<EllipsesGenotype::Collection>
{
    const EllipseGenerator *ellipseGenerator;
    std::mt19937* prng;
    const std::unique_ptr<std::uniform_real_distribution<double>> rd;

    CopyNewEllipseFunctor(const EllipseGenerator& ellipseGenerator, std::mt19937& prng);
    void mutate(EllipsesGenotype::Collection& genes) const;
};

struct RemoveFromBackFunctor : MutationFunctor<EllipsesGenotype::Collection>
{
    void mutate(EllipsesGenotype::Collection& genes) const;
};

struct RemoveFromFrontFunctor : MutationFunctor<EllipsesGenotype::Collection> {
    void mutate(EllipsesGenotype::Collection& genes) const;
};

struct RemoveHalfFunctor : MutationFunctor<EllipsesGenotype::Collection>
{
    void mutate(EllipsesGenotype::Collection& genes) const;
};

struct RemoveRandomFunctor : MutationFunctor<EllipsesGenotype::Collection>
{
    std::mt19937* prng;

    RemoveRandomFunctor(std::mt19937 &prng);
    void mutate(EllipsesGenotype::Collection& genes) const;
};
