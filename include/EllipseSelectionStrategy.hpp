//
// Created by Mckomo on 18.04.15.
//

#pragma once

#include <Ellipse.hpp>
#include "SelectionStrategy.hpp"


class EllipseSelectionStrategy : public SelectionStrategy<Ellipse> {

    void eliminate(Population<Ellipse> &population, typename Ranking<Ellipse>::Type ranking)
    {
        
    }

};
