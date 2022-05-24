#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include <opencv2/bgsegm.hpp>
#include <opencv2/video/background_segm.hpp>
#include <conio.h>
#include <ctime>

using namespace std;
using namespace cv;
using namespace cv::bgsegm;

Ptr<BackgroundSubtractor> pointer;

bool objectMove = false; 

Mat img, dil, mask, canny;

void getContours(Mat imgDil, Mat img) {

	vector<vector<Point>> contours;
	vector<Vec4i> hierarchy;

	findContours(imgDil, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);

	vector<vector<Point>> conPoly(contours.size());
	vector<Rect> boundRect(contours.size());
	string objectType;

	for (int i = 0; i < contours.size(); i++) {

		int area = contourArea(contours[i]);
		cout << area << endl;

		if (area > 200) {

			float peri = arcLength(contours[i], true);
			approxPolyDP(contours[i], conPoly[i], 0.02 * peri, true);
			cout << conPoly[i].size() << endl;
			boundRect[i] = boundingRect(conPoly[i]);

			// rectangle(img, boundRect[i].tl(), boundRect[i].br(), Scalar(0, 255, 0), 5);
			// drawContours(img, conPoly, i, Scalar(255, 0, 255), 2);

			time_t timeStamp = time(0);
			struct tm now;
			localtime_s(&now, &timeStamp);
			string theTime = to_string(now.tm_hour) + ":" + to_string(now.tm_min) + ":" + to_string(now.tm_sec);
			putText(img, theTime, { 20, 20 }, FONT_HERSHEY_PLAIN, 1, Scalar(0, 0, 0), 2);

			objectMove = true;
			break;
		}
		else {
			objectMove = false;
		}
	}
}

void processImg(Mat kernel, VideoCapture cap) {


	cap.read(img);
	pointer->apply(img, mask);
	dilate(mask, dil, kernel);
	Canny(dil, canny, 200, 500);

}

int main() {

	VideoCapture cap(0);
	pointer = createBackgroundSubtractorMOG2(500, 50); // creating the background subtractor

	int frame_width = cap.get(CAP_PROP_FRAME_WIDTH); // finding webcam width
	int frame_height = cap.get(CAP_PROP_FRAME_HEIGHT); // finding webcam height
	Mat kernel = getStructuringElement(MORPH_RECT, Size(2, 2));

	time_t timeStamp = time(0);
	struct tm now;
	localtime_s(&now, &timeStamp);
	cv::String date = to_string(now.tm_year + 1900) + "_" + to_string(now.tm_mon + 1) + "_" + to_string(now.tm_mday) + ".mp4";

	VideoWriter video(date, VideoWriter::fourcc('m', 'p', '4', 'v'), 30, Size(frame_width, frame_height), true); // hdv1

	while (!_kbhit()){

		processImg (kernel, cap);

		getContours(dil, img);

		if (objectMove == true) {

			while (objectMove == true) {
				video.write(img);
				processImg(kernel, cap);
				getContours(dil, img);

				// imshow("Image", img);
				// imshow("Mask", mask);
				// imshow("Dilate", dil);
				// imshow("Canny", canny);
				waitKey(1);

			}
		}

		// imshow("Image", img);
		// imshow("Mask", mask);
		// imshow("Dilate", dil);
		// imshow("Canny", canny);
		waitKey(1);
	}
	video.release();

	return 0;
}