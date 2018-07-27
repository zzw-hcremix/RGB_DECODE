/*
 *
 * GNU General Public License v2.0
 *
 * Copyright (c) 2018 GetBAQI
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 */


#ifndef SVJPEG_HPP
#define SVJPEG_HPP

#include <cmath>
#include <cstdint>
#include <cstdio>
#include <algorithm>
#include <initializer_list>
#include <tuple>



namespace Impl {
    std::tuple<double, double, double> rgb2ycbcr(const std::uint8_t* rgb);
    void dct(const double* input, std::int16_t* output);
}

void svjpeg(std::FILE* file, std::uint32_t width, std::uint32_t height, std::uint8_t* data);

#endif
