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

#include "Catch/catch.hpp"

#include "Vector2.hpp"

SCENARIO( "Vector2 is structure used to represent position in 2d dimension", "[vector, vector2]") {
    GIVEN( "A initialized Vector2" ) {
        Vector2 position = {10, 25};

        WHEN( "The Vector2 values are copied" ) {
            int x = position.x;
            int y = position.y;

            THEN( "The copied values match those of initialized Vector2" ) {
                REQUIRE( x == position.x );
                REQUIRE( y == position.y );
            }
        }
        WHEN( "A Vector2 values are changed" ) {
            position.x = 1;
            position.y = 1;

            THEN( "New Vector2 values match those assigned" ) {
                REQUIRE( 1 == position.x );
                REQUIRE( 1 == position.y );
            }
        }
        WHEN( "A Vector2 is constructed using another Vector2" ) {
            Vector2 another = position;

            THEN( "The copied vector has exact same values" ) {
                REQUIRE( another.x == position.x );
                REQUIRE( another.y == position.y );
            }
        }
        WHEN( "A Vector2 is constructed, then another Vector2 is assigned to it") {
            Vector2 another = {123, 123};
            another = position;

            THEN( "The newly constructed Vector2 has exact same values" ) {
                REQUIRE( another.x == position.x );
                REQUIRE( another.y == position.y );
            }
            AND_THEN( "Vector2 is comparable with comparison operator" ) {
                REQUIRE ( another == position );
            }
        }
    }
}
