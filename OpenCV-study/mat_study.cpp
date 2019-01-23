#include<opencv2/opencv.hpp>

#include<iostream>

using namespace cv;
using namespace std;

int main()
{
	// CV_[The number of bits per item][Signed or Unsigned][Type Prefix]C[The channel number]
	Mat M(2, 2, CV_8UC3, Scalar(0, 0, 255));
	cout << "M = " << endl << " " << M << endl << endl;
	waitKey(0);
	return 0;
}