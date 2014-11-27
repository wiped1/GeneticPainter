/*
The MIT License (MIT)

Copyright (c) <year> <copyright holders>

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
*/

#pragma once

#include <random>

#include "Vector2.hpp"
#include "Color.hpp"

/*!
    Struct containing values describing an ellipse.
 */
struct Ellipse {
    Vector2 position;
    unsigned int diameter;
    Color color;

    /*!
        Deleted constructor to prevent compiler from generating it's own
     */
    Ellipse() = delete;

    /*!
        Constructor used to instantiate ellipse with random values

        @param rnd Pseudorandom engine used to instantiate values
     */
    Ellipse(std::mt19937 &rnd, unsigned int maxDiameter, int maxWidth, int maxHeight)
            : color(rnd), position() {
        std::uniform_int_distribution<> diameterDistribution(0, maxDiameter);
        std::uniform_int_distribution<> widthDistribution(0, maxWidth);
        std::uniform_int_distribution<> heightDistribution(0, maxHeight);

        diameter = static_cast<unsigned int>(diameterDistribution(rnd));
        position.x = widthDistribution(rnd);
        position.y = heightDistribution(rnd);

    }
};
