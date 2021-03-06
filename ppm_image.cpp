#include "ppm_image.h"
#include <string>
#include <fstream>
#include <iostream>
#include <cmath>

using namespace agl;
using namespace std;

ppm_image::ppm_image() 
{
   imageWidth = 0;
   imageHeight = 0;
   pixelArray= nullptr;

}

ppm_image::ppm_image(int w, int h) 
{
   imageWidth = w;
   imageHeight =h;
   pixelArray = new ppm_pixel*[h];
   for (int i =0; i<h ;i++)
   {
      pixelArray[i] = new ppm_pixel[w];
   }

}

ppm_image::ppm_image(const ppm_image& orig)
{
   imageWidth = orig.imageWidth;
   imageHeight = orig.imageHeight;
   pixelArray = orig.pixelArray;

}

ppm_image& ppm_image::operator=(const ppm_image& orig)
{
   if (&orig == this) // protect against self-assignment
   {
      return *this;
   }

   imageHeight = orig.imageHeight;
   imageWidth = orig.imageWidth;
   pixelArray = orig.pixelArray; 
   return *this;   
}

ppm_image::~ppm_image()
{
   for (int i = 0; i < imageHeight; i++)
   {
      delete[] pixelArray[i];
   }
   delete[] pixelArray;
   
}
ppm_image func(int w, int h)
{
  ppm_image  imageInstance =  ppm_image( w,  h); // init with width and height
   // set pixels on image
   return imageInstance;
} 

bool ppm_image::load(const std::string& filename)
{
   
   ifstream file(filename);
   cout<<"filename " << filename <<endl;
   string p3;
   int value;
   if (!file) // true if the file is valid
   {
      cout << "Cannot load file: " << filename << endl;
      return 1;
   }

   file >> p3; //this will store "P3"
   file >> value; //width
   imageWidth =  value;
   file >> value; //height
   imageHeight = value;
   file >> value; //this will give the number 255

   pixelArray = new ppm_pixel*[imageHeight];
   for (int i =0; i<imageHeight ;i++)
   {
      pixelArray[i] = new ppm_pixel[imageWidth];
   }
   while(file)
   {
      for (int j = 0; j < imageHeight; j++) //rows
      {
         for (int k = 0; k < imageWidth; k++) //columns
         {
            ppm_pixel tempPixel;
            int pixel;
            //r value of the pixel
            file >> pixel ;
            tempPixel.r = (unsigned char) pixel;
            //g value of the pixel
            file >> pixel ;
            tempPixel.g =  (unsigned char) pixel;
            //b value of the pixel
            file >> pixel ;
            tempPixel.b =  (unsigned char) pixel; 
            //pixel with r,g,b valus stored in the 2D array
            pixelArray[j][k]= tempPixel;  
         }
      }
      return 0;
   }   
   return 0;
}


bool ppm_image::save(const std::string& filename) const
{
   ofstream file(filename);
   if(!file)
   {
      return 1;
   }
   string p3 = "P3";
   file << p3 << endl; //this will store "P3"
   file << imageWidth << endl; //width
   file << imageHeight << endl; //height
   int value = 255;
   file << value << endl;//this will give the number 255
   
   for (int j = 0; j < imageHeight; j++) //rows
   {
      for (int k = 0; k < imageWidth; k++) //columns
      {
         ppm_pixel tempPixel;
         tempPixel = pixelArray[j][k]; 
         //r value of the pixel stored in the file
         file << (int) tempPixel.r <<endl; 
         //cout << (int) tempPixel.r <<endl;
         //g value of the pixel stored in the file
         file << (int) tempPixel.g << endl;
         //cout << (int) tempPixel.g <<endl;
         //b value of the pixel stored in the file
         file << (int) tempPixel.b << endl;
         //cout << (int) tempPixel.b <<endl;
         }
      }
   file.close();
   return 0;
}

 ppm_image ppm_image::resize(int w, int h) const
{
   int  oldPixelC, oldPixelR;
    ppm_image result = func(w,h);
    for (int i = 0 ; i < h; i++)
    {
       for (int j = 0; j < w ;j++)
       {
          oldPixelR = floor( (i * (imageHeight - 1))/(h-1)  );
          oldPixelC = floor( (j * (imageWidth - 1))/(w-1)   );
          result.pixelArray[i][j].r = pixelArray[oldPixelR][oldPixelC].r;
          result.pixelArray[i][j].g = pixelArray[oldPixelR][oldPixelC].g;
          result.pixelArray[i][j].b = pixelArray[oldPixelR][oldPixelC].b;
       }
    }

    return result;
}

