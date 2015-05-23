//
// Created by Mckomo on 23.05.15.
//

#pragma once

#include "MutationFunctor.hpp"

template <typename T>
T clamp(T n, T lower, T upper) {
    return std::max(lower, std::min(n, upper));
}

template <typename Distribution>
double getDistributedRandom(Distribution &rd, std::mt19937 &prng)
{
    return rd(prng);
}

struct AlterSizeFunctor : public MutationFunctor<EllipsesGenotype::Collection, Ellipse>
{
    const EllipseGenerator *ellipseGenerator;
    const std::unique_ptr<std::uniform_real_distribution<double>> rd;
    std::mt19937* prng;

    AlterSizeFunctor(const EllipseGenerator &ellipseGenerator, std::mt19937 &prng)
            : ellipseGenerator(&ellipseGenerator)
            , prng(&prng)
            , rd(new std::uniform_real_distribution<double>(0.95, 1.05))
    {
        // do nothing
    }

    virtual void operator()(EllipsesGenotype::Collection& genotype, Ellipse& ellipse) const
    {
        ellipse.size.height = std::min<int>(
                static_cast<int>(static_cast<double>(ellipse.size.height) * getDistributedRandom(*rd, *prng)),
                ellipseGenerator->getMaxDiameter());
        ellipse.size.width = std::min<int>(
                static_cast<int>(static_cast<double>(ellipse.size.width) * getDistributedRandom(*rd, *prng)),
                ellipseGenerator->getMaxDiameter());
    }
};

struct MakeSmallerFunctor : public MutationFunctor<EllipsesGenotype::Collection, Ellipse>
{
    const EllipseGenerator *ellipseGenerator;
    const std::unique_ptr<std::uniform_real_distribution<double>> rd;
    std::mt19937* prng;

    MakeSmallerFunctor(const EllipseGenerator &ellipseGenerator, std::mt19937 &prng)
            : ellipseGenerator(&ellipseGenerator)
            , prng(&prng)
            , rd(new std::uniform_real_distribution<double>(0.95, 1.00))
    {
        // do nothing
    }

    virtual void operator()(EllipsesGenotype::Collection& genotype, Ellipse& ellipse) const
    {
        ellipse.size.height = std::min<int>(
                static_cast<int>(static_cast<double>(ellipse.size.height) * getDistributedRandom(*rd, *prng)),
                ellipseGenerator->getMaxDiameter());
        ellipse.size.width = std::min<int>(
                static_cast<int>(static_cast<double>(ellipse.size.width) * getDistributedRandom(*rd, *prng)),
                ellipseGenerator->getMaxDiameter());
    }
};

struct MakeBiggerFunctor : public MutationFunctor<EllipsesGenotype::Collection, Ellipse>
{
    const EllipseGenerator *ellipseGenerator;
    const std::unique_ptr<std::uniform_real_distribution<double>> rd;
    std::mt19937* prng;

    MakeBiggerFunctor(const EllipseGenerator &ellipseGenerator, std::mt19937 &prng)
            : ellipseGenerator(&ellipseGenerator)
            , prng(&prng)
            , rd(new std::uniform_real_distribution<double>(1.00, 1.05))
    {
        // do nothing
    }

    virtual void operator()(EllipsesGenotype::Collection& genotype, Ellipse& ellipse) const
    {
        ellipse.size.height = std::min<int>(
                static_cast<int>(static_cast<double>(ellipse.size.height) * getDistributedRandom(*rd, *prng)),
                ellipseGenerator->getMaxDiameter());
        ellipse.size.width = std::min<int>(
                static_cast<int>(static_cast<double>(ellipse.size.width) * getDistributedRandom(*rd, *prng)),
                ellipseGenerator->getMaxDiameter());
    }
};

struct AlterColorByRatioFunctor : public MutationFunctor<EllipsesGenotype::Collection, Ellipse> {

    const std::unique_ptr<std::uniform_real_distribution<double>> rd;
    std::mt19937* prng;

    AlterColorByRatioFunctor(std::mt19937& prng)
            : prng(&prng)
            , rd(new std::uniform_real_distribution<double>(0.5, 1.5))
    {
        // do nothing
    }

    virtual void operator()(EllipsesGenotype::Collection& genotype, Ellipse& ellipse) const
    {
        ellipse.color[0] = static_cast<int>(ellipse.color[0] * getDistributedRandom(*rd, *prng)) % 256;
        ellipse.color[1] = static_cast<int>(ellipse.color[1] * getDistributedRandom(*rd, *prng)) % 256;
        ellipse.color[2] = static_cast<int>(ellipse.color[2] * getDistributedRandom(*rd, *prng)) % 256;
    }
};

struct AlterBlueByRatioFunctor : public MutationFunctor<EllipsesGenotype::Collection, Ellipse>
{
    const std::unique_ptr<std::uniform_real_distribution<double>> rd;
    std::mt19937* prng;

    AlterBlueByRatioFunctor(std::mt19937& prng)
            : prng(&prng)
            , rd(new std::uniform_real_distribution<double>(0.95, 1.05))
    {
        // do nothing
    }

    virtual void operator()(EllipsesGenotype::Collection& genotype, Ellipse& ellipse) const
    {
        ellipse.color[0] = static_cast<int>(ellipse.color[0] * getDistributedRandom(*rd, *prng)) % 256;
    }
};

struct AlterGreenByRatioFunctor : public MutationFunctor<EllipsesGenotype::Collection, Ellipse>
{
    const std::unique_ptr<std::uniform_real_distribution<double>> rd;
    std::mt19937* prng;

    AlterGreenByRatioFunctor(std::mt19937& prng)
            : prng(&prng)
            , rd(new std::uniform_real_distribution<double>(0.95, 1.05))
    {
        // do nothing
    }

