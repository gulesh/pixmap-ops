#include <iostream>
#include "ppm_image.h"
#include <string>
#include <fstream>
#include <iostream>
#include <cmath>
#include <algorithm> 

using namespace agl;
using namespace std;

int main(int argc, char** argv)
{
    ppm_image image;
    image.load("../images/imagePart5.ppm");
    image.save("imagePart5.ppm"); // should match original
    cout << "loaded imagePart5: " << image.width() << " " << image.height() << endl;

    //LAYER ONE CHANGES
    //1.1.invert Image
    ppm_image imageInverted = image.invertColor();
    imageInverted.save("imagePart5-inverted-image.ppm");

    //1.2.swirl color Image
    ppm_image swirlImage = image.swirlColors();
    swirlImage.save("imagePart5-swirled-image.ppm");

    //1.3.red Extract Image
    ppm_image redExtractedImage = image.redExtract();
    redExtractedImage.save("imagePart5-redextracted-image.ppm");

    //1.4.blue extract Image
    ppm_image blueExtractedimage = image.blueExtract();
    blueExtractedimage.save("imagePart5-blueextracted-image.ppm");

    //1.5.green extract
    ppm_image greenExtractedImage = image.greenExtract();
    greenExtractedImage.save("imagePart5-greenextracted-image.ppm");
    
    //1.6.Red Only extract
    ppm_image redOnlyImage = image.redOnly(imageInverted);
    redOnlyImage.save("imagePart5-redOnly-image.ppm");
    
    //1.7.distort Image
    ppm_image distortOriginalImage = image.distortImage();
    distortOriginalImage.save("imagePart5-distortOriginal-image.ppm");

    //1.8.invert Image
    ppm_image gammaCorrected = image.gammaCorrect(0.6f);
    gammaCorrected.save("imagePart5-gammaCorrected-image.ppm");

    //LABEL 2 CHANGES
    //2.1 swirl color inverted Image
    ppm_image swirlImage2 = imageInverted.swirlColors();
    swirlImage2.save("imagePart5-swirled-image2.ppm");

    //2.2 difference inverted image
    ppm_image differencedImage = image.difference(imageInverted);
    differencedImage.save("imagePart5-differenced-image.ppm");

    //LABEL 3 CHANGES
    //3.1 Rotate differenced image
    ppm_image rotatedImaged = differencedImage.rotate90();
    rotatedImaged.save("imagePart5-rotated-image.ppm");

    //3.2 distort swirled2 image
    ppm_image distortedImage = swirlImage2.distortImage();
    distortedImage.save("imagePart5-distorted-image.ppm");

    //LABEL FOUR CHANGES
    //4.1 dirtort rotated image
    ppm_image distortedImage2 = rotatedImaged.distortImage();
    distortedImage2.save("imagePart5-distorted-image2.ppm");
    
}

