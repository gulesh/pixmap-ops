#include "ppm_image.h"
#include <string>
#include <fstream>
#include <iostream>

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
   // todo: your code here
   imageHeight = orig.imageHeight;
   imageWidth = orig.imageWidth;
   pixelArray = orig.pixelArray; 
   return *this;   
}

ppm_image::~ppm_image()
{
   
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
            //unsigned char r, g, b;
            //r value of the pixel
            file >> pixel ;
            tempPixel.r = (unsigned char) pixel;
            cout << tempPixel.r << "   -> pixel r value  -> the output file value ->" << pixel << endl;
            //g value of the pixel
            file >> pixel ;
            tempPixel.g =  (unsigned char) pixel;
            cout<< tempPixel.g <<"   -> pixel g value  -> the output file value ->" << pixel << endl;
            //b value of the pixel
            file >> pixel ;
            tempPixel.b =  (unsigned char) pixel; 
            cout<< tempPixel.b <<"   -> pixel b value  -> the output file value ->" << pixel << endl;
            //pixel with r,g,b valus stored in the 2D array
            pixelArray[j][k]= tempPixel;  
         }
      }
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
   file << p3; //this will store "P3"
   file << imageWidth; //width
   file << imageHeight; //height
   int value = 255;
   file << value; //this will give the number 255
   
   for (int j = 0; j < imageHeight; j++) //rows
   {
      for (int k = 0; k < imageWidth; k++) //columns
      {
         ppm_pixel tempPixel;
         pixelArray[j][k]= tempPixel;  
         //r value of the pixel stored in the file
         file << tempPixel.r; 
         //g value of the pixel stored in the file
         file << tempPixel.g ;
         //b value of the pixel stored in the file
         file << tempPixel.b ;
         }
      }
   file.close();
   return 0;
}

 ppm_image ppm_image::resize(int w, int h) const
{
    ppm_image result;
    return result;
}

ppm_image ppm_image::flip_horizontal() const
{
    ppm_image result;
    return result;
}

ppm_image ppm_image::subimage(int startx, int starty, int w, int h) const
{
    ppm_image result;
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
   ppm_image result;
   return result;
}

ppm_image ppm_image::grayscale() const
{
   ppm_image result;
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
