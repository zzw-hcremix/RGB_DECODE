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
static int FILE_SIZE(const char *PATH); //jisuan yuansu ge shu

void decode_rgb_box(char *path)
{
    IplImage *img = cvLoadImage(path, 1);
    if(img == NULL) {
        cout<<"Picture Not Found \n";
        return ;
    }
    else {
        ofstream fout("RGB.txt");
        CvScalar s;
        cout<<"Start to save. Please Wait...\n";
        int q = 0;
        for(int i = 0; i < img->height; i++) {
            for(int j = 0; j < img->width; j++) {
                s = cvGet2D(img,i,j); //Gets the value of pixels in the SRC image with coordinates of (I, J).
                //s.val[2]------->R
                //s.val[1]------->G
                //s.val[0]------->B
                /* ++@++2018.5.5 zengziwen modify this++@++ */
                fout<<s.val[2]; //R
                fout<<"\n";
                fout<<s.val[1]; //G
                fout<<"\n";
                fout<<s.val[0]; //B
                fout<<"\n";
                cvSet2D(img, i, j, s);       //set the (i,j) pixel value
                q++;
            }
        }
        cout<<"Save Success！ \n";
        cout<<"Number of matrix columns:\n"<<q<<" Columns."<<'\n';
        return ;
    }

}

void decode_bgr_box(char *path)
{
    IplImage *img = cvLoadImage(path,1);
    if(img == NULL) {
        cout<<"Picture Not Found \n";
        return ;
    }
    else {
        ofstream fout("BGR.txt");
        CvScalar s;
        cout<<"\n Start to save. Please Wait...\n";
        int q = 0;
        for(int i = 0; i < img->height; i++) {
            for(int j = 0; j <img->width; j++) {
                s=cvGet2D(img, i, j); //Gets the value of pixels in the SRC image with coordinates of (I, J).
                //s.val[2]------->R
                //s.val[1]------->G
                //s.val[0]------->B
                /* ++@++2018.5.5 zengziwen modify this++@++ */
                fout<<s.val[0]; //B
                fout<<"\n";
                fout<<s.val[1]; //G
                fout<<"\n";
                fout<<s.val[2]; //R
                fout<<"\n";
                cvSet2D(img, i, j, s);       //set the (i,j) pixel value
                q++;
            }
        }
        cout<<"\n Save Success！ \n";
        cout<<"Number of matrix columns"<<q<<"columns"<<'\n';
        return ;
    }

}

void encode_png_box(char *path)
{
    int filesize = FILE_SIZE(path); //filesize
    FILE *fp = fopen(path,"r"); //file handle
    unsigned char *buff = (unsigned char*)malloc(filesize*sizeof(unsigned char)); //buff
    int i; //count
    int w, h;

    FILE *pRGB = fopen("CreatePng.png","wb");


    printf("Copy file to memory buff...\n");
    for(i = 0; i < filesize; i++) {
        fscanf(fp, "%d/n", (buff+i));
    }
    printf("Please input picture Width. Press the Enter key to end the input:\n");
    scanf("%d", &w);
    printf("please input picture Height. Press the Enter key to end the inpu:\n");
    scanf("%d", &h);
    if((w<0) && (w>16383)) {
        printf("Width Error!!\n");
        return ;
    }
    if(h < 0) {
        printf("Height Error!!\n");
        return ;
    }

    svpng(pRGB, w, h, buff, 0);
    printf("Complete png format picture generation!\n");
    fclose(pRGB);
    free(buff);
    fclose(fp);
}

void encode_jpg_box(char *path)
{
    int filesize = FILE_SIZE(path); //filesize
    FILE *fp = fopen(path,"r"); //file handle
    unsigned char *buff = (unsigned char*)malloc(filesize*sizeof(unsigned char)); //buff
    int i; //count
    int w, h;

    FILE *pRGB = fopen("CreateJpg.jpg","wb");


    printf("Copy file to memory buff...\n");
    for(i = 0; i < filesize; i++) {
        fscanf(fp, "%d/n", (buff+i));
    }
    printf("Please input picture Width. Press the Enter key to end the input:\n");
    scanf("%d", &w);
    printf("please input picture Height. Press the Enter key to end the inpu:\n");
    scanf("%d", &h);
    if((w<0) && (w>16383)) {
        printf("Width Error!!\n");
        return ;
    }
    if(h < 0) {
        printf("Height Error!!\n");
        return ;
    }

    svjpeg(pRGB, w, h, buff);
    printf("Complete jpeg foramt picture generation!\n");
    fclose(pRGB);
    free(buff);
    fclose(fp);
}

void help_box(void)
{
    printf("Usage:\n\n");
    printf("    ./DECODE_ENCODE [options] <xxx.xxx>   \n\n");
    printf("For example: ./DECODE_ENCODE -d -r picture.jpg\n\n");
    printf("options:\n");
    printf("         -d(decode picture to code) -r(rgb code)\n");
    printf("         -d(decode picture to code) -b(bgr code)\n");
    printf("         -e(encode RGB/BGR to picture) -p(generate png format picture)\n");
    printf("         -e(encode RGB/BGR to picture) -j(generate jpg format picture)\n");
    printf("         -h(to your help)\n");
    printf("         -v(version)\n\n");
    printf("NOTE:\n");
    printf("Please put the picture or TXT file in the same directory of this program, which will generate the target file under the program directory.\n");
}

void version_box(void)
{
    printf("DECODE_ENCODE version: 2.1.0 (Date 2018.5.7) on Debian 6.4.0-2\n");
}

static int FILE_SIZE(const char *PATH) //jisuan yuansu ge shu
{
    FILE *fp;
    int filesize=0;
    int a;
    fp=fopen(PATH,"r");
    while(fscanf(fp,"%d\n",&a)!=EOF)
    {
        filesize+=1;
    }
    fclose(fp);
    return filesize;
}