    virtual void operator()(EllipsesGenotype::Collection& genotype, Ellipse& ellipse) const
    {
        ellipse.color[1] = static_cast<int>(ellipse.color[1] * getDistributedRandom(*rd, *prng)) % 256;
    }
};

struct AlterRedByRatioFunctor : public MutationFunctor<EllipsesGenotype::Collection, Ellipse>
{
    const std::unique_ptr<std::uniform_real_distribution<double>> rd;
    std::mt19937* prng;

    AlterRedByRatioFunctor(std::mt19937& prng)
            : prng(&prng)
            , rd(new std::uniform_real_distribution<double>(0.95, 1.05))
    {
        // do nothing
    }

    virtual void operator()(EllipsesGenotype::Collection& genotype, Ellipse& ellipse) const
    {
        ellipse.color[2] = static_cast<int>(ellipse.color[2] * getDistributedRandom(*rd, *prng)) % 256;
    }
};

struct AlterColorBySumFunctor : public MutationFunctor<EllipsesGenotype::Collection, Ellipse>
{
    std::mt19937* prng;
    const std::unique_ptr<std::uniform_real_distribution<double>> rd;

    AlterColorBySumFunctor(std::mt19937& prng)
            : prng(&prng)
            , rd(new std::uniform_real_distribution<double>(-50.0, 50.0))
    {
        // do nothing
    }

    virtual void operator()(EllipsesGenotype::Collection& genotype, Ellipse& ellipse) const
    {
        ellipse.color[0] = clamp(static_cast<int>(ellipse.color[0] + getDistributedRandom(*rd, *prng)), 0, 255);
        ellipse.color[1] = clamp(static_cast<int>(ellipse.color[1] + getDistributedRandom(*rd, *prng)), 0, 255);
        ellipse.color[2] = clamp(static_cast<int>(ellipse.color[2] + getDistributedRandom(*rd, *prng)), 0, 255);
    }
};

struct AlterPositionFunctor : public MutationFunctor<EllipsesGenotype::Collection, Ellipse>
{
    const EllipseGenerator *ellipseGenerator;
    std::mt19937* prng;
    const std::unique_ptr<std::uniform_real_distribution<double>> rd;

    AlterPositionFunctor(const EllipseGenerator &ellipseGenerator, std::mt19937 &prng)
            : ellipseGenerator(&ellipseGenerator)
            , prng(&prng)
            , rd(new std::uniform_real_distribution<double>(0.5, 1.5))
    {
        // do nothing
    }

    virtual void operator()(EllipsesGenotype::Collection& genotype, Ellipse& ellipse) const
    {
        ellipse.position.x = std::min<int>(
                static_cast<int>(static_cast<double>(ellipse.position.x) * getDistributedRandom(*rd, *prng)),
                ellipseGenerator->getPositionBound().width);
        ellipse.position.y = std::min<int>(
                static_cast<int>(static_cast<double>(ellipse.position.y) * getDistributedRandom(*rd, *prng)),
                ellipseGenerator->getPositionBound().height);
    }
};

struct SwapWithRandomFunctor : MutationFunctor<EllipsesGenotype::Collection, Ellipse>
{
    const EllipseGenerator *ellipseGenerator;

    SwapWithRandomFunctor(const EllipseGenerator &ellipseGenerator)
            : ellipseGenerator(&ellipseGenerator)
    {
        // do nothing
    }

    virtual void operator()(EllipsesGenotype::Collection& genotype, Ellipse& ellipse) const
    {
        ellipse = std::move(ellipseGenerator->generateRandom());
    }
};

struct AddNewEllipseFunctor : MutationFunctor<EllipsesGenotype::Collection, Ellipse>
{
    const EllipseGenerator *ellipseGenerator;

    AddNewEllipseFunctor(const EllipseGenerator& ellipseGenerator)
            : ellipseGenerator(&ellipseGenerator)
    {
        // do nothing
    }

    virtual void operator()(EllipsesGenotype::Collection& genotype, Ellipse& ellipse) const
    {
        if (std::distance(genotype.cbegin(), genotype.cend()) < EvolvingEnvironmentProvider::getInstance().genesCount)
        {
            genotype.emplace_back(ellipseGenerator->generateRandom());
        }
    }
};

struct CopyNewEllipseFunctor : MutationFunctor<EllipsesGenotype::Collection, Ellipse>
{
    const EllipseGenerator *ellipseGenerator;
    std::mt19937* prng;

    CopyNewEllipseFunctor(const EllipseGenerator& ellipseGenerator, std::mt19937& prng)
            : ellipseGenerator(&ellipseGenerator)
            , prng(&prng)
    {
        // do nothing
    }

    virtual void operator()(EllipsesGenotype::Collection& genotype, Ellipse& ellipse) const
    {
        AlterPositionFunctor alterPosition(*ellipseGenerator, *prng);
        Ellipse e(ellipse);
        alterPosition(genotype, e);
        genotype.push_back(e);
    }
};

struct RemoveFromBackFunctor : MutationFunctor<EllipsesGenotype::Collection, Ellipse>
{
    virtual void operator()(EllipsesGenotype::Collection& genotype, Ellipse& ellipse) const
    {
        genotype.erase(genotype.begin());
    }
};

struct RemoveRandomFunctor : MutationFunctor<EllipsesGenotype::Collection, Ellipse>
{
    std::mt19937* prng;

    RemoveRandomFunctor(std::mt19937 &prng) : prng(&prng)
    {
        // do nothing
    }

    virtual void operator()(EllipsesGenotype::Collection& genotype, Ellipse& ellipse) const
    {
        genotype.erase(std::next(genotype.begin(), (*prng)() % genotype.size()));
    }
};