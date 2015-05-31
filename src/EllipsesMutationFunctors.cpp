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

void AlterSizeFunctor::mutate(EllipsesGenotype::Collection& genes) const
{
    auto ellipse = genes.at((*prng)() % genes.size());
    ellipse.size.height = std::min<int>(
            static_cast<int>(static_cast<double>(ellipse.size.height) * getDistributedRandom(*rd, *prng)),
            ellipseGenerator->getMaxDiameter());
    ellipse.size.width = std::min<int>(
            static_cast<int>(static_cast<double>(ellipse.size.width) * getDistributedRandom(*rd, *prng)),
            ellipseGenerator->getMaxDiameter());
}

MakeSmallerFunctor::MakeSmallerFunctor(const EllipseGenerator &ellipseGenerator, std::mt19937 &prng)
        : ellipseGenerator(&ellipseGenerator) , prng(&prng)
        , rd(new std::uniform_real_distribution<double>(0.95, 1.00))
{
    // do nothing
}

void MakeSmallerFunctor::mutate(EllipsesGenotype::Collection& genes) const
{
    auto ellipse = genes.at((*prng)() % genes.size());
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
        , rd(new std::uniform_real_distribution<double>(1.00, 1.05))
{
    // do nothing
}

void MakeBiggerFunctor::mutate(EllipsesGenotype::Collection& genes) const {
    auto ellipse = genes.at((*prng)() % genes.size());
    ellipse.size.height = std::min<int>(
            static_cast<int>(static_cast<double>(ellipse.size.height) * getDistributedRandom(*rd, *prng)),
            ellipseGenerator->getMaxDiameter());
    ellipse.size.width = std::min<int>(
            static_cast<int>(static_cast<double>(ellipse.size.width) * getDistributedRandom(*rd, *prng)),
            ellipseGenerator->getMaxDiameter());
}

AlterColorByRatioFunctor::AlterColorByRatioFunctor(std::mt19937& prng)
        : prng(&prng)
        , rd(new std::uniform_real_distribution<double>(0.5, 1.5))
{
    // do nothing
}

void AlterColorByRatioFunctor::mutate(EllipsesGenotype::Collection& genes) const {
    auto ellipse = genes.at((*prng)() % genes.size());
    ellipse.color[0] = static_cast<int>(ellipse.color[0] * getDistributedRandom(*rd, *prng)) % 256;
    ellipse.color[1] = static_cast<int>(ellipse.color[1] * getDistributedRandom(*rd, *prng)) % 256;
    ellipse.color[2] = static_cast<int>(ellipse.color[2] * getDistributedRandom(*rd, *prng)) % 256;
}


AlterAlphaByRatioFunctor::AlterAlphaByRatioFunctor(std::mt19937& prng)
        : prng(&prng)
        , rd(new std::uniform_real_distribution<double>(0.92, 1.08))
{
    // do nothing
}

void AlterAlphaByRatioFunctor::mutate(EllipsesGenotype::Collection& genes) const
{
    auto ellipse = genes.at((*prng)() % genes.size());
    ellipse.color[3] = std::min(ellipse.color[3] * getDistributedRandom(*rd, *prng), 1.0);
}

AlterColorBySumFunctor::AlterColorBySumFunctor(std::mt19937& prng)
        : prng(&prng)
        , rd(new std::uniform_real_distribution<double>(-50.0, 50.0))
{
    // do nothing
}

void AlterColorBySumFunctor::mutate(EllipsesGenotype::Collection& genes) const
{
    auto ellipse = genes.at((*prng)() % genes.size());
    ellipse.color[0] = clamp(static_cast<int>(ellipse.color[0] + getDistributedRandom(*rd, *prng)), 0, 255);
    ellipse.color[1] = clamp(static_cast<int>(ellipse.color[1] + getDistributedRandom(*rd, *prng)), 0, 255);
    ellipse.color[2] = clamp(static_cast<int>(ellipse.color[2] + getDistributedRandom(*rd, *prng)), 0, 255);
}

AlterPositionFunctor::AlterPositionFunctor(const EllipseGenerator &ellipseGenerator, std::mt19937 &prng)
        : ellipseGenerator(&ellipseGenerator)
        , prng(&prng)
        , rd(new std::uniform_real_distribution<double>(0.5, 1.5))
{
    // do nothing
}

void AlterPositionFunctor::mutate(EllipsesGenotype::Collection& genes) const
{
    auto ellipse = genes.at((*prng)() % genes.size());
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

void SwapWithRandomFunctor::mutate(EllipsesGenotype::Collection& genes) const
{
//    ellipse = std::move(ellipseGenerator->generateRandom());
}

AddNewEllipseFunctor::AddNewEllipseFunctor(const EllipseGenerator& ellipseGenerator)
        : ellipseGenerator(&ellipseGenerator)
{
    // do nothing
}

void AddNewEllipseFunctor::mutate(EllipsesGenotype::Collection& genes) const
{
    if (std::distance(genes.cbegin(), genes.cend()) < EvolvingEnvironmentProvider::getInstance().genesCount)
    {
        genes.emplace_back(ellipseGenerator->generateRandom());
    }
}

CopyNewEllipseFunctor::CopyNewEllipseFunctor(const EllipseGenerator& ellipseGenerator, std::mt19937& prng)
        : ellipseGenerator(&ellipseGenerator),
          prng(&prng),
          rd(new std::uniform_real_distribution<double>(0.95, 1.05))

{
    // do nothing
}

void CopyNewEllipseFunctor::mutate(EllipsesGenotype::Collection& genes) const
{
    auto ellipse = genes.at((*prng)() % genes.size());
    Ellipse e(ellipse);
    e.position.x = std::min<int>(
            static_cast<int>(static_cast<double>(e.position.x) * getDistributedRandom(*rd, *prng)),
            ellipseGenerator->getPositionBound().width);
    e.position.y = std::min<int>(
            static_cast<int>(static_cast<double>(e.position.y) * getDistributedRandom(*rd, *prng)),
            ellipseGenerator->getPositionBound().height);
    genes.push_back(e);
}

void RemoveFromBackFunctor::mutate(EllipsesGenotype::Collection& genes) const
{
    if (genes.size() > 1) {
        genes.erase(genes.begin());
    }
}

void RemoveFromFrontFunctor::mutate(EllipsesGenotype::Collection& genes) const
{
    if (genes.size() > 1) {
        genes.erase(std::prev(genes.end()));
    }
}

RemoveRandomFunctor::RemoveRandomFunctor(std::mt19937 &prng)
        : prng(&prng)
{
    // do nothing
}

void RemoveRandomFunctor::mutate(EllipsesGenotype::Collection& genes) const
{
    if (genes.size() > 1) {
        genes.erase(std::next(genes.begin(), (*prng)() % genes.size()));
    }
}


