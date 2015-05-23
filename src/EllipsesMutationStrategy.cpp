//
// Created by Mckomo on 18.04.15.
//

#include <iostream>
#include <random>
#include <functional>
#include <EllipsesSizeComparator.hpp>
#include <EvolvingEnvironment.hpp>
#include "EllipsesMutationStrategy.hpp"
#include "EllipsesGenotype.hpp"
#include "MutationFunctor.hpp"
#include "MutationProbabilityDistribution.hpp"

using namespace gall;

template <typename Distribution>
double getRandomRatio(Distribution& dist, std::mt19937& prng) {
    return dist(prng);
}

struct AlterSizeFunctor : public MutationFunctor<EllipsesGenotype::Collection, Ellipse> {
    const EllipseGenerator *ellipseGenerator;
    std::mt19937* prng;
    const std::unique_ptr<std::uniform_real_distribution<double>> alterationRatio;
    AlterSizeFunctor(const EllipseGenerator &ellipseGenerator, std::mt19937 &prng)
    : ellipseGenerator(&ellipseGenerator), prng(&prng), alterationRatio(
            new std::uniform_real_distribution<double>(0.95, 1.05)) {
        // do nothing
    }

    virtual void operator()(EllipsesGenotype::Collection& genotype, Ellipse& ellipse) const {
        ellipse.size.height = std::min<int>(static_cast<int>(static_cast<double>(ellipse.size.height)
                * getRandomRatio(*alterationRatio, *prng)), ellipseGenerator->getMaxDiameter());
        ellipse.size.width = std::min<int>(static_cast<int>(static_cast<double>(ellipse.size.width)
                * getRandomRatio(*alterationRatio, *prng)), ellipseGenerator->getMaxDiameter());
    }
};

struct MakeSmallerFunctor : public MutationFunctor<EllipsesGenotype::Collection, Ellipse> {
    const EllipseGenerator *ellipseGenerator;
    std::mt19937* prng;
    const std::unique_ptr<std::uniform_real_distribution<double>> alterationRatio;
    MakeSmallerFunctor(const EllipseGenerator &ellipseGenerator, std::mt19937 &prng)
            : ellipseGenerator(&ellipseGenerator), prng(&prng), alterationRatio(
            new std::uniform_real_distribution<double>(0.95, 1.00)) {
        // do nothing
    }
    virtual void operator()(EllipsesGenotype::Collection& genotype, Ellipse& ellipse) const {
        ellipse.size.height = std::min<int>(static_cast<int>(static_cast<double>(ellipse.size.height)
                * getRandomRatio(*alterationRatio, *prng)), ellipseGenerator->getMaxDiameter());
        ellipse.size.width = std::min<int>(static_cast<int>(static_cast<double>(ellipse.size.width)
                * getRandomRatio(*alterationRatio, *prng)), ellipseGenerator->getMaxDiameter());
    }
};

struct MakeBiggerFunctor : public MutationFunctor<EllipsesGenotype::Collection, Ellipse> {
    const EllipseGenerator *ellipseGenerator;
    std::mt19937* prng;
    const std::unique_ptr<std::uniform_real_distribution<double>> alterationRatio;
    MakeBiggerFunctor(const EllipseGenerator &ellipseGenerator, std::mt19937 &prng)
            : ellipseGenerator(&ellipseGenerator), prng(&prng), alterationRatio(
            new std::uniform_real_distribution<double>(1.00, 1.05)) {
        // do nothing
    }
    virtual void operator()(EllipsesGenotype::Collection& genotype, Ellipse& ellipse) const {
        ellipse.size.height = std::min<int>(static_cast<int>(static_cast<double>(ellipse.size.height)
                * getRandomRatio(*alterationRatio, *prng)), ellipseGenerator->getMaxDiameter());
        ellipse.size.width = std::min<int>(static_cast<int>(static_cast<double>(ellipse.size.width)
                * getRandomRatio(*alterationRatio, *prng)), ellipseGenerator->getMaxDiameter());
    }
};

struct AlterColorByRatioFunctor : public MutationFunctor<EllipsesGenotype::Collection, Ellipse> {
    std::mt19937* prng;
    const std::unique_ptr<std::uniform_real_distribution<double>> alterationRatio;
    AlterColorByRatioFunctor(std::mt19937& prng) : prng(&prng),
            alterationRatio(new std::uniform_real_distribution<double>(0.5, 1.5)) {
        // do nothing
    }
    virtual void operator()(EllipsesGenotype::Collection& genotype, Ellipse& ellipse) const {
        ellipse.color[0] = static_cast<int>(ellipse.color[0] * getRandomRatio(*alterationRatio, *prng)) % 256;
        ellipse.color[1] = static_cast<int>(ellipse.color[1] * getRandomRatio(*alterationRatio, *prng)) % 256;
        ellipse.color[2] = static_cast<int>(ellipse.color[2] * getRandomRatio(*alterationRatio, *prng)) % 256;
    }
};

