#include<opencv2/opencv.hpp>

#include<string>

using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
	String imageName("./image/1.jpg");
	if (argc > 1)
	{
		imageName = argv[1];
	}
	Mat image;
	image = imread(imageName, IMREAD_COLOR);
	if (!image.data)
	{
		cout << "No images!" << endl;
		return -1;
	}

	Mat gray_image;
	cvtColor(image, gray_image, COLOR_BGR2GRAY);

	imwrite("./image/1_gray_image.jpg", gray_image);

	namedWindow(imageName, WINDOW_AUTOSIZE);
	namedWindow("gray image", WINDOW_AUTOSIZE);

	waitKey(0);
}