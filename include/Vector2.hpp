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

/*!
    Struct used to represent position in 2d space.
 */
struct Vector2 {
    /*!
        Position x in 2d space
     */
    int x;
    /*!
        Position y in 2d space
     */
    int y;

    bool operator==(const Vector2& rhs) {
        return this->x == rhs.x && this->y == rhs.y;
    }

    /*!
        Deleted constructor to prevent compiler from generating it's own
     */
    Vector2() {
        x = 0;
        y = 0;
    }

    /*!
        Constructor used to instantiate vector2 with values

        @param x x position
        @param y y position
     */
    Vector2(int x, int y) {
        this->x = x;
        this->y = y;
    }
};
