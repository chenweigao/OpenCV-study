#include<opencv2/core.hpp>
#include<opencv2/core/utility.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgcodecs.hpp>
#include<iostream>
#include<sstream>

using namespace std;
using namespace cv;

Mat& ScanImageAndReduceC(Mat &I, const uchar* table);

int main(int argc, char** argv)
{
	if (argc < 3)
	{
		cout << "Not enough parameters" << endl;
		return -1;
	}

	Mat I, J;
	// return 0 if equal
	if (argc == 4 && !strcmp(argv[3], "G"))
	{
		I = imread(argv[1], IMREAD_GRAYSCALE);
	}
	else
	{
		I = imread(argv[1], IMREAD_COLOR);
	}

	if (I.empty())
	{
		cout << "Can not load the file" << argv[1] << endl;
		return -1;
	}

	// convert string to number
	int divideWith = 0;
	stringstream s;
	s << argv[2];
	s >> divideWith;
	if (!s || !divideWith)
	{
		cout << "Invaild number enterd for dividing. " << endl;
		return -1;
	}

	uchar table[256];
	for (int i = 0; i < 256; i++)
	{
		// calculate the lookup table
		table[i] = (uchar)(divideWith * (i / divideWith));
	}
}

Mat& ScanImageAndReduceC(Mat &I, const uchar* table)
{
	CV_Assert(I.depth() == CV_8U);

	int channels = I.channels();

	int nRows = I.rows;
	int nCols = I.cols;

	if (I.isContinuous())
	{
		nCols *= nRows;
		nRows = 1;
	}

	int i, j;
	uchar* p;
	for ( i = 0; i < nRows; i++)
	{
		p = I.ptr<uchar>(i);
		for ( j = 0; j < nCols; j++)
		{
			p[i] = table[p[j]];
		}
	}
	return I;
}
