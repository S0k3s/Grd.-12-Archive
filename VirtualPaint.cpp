#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;

// Project 1

// hmin, hmax, smin, smax, vmin, vmax

vector<vector<int>> myColours {
	{ 0, 16, 151, 255, 135, 255 }, // Orange
	{ 60, 78, 84, 156, 131, 238 }, // Green
	{ 23, 36, 110, 204, 120, 255 } // Yellow
};

vector<Scalar> myColourValues {
	{0, 128, 255}, // Orange
	{0, 153, 0}, // Green
	{0, 255, 255} // Yellow
};

vector<vector<int>> newPoints; // x, y, colour

Mat mask;

Point getContours(Mat imgDil, Mat img) {

	vector<vector<Point>> contours;
	vector<Vec4i> hierarchy;

	findContours(imgDil, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
	// drawContours(img, contours, -1, Scalar(255, 0, 255), 2);

	vector<vector<Point>> conPoly(contours.size());
	vector<Rect> boundRect(contours.size());
	string objectType;

	Point myPoint(0, 0);

	for (int i = 0; i < contours.size(); i++) {
		int area = contourArea(contours[i]);
		cout << area << endl;

		if (area > 1000) {

			float peri = arcLength(contours[i], true);
			approxPolyDP(contours[i], conPoly[i], 0.02 * peri, true);

			cout << conPoly[i].size() << endl;
			boundRect[i] = boundingRect(conPoly[i]);
			myPoint.x = boundRect[i].x + boundRect[i].width / 2;
			myPoint.y = boundRect[i].y;

			rectangle(img, boundRect[i].tl(), boundRect[i].br(), Scalar(0, 255, 0), 5);
			drawContours(img, conPoly, i, Scalar(255, 0, 255), 2);

		}
	}
	return (myPoint);
}

vector<vector<int>> findColour(Mat img) {

	Mat imgHSV;
	cvtColor(img, imgHSV, COLOR_BGR2HSV);

	for (int i = 0; i < myColours.size(); i++) {

		Scalar lower(myColours[i][0], myColours[i][2], myColours[i][4]);
		Scalar upper(myColours[i][1], myColours[i][3], myColours[i][5]);
		
		inRange(imgHSV, lower, upper, mask);
		// imshow(to_string(i), mask);

		Point myPoint = getContours(mask, img);
		if (myPoint.x != 0 && myPoint.y != 0) {
			newPoints.push_back({ myPoint.x, myPoint.y, i });
		}

	}
	return newPoints;
}

void draw(vector<vector<int>> newPoints, vector<Scalar> myColourValues, Mat img) {

	for (int i = 0; i < newPoints.size(); i++) {
		circle(img, Point(newPoints[i][0], newPoints[i][1]), 10, myColourValues[newPoints[i][2]], FILLED);
	}

}

int main() {

	VideoCapture cap(0);
	Mat img;

	while (true) {

		cap.read(img);
		newPoints = findColour(img);
		draw(newPoints, myColourValues, img);

		imshow("Image", img);
		imshow("Image Mask", mask);
		waitKey(1);

	}

	return 0;
}