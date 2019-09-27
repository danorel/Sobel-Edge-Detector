//
// Created by Dan Orel on 2019-09-27.
//
#include <iostream>
#include "sobel_operator.h"

int main(){
    std::string pathToImage = "/Users/danorel/Workspace/World of C/C++/KMA/MMPI/Sobel-Operator/";
    std::string image = "image1.jpg";
    std::string ImageLabel = "Original Image";
    std::string ProcessedImageLabel = "Processed Image";

    Mat Image = imread(pathToImage + image, IMREAD_GRAYSCALE);

    SobelOperator sobel = SobelOperator(Image);
    Mat ProcessedImage = sobel.process();

    imshow(ImageLabel, Image);
    imshow(ProcessedImageLabel, ProcessedImage);
    waitKey();
    return 0;
}