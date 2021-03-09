#include <iostream>
#include "ppm_image.h"
using namespace std;
using namespace agl;

int main(int argc, char** argv)
{
   
   ppm_image image;
   image.load("../images/feep.ppm");
   image.save("feep-test-save.ppm"); // should match original

   // should print 4 4
   cout << "loaded feep: " << image.width() << " " << image.height() << endl;

   // test: copy constructor
   ppm_image copy = image; 
   copy.save("feep-test-copy.ppm"); // should match original and load into gimp

   // test: assignment operator
   copy = image; 
   copy.save("feep-test-assignment.ppm"); // should match original and load into gimp

   // should print r,g,b
   ppm_pixel pixel = image.get(1, 1);
   cout << (int) pixel.r << " " << (int) pixel.g << " " << (int) pixel.b << endl;

   // test: setting a color
   pixel.r = 255;
   image.set(1, 1, pixel);
   image.save("feep-test-newcolor.ppm");

   // test a non-trivial image
   image.load("../images/earth-ascii.ppm"); // a real image

   // should print 400 400
   cout << "loaded earth: " << image.width() << " " << image.height() << endl;
  
   // resize
   ppm_image resize = image.resize(200,300);
   resize.save("earth-200-300.ppm");

   // grayscale
   ppm_image grayscale = image.grayscale(); 
   grayscale.save("earth-grayscale.ppm");

   // flip horizontal
   ppm_image flip = image.flip_horizontal(); 
   flip.save("earth-flip.ppm"); 

   // sub image
   ppm_image sub = image.subimage(200, 200, 100, 100); 
   sub.save("earth-subimage.ppm"); 

   // gamma correction
   ppm_image gamma = image.gammaCorrect(0.6f); 
   gamma.save("earth-gamma-0.6.ppm"); 

   gamma = image.gammaCorrect(2.2f);
   gamma.save("earth-gamma-2.2.ppm"); 

   // alpha blend
   ppm_image soup;
   soup.load("../images/soup-ascii.ppm");


   //rotate image 90 degree clockwise
   ppm_image rotatedImage = image.rotate90();
   rotatedImage.save("earth-rotated-90.ppm");


   //distorted image earth
   ppm_image distortedImage = image.distortImage();
  distortedImage.save("earth-distorted-image.ppm");

   //inverted Image
   ppm_image earthInverted = image.invertColor();
   earthInverted.save("earth-inverted-image.ppm");

   //swirl color Image
   ppm_image swirlColoredImage = image.swirlColors();
   swirlColoredImage.save("earth-swirledcolored-image.ppm");

   //lightest extract Image
   ppm_image listestImage = image.lightest(swirlColoredImage);
   listestImage.save("earth-lightest-image.ppm");

   //darkest extract Image
   ppm_image darkestImage = image.darkest(swirlColoredImage);
   darkestImage.save("earth-darkest-image.ppm");

   
   //difference extract Image
   ppm_image differenceImage = image.difference(swirlColoredImage);
   differenceImage.save("earth-difference-image.ppm");

   //multiply extract Image
   ppm_image multiplyImage = image.multiply(distortedImage);
   multiplyImage.save("earth-multiply-image.ppm");

   //Image is just red
   ppm_image redImage = image.redOnly(distortedImage);
   redImage.save("earth-red-image.ppm");

   //red extract
   ppm_image redExtract = image.redExtract();
   redExtract.save("earth-redextract-image.ppm");

   //red extract
   ppm_image greenExtract = image.greenExtract();
   greenExtract.save("earth-greenextract-image.ppm");

   //red extract
   ppm_image blueExtract = image.blueExtract();
   blueExtract.save("earth-blueextract-image.ppm");

   int x = (int) (0.5f * (image.width() - soup.width()));
   int y = (int) (0.5f * (image.height() - soup.height()));
   cout << "loaded earth: " << soup.width() << " " << soup.height() << endl;
   ppm_image background = image.subimage(x, y, soup.width(), soup.height());
   background.save("background-test.ppm");
   ppm_image blend = background.alpha_blend(soup, 0.5f);
   image.replace(blend, x, y);
   image.save("earth-blend-0.5.ppm");
   
}

