#include "EllipsesMutationFunctors.hpp"

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
        , rd(new std::uniform_real_distribution<double>(1.00, 1.05))
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
        , rd(new std::uniform_real_distribution<double>(0.5, 1.5))
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
        , rd(new std::uniform_real_distribution<double>(0.5, 1.5))
{
    // do nothing
}

void AlterAlphaByRatioFunctor::operator()(EllipsesGenotype::Collection& genotype, Ellipse& ellipse) const
{
    ellipse.color[3] = std::min(ellipse.color[3] * getDistributedRandom(*rd, *prng), 1.0);
}

AlterColorBySumFunctor::AlterColorBySumFunctor(std::mt19937& prng)
        : prng(&prng)
        , rd(new std::uniform_real_distribution<double>(-50.0, 50.0))
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
        , rd(new std::uniform_real_distribution<double>(0.5, 1.5))
{
    // do nothing
}

void AlterPositionFunctor::operator()(EllipsesGenotype::Collection& genotype, Ellipse& ellipse) const
{
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
    AlterPositionFunctor alterPosition(*ellipseGenerator, *prng);
    AlterSizeFunctor alterSize(*ellipseGenerator, *prng);
    Ellipse e(ellipse);
    alterPosition(genotype, e);
    alterSize(genotype, e);
    genotype.push_back(e);
}

void RemoveFromBackFunctor::operator()(EllipsesGenotype::Collection& genotype, Ellipse& ellipse) const
{
    genotype.erase(genotype.begin());
}

void RemoveFromFrontFunctor::operator()(EllipsesGenotype::Collection& genotype, Ellipse& ellipse) const
{
    genotype.erase(std::prev(genotype.end()));
}

RemoveRandomFunctor::RemoveRandomFunctor(std::mt19937 &prng)
        : prng(&prng)
{
    // do nothing
}

void RemoveRandomFunctor::operator()(EllipsesGenotype::Collection& genotype, Ellipse& ellipse) const
{
    genotype.erase(std::next(genotype.begin(), (*prng)() % genotype.size()));
}


