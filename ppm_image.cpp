#include "ppm_image.h"
#include <string>
#include <fstream>
#include <iostream>
#include <cmath>
#include <algorithm> 

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
   //clear();
   pixelArray = new ppm_pixel*[h];
   for (int i =0; i<h ;i++)
   {
      pixelArray[i] = new ppm_pixel[w];
   }

}

ppm_image::ppm_image(const ppm_image& orig)
{
   //clear();
   imageWidth = orig.imageWidth;
   imageHeight = orig.imageHeight;
   pixelArray = new ppm_pixel*[imageHeight];
   for (int i =0; i<imageHeight ;i++)
   {
      pixelArray[i] = new ppm_pixel[imageWidth];
   }
   for (int j = 0; j < imageHeight; j++) //rows
   {
      for (int k = 0; k < imageWidth; k++) //columns
      {
         pixelArray[j][k]= orig.pixelArray[j][k];  
      }
   }
}

ppm_image& ppm_image::operator=(const ppm_image& orig)
{
   if (&orig == this) // protect against self-assignment
   {
      return *this;
   }
   //clear();
   imageHeight = orig.imageHeight;
   imageWidth = orig.imageWidth;
   pixelArray = new ppm_pixel*[imageHeight];
   for (int i =0; i<imageHeight ;i++)
   {
      pixelArray[i] = new ppm_pixel[imageWidth];
   }
   for (int j = 0; j < imageHeight; j++) //rows
   {
      for (int k = 0; k < imageWidth; k++) //columns
      {
         pixelArray[j][k]= orig.pixelArray[j][k];  
      }
   }
   return *this;   
}

void ppm_image::clear()
{
   
   //pixelArray = nullptr;

}
ppm_image::~ppm_image()
{
   for (int i = 0; i < imageHeight; i++)
   {
         delete[] pixelArray[i];
   }
   delete[] pixelArray;
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

   //memory cleaning
   //clear();

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
    ppm_image  result =  ppm_image( w,  h); 
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
    ppm_image result = ppm_image(imageWidth,imageHeight);
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
   ppm_image result = ppm_image(w,h);
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
   for (int i = 0 ; i < image.imageHeight; i++)
   {
      for (int j = 0; j < image.imageWidth ;j++)
      {
         pixelArray[i+starty][j+startx] = image.pixelArray[i][j];
      }
   }
   
}

ppm_image ppm_image::alpha_blend(const ppm_image& other, float alpha) const
{
   int blendedR, blendedG, blendedB;
   ppm_image result = ppm_image(imageWidth,imageHeight);
   for (int i = 0 ; i < imageHeight; i++)
   {
      for (int j = 0; j < imageWidth ;j++)
      {
         blendedR = (int) ( ((float) (pixelArray[i][j].r )) * (1 - alpha) + ((float) ( other.pixelArray[i][j].r)) * alpha ) ;
         blendedG = (int) ( ((float) (pixelArray[i][j].g )) * (1 - alpha) + ((float) ( other.pixelArray[i][j].g)) * alpha ) ;
         blendedB = (int) ( ((float) (pixelArray[i][j].b )) * (1 - alpha) + ((float) ( other.pixelArray[i][j].b)) * alpha ) ;
         //setting new pixel color
         result.pixelArray[i][j].r = (unsigned char) blendedR;
         result.pixelArray[i][j].g = (unsigned char) blendedG;
         result.pixelArray[i][j].b = (unsigned char) blendedB;
      }
   }
   return result;
}


