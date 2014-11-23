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

#define CATCH_CONFIG_MAIN
#include "Catch/catch.hpp"

#include <random>

#include "Color.hpp"

SCENARIO( "Color struct is used to represent color" ) {
    GIVEN( "A pseudorandom engine" ) {
        std::random_device rd;
        std::mt19937 gen(rd());

        WHEN( "Color is initialized with default constructor" ) {
            Color color(gen);

            THEN( "The values range from 0-255" ) {
                REQUIRE( (color.r >= 0 && color.r <= 255) );
                REQUIRE( (color.g >= 0 && color.g <= 255) );
                REQUIRE( (color.b >= 0 && color.b <= 255) );
            }
        }
        WHEN( "Color is initialized with values" ) {
            const unsigned int r = 100;
            const unsigned int g = 100;
            const unsigned int b = 100;
            Color color(r, g, b);

            THEN( "The values have proper values" ) {
                REQUIRE( color.r == r );
                REQUIRE( color.g == g );
                REQUIRE( color.b == b );
            }
        }
    }
}
