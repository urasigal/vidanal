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
#include <stdio.h>
#include <string.h>
#include <cstdlib>

using namespace cv;

class VideoStreamer {

public:
	VideoCapture *capPtr;

	Mat image;

	VideoStreamer(const char* fileName);

	void writeImageToFile(std::string fileName, Mat image);

	Mat getMatFromFile(const char* fileName);

	Mat getNextFame();

	void insertSmalltoBigImage( Mat *small, Mat *big);

};

#endif /* VIDEOSTREANER_H_ */
