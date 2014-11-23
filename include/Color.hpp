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

#include <random>

/*!
    Struct used to represent color.
 */
struct Color {
private:
    const unsigned int MIN_VALUE = 0;
    const unsigned int MAX_VALUE = 255;

    /*!
        Empty constructor to prevent compiler from generating it's own
     */
    Color() {
        // do nothing
    }

public:
    unsigned int r;
    unsigned int g;
    unsigned int b;

    /*!
        Constructor used to instantiate colors with values from MIN_VALUE, MAX_VALUE range

        @param rnd Pseudorandom engine used to instantiate values
     */
    Color(std::mt19937 &rnd) {
        std::uniform_int_distribution<> dis(MIN_VALUE, MAX_VALUE);

        r = static_cast<unsigned int>(dis(rnd));
        g = static_cast<unsigned int>(dis(rnd));
        b = static_cast<unsigned int>(dis(rnd));
    }

    /*!
        Constructor used to instantiate values with given parameters

        @param r,g,b Values to instantiate with
     */
    Color(unsigned int r, unsigned int g, unsigned int b) : r(r), g(g), b(b) {
        // do nothing
    }
};