ppm_image ppm_image::gammaCorrect(float gamma) const
{
   int gCorrectedR, gCorrectedG, gCorrectedB;
   ppm_image result = ppm_image(imageWidth,imageHeight);
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
   ppm_image result = ppm_image(imageWidth,imageHeight);
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


ppm_image ppm_image::swirlColors() const
{
   ppm_pixel tempPixel;
   ppm_image result = ppm_image(imageWidth,imageHeight);
   for (int i = 0 ; i < imageHeight; i++)
    {
       for (int j = 0; j < imageWidth ;j++)
       {
         result.pixelArray[i][j] = pixelArray[i][j];
         tempPixel.r = result.pixelArray[i][j].r ;
         result.pixelArray[i][j].r = result.pixelArray[i][j].g;
         result.pixelArray[i][j].g = result.pixelArray[i][j].b;
         result.pixelArray[i][j].b = tempPixel.r;
       }
    }
    return result;
}


ppm_image ppm_image::distortImage() const
{
   ppm_image result = ppm_image(imageWidth,imageHeight);
   for (int i = 0 ; i < imageHeight; i++)
    {
       for (int j = 0; j < imageWidth ;j++)
       {
         int distorted_j = (j + (int) (20*sin(i/10)) + imageWidth) % imageWidth;
         int distorted_i = (i + (int) (20*cos(j/10)) + imageHeight) % imageHeight;
         result.pixelArray[i][j] = pixelArray[distorted_i][distorted_j];
       }
    }
    return result;
}


ppm_image ppm_image::invertColor() const
{
   int modifiedR, modifiedG, modifiedB;
   ppm_image result = ppm_image(imageWidth,imageHeight);
    for (int i = 0 ; i < imageHeight; i++)
    {
       for (int j = 0; j < imageWidth ;j++)
       {
         modifiedR =  255 - (int) pixelArray[i][j].r ;
         modifiedG =  255 - (int) pixelArray[i][j].g ;
         modifiedB =  255 - (int) pixelArray[i][j].b ;
         //setting new pixel color
         result.pixelArray[i][j].r = (unsigned char) modifiedR;
         result.pixelArray[i][j].g = (unsigned char) modifiedG;
         result.pixelArray[i][j].b = (unsigned char) modifiedB;
       }
    }
    return result;
}

ppm_image ppm_image::rotate90() const
{  
   int oldPixelC = 0;
   ppm_image result = ppm_image(imageHeight,imageWidth);
   for (int i = 0 ; i < imageWidth; i++)
   {
      int oldPixelR = imageHeight -1;
      for (int j = 0; j < imageHeight ;j++)
      {
         result.pixelArray[i][j] = pixelArray[oldPixelR][oldPixelC];
         oldPixelR -= 1;
      }
      oldPixelC += 1;
   }
   return result;
}

ppm_image ppm_image::redOnly(const ppm_image& other) const
{
   ppm_image result = ppm_image(imageWidth,imageHeight);
   for (int i = 0 ; i < imageHeight; i++)
    {
       for (int j = 0; j < imageWidth ;j++)
       {
         result.pixelArray[i][j].r = std::max(pixelArray[i][j].r, other.pixelArray[i][j].r);
       }
    }
    return result;
}

ppm_image ppm_image::lightest(const ppm_image& other) const
{
   ppm_image result = ppm_image(imageWidth,imageHeight);
   for (int i = 0 ; i < imageHeight; i++)
    {
       for (int j = 0; j < imageWidth ;j++)
       {
         result.pixelArray[i][j].r = std::max(pixelArray[i][j].r, other.pixelArray[i][j].r);
         result.pixelArray[i][j].g = std::max(pixelArray[i][j].g, other.pixelArray[i][j].g);
         result.pixelArray[i][j].b = std::max(pixelArray[i][j].b, other.pixelArray[i][j].b);
       }
    }
    return result;
}

ppm_image ppm_image::darkest(const ppm_image& other) const
{
   ppm_image result = ppm_image(imageWidth,imageHeight);
   for (int i = 0 ; i < imageHeight; i++)
    {
       for (int j = 0; j < imageWidth ;j++)
       {
         result.pixelArray[i][j].r = std::min(pixelArray[i][j].r, other.pixelArray[i][j].r);
         result.pixelArray[i][j].g = std::min(pixelArray[i][j].g, other.pixelArray[i][j].g);
         result.pixelArray[i][j].b = std::min(pixelArray[i][j].b, other.pixelArray[i][j].b);
       }
    }
    return result;
}
ppm_image ppm_image::difference(const ppm_image& other) const
{
   ppm_image result = ppm_image(imageWidth,imageHeight);
   for (int i = 0 ; i < imageHeight; i++)
    {
       for (int j = 0; j < imageWidth ;j++)
       {
         result.pixelArray[i][j].r = std::min(0, pixelArray[i][j].r - other.pixelArray[i][j].r);
         result.pixelArray[i][j].r = std::min(0, pixelArray[i][j].r - other.pixelArray[i][j].r);
         result.pixelArray[i][j].r = std::min(0, pixelArray[i][j].r - other.pixelArray[i][j].r);
       }
    }
    return result;
}

ppm_image ppm_image::multiply(const ppm_image& other) const
{
   ppm_image result = ppm_image(imageWidth,imageHeight);
   for (int i = 0 ; i < imageHeight; i++)
    {
       for (int j = 0; j < imageWidth ;j++)
       {
         result.pixelArray[i][j].r = std::max(255, pixelArray[i][j].r * other.pixelArray[i][j].r);
         result.pixelArray[i][j].r = std::max(255, pixelArray[i][j].g * other.pixelArray[i][j].g);
         result.pixelArray[i][j].r = std::max(255, pixelArray[i][j].b * other.pixelArray[i][j].b);
       }
    }
    return result;
}

//not working as expected need to edit
ppm_image ppm_image::addBorder() const
{  
   int resultImageH = imageHeight+2;
   int resultImageW = imageWidth+2 ;
   ppm_pixel p{(unsigned char)255,(unsigned char) 255,(unsigned char) 255};
   ppm_image result = ppm_image(resultImageW,resultImageH);
   for (int i = 0 ; i < resultImageH; i++)
   {
      if(i == 0 || i == resultImageH -1)
      {
         for (int j = 0; j < resultImageW ;j++)
         {
            result.pixelArray[i][j] = p;
         }
      }
      else
      {
         for (int j = 0; j < resultImageW ;j++)
         {
            if((j == 0) || (j == resultImageW-1))
            {
               result.pixelArray[i][j] = p;
            }
            else
            {
               result.pixelArray[i][j] = pixelArray[i+1][j+1];
            }
         }
      }  
   }
   return result;
}

ppm_image ppm_image::redExtract() const
{
   int red =0;
   int blue =0;
   int green =0;
   ppm_image result = ppm_image(imageWidth,imageHeight);
   for (int i = 0 ; i < imageHeight; i++)
    {
       for (int j = 0; j < imageWidth ;j++)
       {
         result.pixelArray[i][j] = pixelArray[i][j];
         red = (int) result.pixelArray[i][j].r ;
         green = (int) result.pixelArray[i][j].g;
         blue = (int) result.pixelArray[i][j].b;
         if (red > 100 && ((blue <100) || (green < 100)))
         {
            result.pixelArray[i][j].g = (unsigned) 0;
            result.pixelArray[i][j].b = (unsigned) 0;

         }
         result.pixelArray[i][j].r = (unsigned) 0;
         result.pixelArray[i][j].g = (unsigned) 0;
         result.pixelArray[i][j].b = (unsigned) 0;
       }
    }
    return result;

}
