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
   pixelArray = new ppm_pixel*[0];

}

ppm_image::ppm_image(int w, int h) 
{
   imageWidth = w;
   imageHeight =h;
   pixelArray = new ppm_pixel*[h];
   for(int i = 0; i < h; ++i)
   pixelArray[i] = new ppm_pixel[w];

}

ppm_image::ppm_image(const ppm_image& orig)
{

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

      cout<< "inside IF " <<endl;
      file >> p3; //this will store "P3"
      cout << "Should be P3: " << p3 << endl;
      file >> value; //width
      cout << "Should be width: " << value << endl;
      imageWidth =  value;
      file >> value; //height
      cout << "Should be height: " << value << endl;
      imageHeight = value;
      file >> value; //this will give the number 255

      while(file){
         for (ppm_pixel **j = pixelArray ; j < pixelArray + imageWidth; j++)
         {
            cout << *j <<endl;
            cout << j <<endl;
            for (ppm_pixel *k = *j; k < *j + imageHeight; k++)
            {
               cout << "entering Pixel Loop " << k <<endl; 
               ppm_pixel tempPixel;
               for (int i=0; i<3;i++){
                  cout << "inside pixel"<<endl;
                  file >> value;
                  if(i == 0)
                  {
                     tempPixel.r = value;
                     cout << "inside red"<< tempPixel.r <<endl;
                  } 
                  else if (i == 1)
                  {
                     tempPixel.g = value;
                     cout << "inside green"<< tempPixel.g <<endl;
                  }
                  else
                  {
                     tempPixel.b = value;
                      cout << "inside blue"<< tempPixel.b <<endl;
                  }  
               }
               cout << "out of pixel loop  " <<endl; 
               cout << "K" << k <<endl;
               //cout << "*K" << *k <<endl;
               cout<< &tempPixel <<endl;
               *k = tempPixel;
               cout << "K" << k <<endl;
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
      while(file)
      {

      }
   }
   return false;
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
   return pixelArray[row-1][col-1];
}

void ppm_image::set(int row, int col, const ppm_pixel& c)
{
   pixelArray[row-1][col-1].r = c.r;
   pixelArray[row-1][col-1].g = c.g;
   pixelArray[row-1][col-1].b = c.b;

}

int ppm_image::height() const
{
   return imageHeight;
}

int ppm_image::width() const
{
   return imageWidth;
}
