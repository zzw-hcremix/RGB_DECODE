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

#include "toolbox.hpp"

using namespace std;

int main(int argc, char **argv)
{
    if((argc == 1) || (argc == 3) || (argc > 4)) {
        help_box();
        return 0;
    }

    else if(argc == 2) {
        if(*(*(argv + 1) + 1) == 'h') { //help
            help_box();
            return 0;
        }

        else if(*(*(argv + 1) + 1) == 'v') { //version
            version_box();
            return 0;
        }

        else if((*(*(argv + 1) + 1) != 'v') || *(*(argv) + 1) != 'h') {
            help_box();
            return 0;
        }
    }

    else if(argc == 4) {
        if(*(*(argv+1) + 1) == 'd') { //decode
            if(*(*(argv + 2) + 1) == 'r') { //decode picture to RGB code...
                decode_rgb_box(*(argv + 3));
                return 0;
            }

            else if(*(*(argv + 2) + 1) == 'b') { //decode picture to BGR code...
                decode_bgr_box(*(argv + 3));
                return 0;
            }

            else if((*(*(argv + 2) + 1) != 'r') || (*(*(argv + 2) + 1) != 'b')) {
                help_box();
                return 0;
            }
        }

        else if(*(*(argv + 1) + 1) == 'e') { //encode
            if(*(*(argv + 2) + 1) == 'p') { //encode RGB/BGR code to png format pircture...
               encode_png_box(*(argv + 3));
                return 0;
            }

            else if(*(*(argv + 2) + 1) == 'j') {//encode RGB/BGR code to jpeg format pircture...
               encode_jpg_box(*(argv + 3));
                return 0;
            }

            else if((*(*(argv + 2) + 1) != 'p') || (*(*(argv + 2) + 1) != 'j')) {
                help_box();
                return 0;
            }
        }

        else if((*(*(argv) + 1) != 'd') || *(*(argv) + 1) != 'e') {
            help_box();
            return 0;
        }
    }
}

