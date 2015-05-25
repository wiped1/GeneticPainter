#include "EllipsesMutationFunctors.hpp"

#include <iostream>

template <typename T>
T clamp(T n, T lower, T upper) {
        return std::max(lower, std::min(n, upper));
}

template <typename Distribution>
double getDistributedRandom(Distribution &rd, std::mt19937 &prng)
{
        return rd(prng);
}

AlterSizeFunctor::AlterSizeFunctor(const EllipseGenerator &ellipseGenerator, std::mt19937 &prng)
        : ellipseGenerator(&ellipseGenerator), prng(&prng)
        , rd(new std::uniform_real_distribution<double>(0.95, 1.05))
{
    // do nothing
}

void AlterSizeFunctor::operator()(EllipsesGenotype::Collection& genotype, Ellipse& ellipse) const
{
    ellipse.size.height = std::min<int>(
            ellipse.size.height * getDistributedRandom(*rd, *prng),
            ellipseGenerator->getMaxDiameter());
    ellipse.size.width = std::min<int>(
            ellipse.size.width * getDistributedRandom(*rd, *prng),
            ellipseGenerator->getMaxDiameter());
}

MakeSmallerFunctor::MakeSmallerFunctor(const EllipseGenerator &ellipseGenerator, std::mt19937 &prng)
        : ellipseGenerator(&ellipseGenerator) , prng(&prng)
        , rd(new std::uniform_real_distribution<double>(0.95, 1.05))
{
    // do nothing
}

void MakeSmallerFunctor::operator()(EllipsesGenotype::Collection& genotype, Ellipse& ellipse) const
{
    ellipse.size.height = std::min<int>(
        static_cast<int>(static_cast<double>(ellipse.size.height) * getDistributedRandom(*rd, *prng)),
        ellipseGenerator->getMaxDiameter());
    ellipse.size.width = std::min<int>(
        static_cast<int>(static_cast<double>(ellipse.size.width) * getDistributedRandom(*rd, *prng)),
        ellipseGenerator->getMaxDiameter());
}

MakeBiggerFunctor::MakeBiggerFunctor(const EllipseGenerator &ellipseGenerator, std::mt19937 &prng)
        : ellipseGenerator(&ellipseGenerator)
        , prng(&prng)
        , rd(new std::uniform_real_distribution<double>(1.00, 1.1))
{
    // do nothing
}

void MakeBiggerFunctor::operator()(EllipsesGenotype::Collection& genotype, Ellipse& ellipse) const {
    ellipse.size.height = std::min<int>(
            static_cast<int>(static_cast<double>(ellipse.size.height) * getDistributedRandom(*rd, *prng)),
            ellipseGenerator->getMaxDiameter());
    ellipse.size.width = std::min<int>(
            static_cast<int>(static_cast<double>(ellipse.size.width) * getDistributedRandom(*rd, *prng)),
            ellipseGenerator->getMaxDiameter());
}

AlterColorByRatioFunctor::AlterColorByRatioFunctor(std::mt19937& prng)
        : prng(&prng)
        , rd(new std::uniform_real_distribution<double>(0.95, 1.05))
{
    // do nothing
}

void AlterColorByRatioFunctor::operator()(EllipsesGenotype::Collection& genotype, Ellipse& ellipse) const {
    ellipse.color[0] = static_cast<int>(ellipse.color[0] * getDistributedRandom(*rd, *prng)) % 256;
    ellipse.color[1] = static_cast<int>(ellipse.color[1] * getDistributedRandom(*rd, *prng)) % 256;
    ellipse.color[2] = static_cast<int>(ellipse.color[2] * getDistributedRandom(*rd, *prng)) % 256;
}


AlterAlphaByRatioFunctor::AlterAlphaByRatioFunctor(std::mt19937& prng)
        : prng(&prng)
        , rd(new std::uniform_real_distribution<double>(0.95, 1.05))
{
    // do nothing
}

void AlterAlphaByRatioFunctor::operator()(EllipsesGenotype::Collection& genotype, Ellipse& ellipse) const
{
    ellipse.color[3] = std::min(ellipse.color[3] * getDistributedRandom(*rd, *prng), 1.0);
}

AlterColorBySumFunctor::AlterColorBySumFunctor(std::mt19937& prng)
        : prng(&prng)
        , rd(new std::uniform_real_distribution<double>(-1.0, 1.0))
{
    // do nothing
}

