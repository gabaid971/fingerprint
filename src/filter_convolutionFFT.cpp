/*!
 * \file filter_convolutionFFT.cpp
 * \brief Tools for filter FFT convolution.
 * \author Thu Thao Huynh
 */
 #include "filter_convolutionFFT.hpp"

#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

using namespace cv;
using namespace std;

/*!
* \fn DFT(Mat& image, Mat& kernel)
* \param image: matrix of original image
* \param kernel: matrix of kernel matrix
* \return the matrices which are discrete Fourier transform
*/
void DFT(Mat& image, Mat& kernel){
// calculate the optimal DFT size
int dftSize_col = getOptimalDFTSize(image.cols + kernel.cols - 1);
int dftSize_row = getOptimalDFTSize(image.rows + kernel.rows - 1);

//padding zero to get to optimal size
copyMakeBorder(image, image, 0, dftSize_row - image.rows, 0, dftSize_col - image.cols,0);
copyMakeBorder(kernel, kernel, 0, dftSize_row - kernel.rows, 0, dftSize_col - kernel.cols,0);

//Discrete Fourier transform image and kernel
dft(image,image);
dft(kernel,kernel);
}


/*!
* \fn inverse(Mat image, Mat kernel,Mat save)
* \param image: matrix of original image
* \param kernel: matrix of kernel matrix
* \param save: matrix of original matrix before changing anything
* \return convolution FFT matrix
*/
void inverse(Mat image, Mat kernel,Mat save)
{
	DFT(image,kernel); //function to calculate DFT

  //Multiply element with element
	Mat dst;
	mulSpectrums(image, kernel, dst,false);

  //Inverse Discrete Fourier transform
    idft(dst,dst);

	normalize(dst,dst,255,0,NORM_MINMAX,CV_32SC1);

	//Cut to get the same size with original one
	Mat O(dst,Rect(0,0,save.cols,save.rows));

	imshow( "convolution_FFT", O); //save image
  waitKey(0);
}
