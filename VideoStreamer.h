/*
 * VideoStreaner.h
 *
 *  Created on: Dec 5, 2016
 *      Author: yuri
 */

#ifndef VIDEOSTREANER_H_
#define VIDEOSTREANER_H_

#include "opencv2/opencv.hpp"
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
#include <string>
#include <sstream>
#include "Constants.h"

using namespace cv;

class VideoStreamer {

public:
	VideoCapture *capPtr;

	VideoStreamer(const char* fileName);

	void writeImageToFile(std::string fileName, Mat image);

	Mat getNextFame();

};

#endif /* VIDEOSTREANER_H_ */