struct AlterBlueByRatioFunctor : public MutationFunctor<EllipsesGenotype::Collection, Ellipse> {
    std::mt19937* prng;
    const std::unique_ptr<std::uniform_real_distribution<double>> alterationRatio;
    AlterBlueByRatioFunctor(std::mt19937& prng) : prng(&prng),
            alterationRatio(new std::uniform_real_distribution<double>(0.95, 1.05)) {
        // do nothing
    }
    virtual void operator()(EllipsesGenotype::Collection& genotype, Ellipse& ellipse) const {
        ellipse.color[0] = static_cast<int>(ellipse.color[0] * getRandomRatio(*alterationRatio, *prng)) % 256;
    }
};

struct AlterGreenByRatioFunctor : public MutationFunctor<EllipsesGenotype::Collection, Ellipse> {
    std::mt19937* prng;
    const std::unique_ptr<std::uniform_real_distribution<double>> alterationRatio;
    AlterGreenByRatioFunctor(std::mt19937& prng) : prng(&prng),
            alterationRatio(new std::uniform_real_distribution<double>(0.95, 1.05)) {
        // do nothing
    }
    virtual void operator()(EllipsesGenotype::Collection& genotype, Ellipse& ellipse) const {
        ellipse.color[1] = static_cast<int>(ellipse.color[1] * getRandomRatio(*alterationRatio, *prng)) % 256;
    }
};

struct AlterRedByRatioFunctor : public MutationFunctor<EllipsesGenotype::Collection, Ellipse> {
    std::mt19937* prng;
    const std::unique_ptr<std::uniform_real_distribution<double>> alterationRatio;
    AlterRedByRatioFunctor(std::mt19937& prng) : prng(&prng),
            alterationRatio(new std::uniform_real_distribution<double>(0.95, 1.05)) {
        // do nothing
    }
    virtual void operator()(EllipsesGenotype::Collection& genotype, Ellipse& ellipse) const {
        ellipse.color[2] = static_cast<int>(ellipse.color[2] * getRandomRatio(*alterationRatio, *prng)) % 256;
    }
};

template <typename T>
T clamp(T n, T lower, T upper) {
    return std::max(lower, std::min(n, upper));
}

struct AlterColorBySumFunctor : public MutationFunctor<EllipsesGenotype::Collection, Ellipse> {
    std::mt19937* prng;
    const std::unique_ptr<std::uniform_int_distribution<int>> alterationAmmount;
    AlterColorBySumFunctor(std::mt19937& prng) : prng(&prng),
            alterationAmmount(new std::uniform_int_distribution<int>(-50, 50)) {
        // do nothing
    }
    virtual void operator()(EllipsesGenotype::Collection& genotype, Ellipse& ellipse) const {
        ellipse.color[0] = clamp(static_cast<int>(ellipse.color[0]) + (*alterationAmmount)(*prng), 0, 255);
        ellipse.color[1] = clamp(static_cast<int>(ellipse.color[1]) + (*alterationAmmount)(*prng), 0, 255);
        ellipse.color[2] = clamp(static_cast<int>(ellipse.color[2]) + (*alterationAmmount)(*prng), 0, 255);
    }
};

struct AlterPositionFunctor : public MutationFunctor<EllipsesGenotype::Collection, Ellipse> {
    const EllipseGenerator *ellipseGenerator;
    std::mt19937* prng;
    const std::unique_ptr<std::uniform_real_distribution<double>> alterationRatio;
    AlterPositionFunctor(const EllipseGenerator &ellipseGenerator, std::mt19937 &prng)
    : ellipseGenerator(&ellipseGenerator),
      prng(&prng),
      alterationRatio(new std::uniform_real_distribution<double>(0.5, 1.5))
    {
        // do nothing
    }

    virtual void operator()(EllipsesGenotype::Collection& genotype, Ellipse& ellipse) const {
        ellipse.position.x = std::min<int>(static_cast<int>(static_cast<double>(ellipse.position.x)
                * getRandomRatio(*alterationRatio, *prng)), ellipseGenerator->getPositionBound().width);
        ellipse.position.y = std::min<int>(static_cast<int>(static_cast<double>(ellipse.position.y)
                * getRandomRatio(*alterationRatio, *prng)), ellipseGenerator->getPositionBound().height);
    }
};

