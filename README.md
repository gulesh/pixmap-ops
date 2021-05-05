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
***Following features are implemented in PPM Class:*** 

**1. Resize **

<img width="198" alt="Screen Shot 2021-05-05 at 3 12 49 PM" src="https://user-images.githubusercontent.com/60520906/117196435-77c43d00-adb4-11eb-842f-57023cea7f5b.png">

**2. Flip Horizontally**

<img width="397" alt="Screen Shot 2021-05-05 at 3 37 09 PM" src="https://user-images.githubusercontent.com/60520906/117199290-05555c00-adb8-11eb-994d-976770b88b9b.png">

**3. Gamma Corrections**
- Gamma = 0.6

<img width="398" alt="Screen Shot 2021-05-05 at 3 41 19 PM" src="https://user-images.githubusercontent.com/60520906/117199606-611fe500-adb8-11eb-9649-8898302804b4.png">

- Gamma = 2.2

<img width="401" alt="Screen Shot 2021-05-05 at 3 42 21 PM" src="https://user-images.githubusercontent.com/60520906/117199705-80b70d80-adb8-11eb-9c18-3762f2219d31.png">

**4. GrayScale**

<img width="401" alt="Screen Shot 2021-05-05 at 3 43 49 PM" src="https://user-images.githubusercontent.com/60520906/117199874-b956e700-adb8-11eb-99ad-38d7d5c0340e.png">

**5. SubImage**

<img width="97" alt="Screen Shot 2021-05-05 at 3 44 56 PM" src="https://user-images.githubusercontent.com/60520906/117199988-e1dee100-adb8-11eb-9269-2041d94c9e5a.png">


**6. Blend and Replace**

<img width="400" alt="Screen Shot 2021-05-05 at 3 46 06 PM" src="https://user-images.githubusercontent.com/60520906/117200121-1357ac80-adb9-11eb-8adc-cbd02b5b35ff.png">

## Unique features Implemented

**1. Rotate 90 degrees**

<img width="398" alt="Screen Shot 2021-05-05 at 3 48 04 PM" src="https://user-images.githubusercontent.com/60520906/117200274-4dc14980-adb9-11eb-93f4-37c4f78217cf.png">


**2. Swirl Color**

<img width="598" alt="Screen Shot 2021-05-05 at 3 49 23 PM" src="https://user-images.githubusercontent.com/60520906/117200426-7d705180-adb9-11eb-8668-f772bab3a409.png">

**3. Invert Colors**

<img width="398" alt="Screen Shot 2021-05-05 at 3 50 16 PM" src="https://user-images.githubusercontent.com/60520906/117200577-9c6ee380-adb9-11eb-8698-7322cc6f36c9.png">

**4. Distort**

<img width="402" alt="Screen Shot 2021-05-05 at 3 51 31 PM" src="https://user-images.githubusercontent.com/60520906/117200716-cc1deb80-adb9-11eb-8f21-5878ff85dec0.png">

**5. Extract Red, Green and Blue**
- Red

<img width="399" alt="Screen Shot 2021-05-05 at 3 53 00 PM" src="https://user-images.githubusercontent.com/60520906/117200995-21f29380-adba-11eb-923b-39b13b0a5403.png">

- Green

<img width="399" alt="Screen Shot 2021-05-05 at 3 53 19 PM" src="https://user-images.githubusercontent.com/60520906/117201025-2919a180-adba-11eb-9701-13fd55286583.png">

- Blue

<img width="399" alt="Screen Shot 2021-05-05 at 3 53 36 PM" src="https://user-images.githubusercontent.com/60520906/117201056-333ba000-adba-11eb-94f7-ac3dfa02c2e6.png">

**6. Lightest**

<img width="402" alt="Screen Shot 2021-05-05 at 3 55 22 PM" src="https://user-images.githubusercontent.com/60520906/117201295-801f7680-adba-11eb-80f7-8d26860ef3e3.png">

**7. Darkest**

