//
// Created by Dan Orel on 2019-09-27.
//
#include "hands_methods.h"

Mat SobelOperator(const Mat& Image){
    const int kernel_size = 3;
    Mat ProcessedImage = Image.clone();
    int columns = Image.cols;
    int rows = Image.rows;
    int verticalBound = (kernel_size - 1) / 2;
    int horizontalBound = (kernel_size - 1) / 2;
    double **Kernel = Gx();
    for(int row = 0 + verticalBound; row < rows - verticalBound; row++){
        for(int column = 0 + horizontalBound; column < columns - horizontalBound; column++){
            float mean = 0.;
            for(int kernel_row = 0; kernel_row < kernel_size; kernel_row++){
                for(int kernel_column = 0; kernel_column < kernel_size; kernel_column++){
                    float pixel = Image.at<uchar>(kernel_row + row - verticalBound,kernel_column + column - horizontalBound) * Kernel[kernel_row][kernel_column];
                    mean += pixel;
                }
            }
            ProcessedImage.at<uchar>(row, column) = cvRound(mean);
        }
    }
    return ProcessedImage;
}

double** Gx(){
    const short size = 3;
    // Initializing the Gx
    double **Gx = new double*[size];
    for(int row = 0; row < size; row++){
        Gx[row] = new double[size];
    }
    double Gx_Temp[][size] = {
        {1, 0, -1},
        {2, 0, -2},
        {1, 0, -1}
    };
    for(int row = 0; row < size; row++){
        for(int column = 0; column < size; column++){
            Gx[row][column] = Gx_Temp[row][column];
        }
    }
    // Output Gx operator
    std::cout << "Gx operator " << std::endl;
    for(int row = 0; row < size; row++){
        for(int column = 0; column < size; column++){
            std::cout << std::left << std::setw(2) << Gx[row][column] << " ";
        }
        std::cout << std::endl;
    }
    return Gx;
}

double** Gy(){
    const short size = 3;
    // Initializing the Gy
    double **Gy = new double*[size];
    for(int row = 0; row < size; row++){
        Gy[row] = new double[size];
    }
    double Gy_Temp[][size] = {
            { 1,  2,  1},
            { 0,  0,  0},
            {-1, -2, -1}
    };
    for(int row = 0; row < size; row++){
        for(int column = 0; column < size; column++){
            Gy[row][column] = Gy_Temp[row][column];
        }
    }
    // Output Gy operator
    std::cout << "Gy operator " << std::endl;
    for(int row = 0; row < size; row++){
        for(int column = 0; column < size; column++){
            std::cout << std::left << std::setw(2) << Gy[row][column] << " ";
        }
        std::cout << std::endl;
    }
    return Gy;
}