ppm_image ppm_image::flip_horizontal() const
{
    ppm_image result = func(imageWidth,imageHeight);
    for (int i = 0 ; i <imageHeight; i++)
    {
       for (int j = imageWidth -1 ; j >= 0 ;j--)
       {
          result.pixelArray[i][imageWidth-j+1]= pixelArray[i][j];
       }
    }

    return result;
}

ppm_image ppm_image::subimage(int startx, int starty, int w, int h) const
{
    ppm_image result = func(w,h);
    for (int i = 0 ; i < h; i++)
    {
       for (int j = 0; j < w ;j++)
       {
          result.pixelArray[i][j].r = pixelArray[i+startx][j+starty].r;
          result.pixelArray[i][j].g = pixelArray[i+startx][j+starty].g;
          result.pixelArray[i][j].b = pixelArray[i+startx][j+starty].b;
       }
    }

    return result;
}

void ppm_image::replace(const ppm_image& image, int startx, int starty)
{
}

ppm_image ppm_image::alpha_blend(const ppm_image& other, float alpha) const
{
   ppm_image result;
   return result;
}

ppm_image ppm_image::gammaCorrect(float gamma) const
{
   int gCorrectedR, gCorrectedG, gCorrectedB;
   ppm_image result = func(imageWidth,imageHeight);
    for (int i = 0 ; i < imageHeight; i++)
    {
       for (int j = 0; j < imageWidth ;j++)
       {
         gCorrectedR = 255 * pow(((float) pixelArray[i][j].r)/255, 1/gamma);
         gCorrectedG = 255 * pow(((float) pixelArray[i][j].g)/255, 1/gamma);
         gCorrectedB = 255 * pow(((float) pixelArray[i][j].b)/255, 1/gamma);
         //setting new pixel color
         result.pixelArray[i][j].r = (unsigned char) gCorrectedR;
         result.pixelArray[i][j].g = (unsigned char) gCorrectedG;
         result.pixelArray[i][j].b = (unsigned char) gCorrectedB;
       }
    }
    return result;
}

ppm_image ppm_image::grayscale() const
{
   int r,g,b,weightedAvg;
   ppm_image result = func(imageWidth,imageHeight);
    for (int i = 0 ; i < imageHeight; i++)
    {
       for (int j = 0 ; j < imageWidth  ;j++)
       {
         ppm_pixel modifyingPixel = pixelArray[i][j];
         r = modifyingPixel.r;
         g = modifyingPixel.g;
         b = modifyingPixel.b;
         weightedAvg = 0.3 * r + 0.59 * g + 0.11 * b;
         modifyingPixel.b = weightedAvg;
         modifyingPixel.g = weightedAvg;
         modifyingPixel.r = weightedAvg;
         result.pixelArray[i][j] = modifyingPixel;
       }
    }
    return result;
}

ppm_pixel ppm_image::get(int row, int col) const
{
   return pixelArray[row][col];
}

void ppm_image::set(int row, int col, const ppm_pixel& c)
{
   pixelArray[row][col].r = c.r;
   pixelArray[row][col].g = c.g;
   pixelArray[row][col].b = c.b;

}

int ppm_image::height() const
{
   return imageHeight;
}

int ppm_image::width() const
{
   return imageWidth;
}