<img width="400" alt="Screen Shot 2021-05-05 at 3 55 51 PM" src="https://user-images.githubusercontent.com/60520906/117201334-8a417500-adba-11eb-9cf7-79893a84fad0.png">

**8. Difference**

<img width="397" alt="Screen Shot 2021-05-05 at 3 56 08 PM" src="https://user-images.githubusercontent.com/60520906/117201387-988f9100-adba-11eb-93dc-dea8d0a97cef.png">


**9. Multiply**

<img width="401" alt="Screen Shot 2021-05-05 at 3 56 24 PM" src="https://user-images.githubusercontent.com/60520906/117201462-a9d89d80-adba-11eb-9e98-5525fb455dd8.png">


## Results

**ORIGINAL IMAGE**

<img width="558" alt="Screen Shot 2021-05-05 at 4 05 17 PM" src="https://user-images.githubusercontent.com/60520906/117202374-bad5de80-adbb-11eb-97a3-74574e916bfb.png">

**Invertion Applied to the Original Image**

<img width="559" alt="Screen Shot 2021-05-05 at 4 07 16 PM" src="https://user-images.githubusercontent.com/60520906/117202586-fd97b680-adbb-11eb-8d79-62a2611b1b0f.png">

**Swirl Color applied to Original Image**

<img width="558" alt="Screen Shot 2021-05-05 at 4 08 23 PM" src="https://user-images.githubusercontent.com/60520906/117202713-2324c000-adbc-11eb-8285-c359343f5563.png">

**Red Extracted from the Original Image**

<img width="556" alt="Screen Shot 2021-05-05 at 4 09 35 PM" src="https://user-images.githubusercontent.com/60520906/117202849-510a0480-adbc-11eb-8eef-08f784056120.png">

**Green Extracted from the Original Image**

<img width="560" alt="Screen Shot 2021-05-05 at 4 10 24 PM" src="https://user-images.githubusercontent.com/60520906/117202971-7ac32b80-adbc-11eb-8120-2aac9dc72f10.png">

**Blue Extracted from the Original Image**

<img width="559" alt="Screen Shot 2021-05-05 at 4 11 30 PM" src="https://user-images.githubusercontent.com/60520906/117203057-93cbdc80-adbc-11eb-814e-a0033a232ad9.png">

**Distortion Applied to the original Image**

<img width="555" alt="Screen Shot 2021-05-05 at 4 13 03 PM" src="https://user-images.githubusercontent.com/60520906/117203256-cd044c80-adbc-11eb-9d90-5ed3295101ca.png">

**Gamma correction applied to the original Image**

<img width="558" alt="Screen Shot 2021-05-05 at 4 14 38 PM" src="https://user-images.githubusercontent.com/60520906/117203444-03da6280-adbd-11eb-8bcd-ed39a1a68c91.png">
 
**Swirl color applied to the Image on which invert color was applied**

<img width="557" alt="Screen Shot 2021-05-05 at 4 16 28 PM" src="https://user-images.githubusercontent.com/60520906/117203663-456b0d80-adbd-11eb-99f5-2dd3e0b51a21.png">

**Difference applied to the Image on which invert color was applied**

<img width="558" alt="Screen Shot 2021-05-05 at 4 17 35 PM" src="https://user-images.githubusercontent.com/60520906/117203775-70edf800-adbd-11eb-8ae8-7f2544b743e9.png">

**Rotation-90 degees applied to the above image**

<img width="980" alt="Screen Shot 2021-05-05 at 4 20 01 PM" src="https://user-images.githubusercontent.com/60520906/117204036-c32f1900-adbd-11eb-807b-4d8e41a125e8.png">

**Distortion applied after applying difference on color inverted images**

<img width="983" alt="Screen Shot 2021-05-05 at 4 22 06 PM" src="https://user-images.githubusercontent.com/60520906/117204258-11441c80-adbe-11eb-9d33-dc684e2629a7.png">









