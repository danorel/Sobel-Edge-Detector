//
// Created by Dan Orel on 2019-09-27.
//
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <opencv2/opencv.hpp>
#include <stdio.h>
#include <iomanip>
#include <cmath>

using namespace cv;
#ifndef SOBEL_OPERATOR_HANDS_METHODS_H
#define SOBEL_OPERATOR_HANDS_METHODS_H
Mat SobelOperator(const Mat&);
double **Gx();
double **Gy();
#endif //SOBEL_OPERATOR_HANDS_METHODS_H
