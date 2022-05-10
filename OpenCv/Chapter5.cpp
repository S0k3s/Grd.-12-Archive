#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

// Warp Images

int main() {

	string path = "Resources/cards.jpg";

	Mat img = imread(path);
	float w = 250, h = 350;
	Mat matrix, imgWarp, matrix2, imgWarp2;

	Point2f src[4] = { {529, 142}, {771, 190}, {405, 395}, {674, 457} };
	Point2f src2[4] = { { 777, 107 },{ 1020, 84 },{ 842, 357 },{ 1115, 331 } };
	Point2f dst[4] = { { 0.0f, 0.0f },{ w, 0.0f },{ 0.0f, h },{ w, h } };
	Point2f dst2[4] = { { 0.0f, 0.0f },{ w, 0.0f },{ 0.0f, h },{ w, h } };

	matrix = getPerspectiveTransform(src, dst);
	warpPerspective(img, imgWarp, matrix, Point(w, h));

	matrix2 = getPerspectiveTransform(src2, dst2);
	warpPerspective(img, imgWarp2, matrix2, Point(w, h));

	for (int i = 0; i < 4; i++) {
		circle(img, src[i], 10, Scalar(0, 69, 255), FILLED);
		circle(img, src2[i], 10, Scalar(0, 69, 255), FILLED);
	}

	imshow("Image", img);
	imshow("Image Warp", imgWarp);
	imshow("Image Warp 2", imgWarp2);
	waitKey(0);
	return 0;
}