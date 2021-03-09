# pixmap-ops

Image manipulation demos based on the PPM image format.

TODO: Add a representative image for your project here

## How to build

*Windows*

Open git bash to the directory containing this repository.

```
pixmap-ops $ mkdir build
pixmap-ops $ cd build
pixmap-ops/build $ cmake -G "Visual Studio 16 2019" ..
pixmap-ops/build $ start Pixmap-Ops.sln
```

Your solution file should contain two projects: `pixmap_art` and `pixmap_test`.
To run from the git bash command shell, 

```
pixmap-ops/build $ ../bin/Debug/pixmap_test
pixmap-ops/build $ ../bin/Debug/pixmap_art
```

*macOS*

Open terminal to the directory containing this repository.

```
pixmap-ops $ mkdir build
pixmap-ops $ cd build
pixmap-ops/build $ cmake ..
pixmap-ops/build $ make
```

To run each program from build, you would type

```
pixmap-ops/build $ ../bin/pixmap_test
pixmap-ops/build $ ../bin/pixmap_art
```

## Image operators

TODO: Document the features of your PPM image class here. Include example images.

Following features are implemented in PPM Class:
1. Rotate 90 Degree
2. Swirl colors
3. Invert colors
4. Distort
5. Extract the red channel
6. Extract the blue channel 
7. Extract the green channel
8. Lightest
9. Darkest
10. Difference
11. Multiply
12. Red Only : In the filter I only selected the max red color from two images and did not edit the g or b values

// I used a different image for fifth Part of the assignment.
    
    //LAYER ONE CHANGES
    //1.1.invert Image
    //1.2.swirl color Image
    //1.3.red Extract Image
    //1.4.blue extract Image
    //1.5.green extract
    //1.6.Red Only extract
    //1.7.distort Image
    //1.8.invert Image

    //LABEL 2 CHANGES
    //2.1 swirl color - inverted Image
    //2.2 difference - inverted image

    //LABEL 3 CHANGES
    //3.1 Rotate - differenced image
    //3.2 distort - swirled2 image

    //LABEL FOUR CHANGES
    //4.1 dirtort - rotated image


## Results
1. "imagePart5-inverted-image.ppm"
2. "imagePart5-swirled-image.ppm"
3. "imagePart5-redextracted-image.ppm"
4. "imagePart5-blueextracted-image.ppm"
5. "imagePart5-greenextracted-image.ppm"
6. "imagePart5-redOnly-image.ppm"
7. "imagePart5-distortOriginal-image.ppm"
8. "imagePart5-gammaCorrected-image.ppm"
9. "imagePart5-swirled-image2.ppm"
10. "imagePart5-differenced-image.ppm"
11. "imagePart5-rotated-image.ppm"
12. "imagePart5-distorted-image.ppm"
13. "imagePart5-distorted-image2.ppm"