void AlterColorBySumFunctor::operator()(EllipsesGenotype::Collection& genotype, Ellipse& ellipse) const
{
    ellipse.color[0] = clamp(static_cast<int>(ellipse.color[0] + getDistributedRandom(*rd, *prng)), 0, 255);
    ellipse.color[1] = clamp(static_cast<int>(ellipse.color[1] + getDistributedRandom(*rd, *prng)), 0, 255);
    ellipse.color[2] = clamp(static_cast<int>(ellipse.color[2] + getDistributedRandom(*rd, *prng)), 0, 255);
}

AlterPositionFunctor::AlterPositionFunctor(const EllipseGenerator &ellipseGenerator, std::mt19937 &prng)
        : ellipseGenerator(&ellipseGenerator)
        , prng(&prng)
        , rd(new std::uniform_real_distribution<double>(0.95, 1.05))
{
    // do nothing
}

void AlterPositionFunctor::operator()(EllipsesGenotype::Collection& genotype, Ellipse& ellipse) const
{
    if (ellipse.position.x < 0) {
        std::cout << "BREAKPOINT" << std::endl;
    }
    ellipse.position.x = std::min<int>(
            static_cast<int>(static_cast<double>(ellipse.position.x) * getDistributedRandom(*rd, *prng)),
            ellipseGenerator->getPositionBound().width);
    ellipse.position.y = std::min<int>(
            static_cast<int>(static_cast<double>(ellipse.position.y) * getDistributedRandom(*rd, *prng)),
            ellipseGenerator->getPositionBound().height);
}

SwapWithRandomFunctor::SwapWithRandomFunctor(const EllipseGenerator &ellipseGenerator)
        : ellipseGenerator(&ellipseGenerator)
{
    // do nothing
}

void SwapWithRandomFunctor::operator()(EllipsesGenotype::Collection& genotype, Ellipse& ellipse) const
{
    ellipse = std::move(ellipseGenerator->generateRandom());
}

AddNewEllipseFunctor::AddNewEllipseFunctor(const EllipseGenerator& ellipseGenerator)
        : ellipseGenerator(&ellipseGenerator)
{
    // do nothing
}

void AddNewEllipseFunctor::operator()(EllipsesGenotype::Collection& genotype, Ellipse& ellipse) const
{
    if (std::distance(genotype.cbegin(), genotype.cend()) < EvolvingEnvironmentProvider::getInstance().genesCount)
    {
        genotype.emplace_back(ellipseGenerator->generateRandom());
    }
}

CopyNewEllipseFunctor::CopyNewEllipseFunctor(const EllipseGenerator& ellipseGenerator, std::mt19937& prng)
        : ellipseGenerator(&ellipseGenerator)
        , prng(&prng)
{
    // do nothing
}

void CopyNewEllipseFunctor::operator()(EllipsesGenotype::Collection& genotype, Ellipse& ellipse) const
{
    Ellipse e(ellipse);
    genotype.push_back(e);
}

void RemoveFromBackFunctor::operator()(EllipsesGenotype::Collection& genotype, Ellipse& ellipse) const
{
    if (genotype.size() > 0) {
        genotype.erase(genotype.begin());
    }
}

void RemoveFromFrontFunctor::operator()(EllipsesGenotype::Collection& genotype, Ellipse& ellipse) const
{
    if (genotype.size() > 0) {
        genotype.erase(std::prev(genotype.end()));
    }
}

RemoveRandomFunctor::RemoveRandomFunctor(std::mt19937 &prng)
        : prng(&prng)
{
    // do nothing
}

void RemoveRandomFunctor::operator()(EllipsesGenotype::Collection& genotype, Ellipse& ellipse) const
{
    if (genotype.size() > 0) {
        genotype.erase(std::next(genotype.begin(), (*prng)() % genotype.size()));
    }
}

void RemoveHalfFunctor::operator()(EllipsesGenotype::Collection& genotype, Ellipse& ellipse) const
{
    if (genotype.size() > 0) {
        genotype.erase(genotype.begin(), std::prev(genotype.end(),
                std::distance(genotype.begin(), genotype.end()) / 2));
    }
}

SwapRandomEllipsesFunctor::SwapRandomEllipsesFunctor(std::mt19937 &prng)
        : prng(&prng)
{
    // do nothing
}

void SwapRandomEllipsesFunctor::operator()(EllipsesGenotype::Collection& genotype, Ellipse& ellipse) const
{
    if (genotype.size() > 2) {
        std::uniform_int_distribution<int> dist(0, genotype.size() - 1);
        auto currentGenotypeIt = std::find(genotype.begin(), genotype.end(), ellipse);
        int index = dist(*prng);
        auto newGenotypeIt = std::next(genotype.begin(), index);
        if (currentGenotypeIt != newGenotypeIt) {
            std::iter_swap(currentGenotypeIt, newGenotypeIt);
        }
    }
}
