//
// Created by Mckomo on 18.04.15.
//

#pragma once

#include "Ellipse.hpp"
#include "SelectionStrategy.hpp"


class EllipsesSelectionStrategy : public SelectionStrategy<Ellipse> {
private:
public:
    void eliminate(Population<Ellipse> &population, Ranking<Ellipse>::CollectionType ranking);
};
