//
// Created by Mckomo on 23.05.15.
//

#pragma once

#include <random>
#include "MutationFunctor.hpp"
#include "EllipsesGenotype.hpp"
#include "EllipseGenerator.hpp"
#include "EvolvingEnvironment.hpp"

struct AlterSizeFunctor : public MutationFunctor<EllipsesGenotype::Collection, Ellipse>
{
    const EllipseGenerator *ellipseGenerator;
    const std::unique_ptr<std::uniform_real_distribution<double>> rd;
    std::mt19937* prng;

    AlterSizeFunctor(const EllipseGenerator &ellipseGenerator, std::mt19937 &prng);
    void operator()(EllipsesGenotype::Collection& genotype, Ellipse& ellipse) const;
};

struct MakeSmallerFunctor : public MutationFunctor<EllipsesGenotype::Collection, Ellipse> {
    const EllipseGenerator *ellipseGenerator;
    const std::unique_ptr<std::uniform_real_distribution<double>> rd;
    std::mt19937* prng;

    MakeSmallerFunctor(const EllipseGenerator &ellipseGenerator, std::mt19937 &prng);
    void operator()(EllipsesGenotype::Collection& genotype, Ellipse& ellipse) const;
};

struct MakeBiggerFunctor : public MutationFunctor<EllipsesGenotype::Collection, Ellipse>
{
    const EllipseGenerator *ellipseGenerator;
    const std::unique_ptr<std::uniform_real_distribution<double>> rd;
    std::mt19937* prng;

    MakeBiggerFunctor(const EllipseGenerator &ellipseGenerator, std::mt19937 &prng);
    void operator()(EllipsesGenotype::Collection& genotype, Ellipse& ellipse) const;
};

struct AlterColorByRatioFunctor : public MutationFunctor<EllipsesGenotype::Collection, Ellipse>
{
    const std::unique_ptr<std::uniform_real_distribution<double>> rd;
    std::mt19937* prng;

    AlterColorByRatioFunctor(std::mt19937& prng);
    void operator()(EllipsesGenotype::Collection& genotype, Ellipse& ellipse) const;
};

struct AlterAlphaByRatioFunctor : public MutationFunctor<EllipsesGenotype::Collection, Ellipse>
{
    const std::unique_ptr<std::uniform_real_distribution<double>> rd;
    std::mt19937* prng;

    AlterAlphaByRatioFunctor(std::mt19937& prng);
    void operator()(EllipsesGenotype::Collection& genotype, Ellipse& ellipse) const;
};

struct AlterColorBySumFunctor : public MutationFunctor<EllipsesGenotype::Collection, Ellipse>
{
    std::mt19937* prng;
    const std::unique_ptr<std::uniform_real_distribution<double>> rd;

    AlterColorBySumFunctor(std::mt19937& prng);
    void operator()(EllipsesGenotype::Collection& genotype, Ellipse& ellipse) const;
};

struct AlterPositionFunctor : public MutationFunctor<EllipsesGenotype::Collection, Ellipse>
{
    const EllipseGenerator *ellipseGenerator;
    std::mt19937* prng;
    const std::unique_ptr<std::uniform_real_distribution<double>> rd;

    AlterPositionFunctor(const EllipseGenerator &ellipseGenerator, std::mt19937 &prng);
    void operator()(EllipsesGenotype::Collection& genotype, Ellipse& ellipse) const;
};

struct SwapWithRandomFunctor : MutationFunctor<EllipsesGenotype::Collection, Ellipse>
{
    const EllipseGenerator *ellipseGenerator;

    SwapWithRandomFunctor(const EllipseGenerator &ellipseGenerator);
    void operator()(EllipsesGenotype::Collection& genotype, Ellipse& ellipse) const;
};

struct AddNewEllipseFunctor : MutationFunctor<EllipsesGenotype::Collection, Ellipse>
{
    const EllipseGenerator *ellipseGenerator;

    AddNewEllipseFunctor(const EllipseGenerator& ellipseGenerator);
    void operator()(EllipsesGenotype::Collection& genotype, Ellipse& ellipse) const;
};

struct CopyNewEllipseFunctor : MutationFunctor<EllipsesGenotype::Collection, Ellipse>
{
    const EllipseGenerator *ellipseGenerator;
    std::mt19937* prng;

    CopyNewEllipseFunctor(const EllipseGenerator& ellipseGenerator, std::mt19937& prng);
    void operator()(EllipsesGenotype::Collection& genotype, Ellipse& ellipse) const;
};

struct RemoveFromBackFunctor : MutationFunctor<EllipsesGenotype::Collection, Ellipse>
{
    void operator()(EllipsesGenotype::Collection& genotype, Ellipse& ellipse) const;
};

struct RemoveFromFrontFunctor : MutationFunctor<EllipsesGenotype::Collection, Ellipse> {
    void operator()(EllipsesGenotype::Collection& genotype, Ellipse& ellipse) const;
};

struct RemoveRandomFunctor : MutationFunctor<EllipsesGenotype::Collection, Ellipse>
{
    std::mt19937* prng;

    RemoveRandomFunctor(std::mt19937 &prng);
    void operator()(EllipsesGenotype::Collection& genotype, Ellipse& ellipse) const;
};