struct SwapWithRandomFunctor : MutationFunctor<EllipsesGenotype::Collection, Ellipse> {
    const EllipseGenerator *ellipseGenerator;
    SwapWithRandomFunctor(const EllipseGenerator &ellipseGenerator)
    : ellipseGenerator(&ellipseGenerator) {
        // do nothing
    }
    virtual void operator()(EllipsesGenotype::Collection& genotype, Ellipse& ellipse) const {
        ellipse = std::move(ellipseGenerator->generateRandom());
    }
};

struct AddNewEllipseFunctor : MutationFunctor<EllipsesGenotype::Collection, Ellipse> {
    const EllipseGenerator *ellipseGenerator;
    AddNewEllipseFunctor(const EllipseGenerator& ellipseGenerator)
    : ellipseGenerator(&ellipseGenerator) {
        // do nothing
    }
    virtual void operator()(EllipsesGenotype::Collection& genotype, Ellipse& ellipse) const {
        if (std::distance(genotype.cbegin(), genotype.cend()) < EvolvingEnvironmentProvider::getInstance().genesCount) {
            genotype.emplace_back(ellipseGenerator->generateRandom());
        }
    }
};

struct CopyNewEllipseFunctor : MutationFunctor<EllipsesGenotype::Collection, Ellipse> {
    const EllipseGenerator *ellipseGenerator;
    std::mt19937* prng;
    CopyNewEllipseFunctor(const EllipseGenerator& ellipseGenerator, std::mt19937& prng)
            : ellipseGenerator(&ellipseGenerator), prng(&prng) {
        // do nothing
    }
    virtual void operator()(EllipsesGenotype::Collection& genotype, Ellipse& ellipse) const {
        AlterPositionFunctor alterPosition(*ellipseGenerator, *prng);
        Ellipse e(ellipse);
        alterPosition(genotype, e);
        genotype.push_back(e);
    }
};

struct RemoveFromBackFunctor : MutationFunctor<EllipsesGenotype::Collection, Ellipse> {
    virtual void operator()(EllipsesGenotype::Collection& genotype, Ellipse& ellipse) const {
        genotype.erase(genotype.begin());
    }
};

struct RemoveRandomFunctor : MutationFunctor<EllipsesGenotype::Collection, Ellipse> {
    std::mt19937* prng;
    RemoveRandomFunctor(std::mt19937 &prng) : prng(&prng) {
        // do nothing
    }
    virtual void operator()(EllipsesGenotype::Collection& genotype, Ellipse& ellipse) const {
        genotype.erase(std::next(genotype.begin(), (*prng)() % genotype.size()));
    }
};

EllipsesMutationStrategy::EllipsesMutationStrategy(EllipseGenerator &ellipseGenerator, std::mt19937 &prng)
        : ellipseGenerator(&ellipseGenerator)
        , prng(&prng)
        , alterationDistribution(new std::uniform_real_distribution<double>(0.0, 1.0))
        , alterationRatio(new std::uniform_real_distribution<double>(0.95, 1.05))
        , dist(prng)
{
    dist.add(new AlterSizeFunctor(ellipseGenerator, prng),10);
    dist.add(new MakeBiggerFunctor(ellipseGenerator, prng),0);
    dist.add(new MakeSmallerFunctor(ellipseGenerator, prng),0);
    dist.add(new AlterColorByRatioFunctor(prng),10);
    dist.add(new AlterBlueByRatioFunctor(prng),0);
    dist.add(new AlterGreenByRatioFunctor(prng),0);
    dist.add(new AlterRedByRatioFunctor(prng),0);
    dist.add(new AlterColorBySumFunctor(prng),10);
    dist.add(new AlterPositionFunctor(ellipseGenerator, prng),10);
    dist.add(new SwapWithRandomFunctor(ellipseGenerator),1);
    dist.add(new AddNewEllipseFunctor(ellipseGenerator),5);
    dist.add(new CopyNewEllipseFunctor(ellipseGenerator, prng), 3);
    dist.add<RemoveFromBackFunctor>(5);
    dist.add(new RemoveRandomFunctor(prng),1);
}

void EllipsesMutationStrategy::mutate(EllipsesGenotype::Type &genotype) const
{
    std::for_each(genotype.begin(), genotype.end(), [&](auto &ellipse)
    {
        double result = (*alterationDistribution)(*prng);
        if (result >= 0.5) {
            // mutate
            dist.draw()(genotype.collection(), ellipse);
        }
    });

    std::sort(genotype.rbegin(), genotype.rend(), EllipsesSizeComparator());
}
