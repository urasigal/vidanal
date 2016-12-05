/*
 * VideoStreaner.cpp
 *
 *  Created on: Dec 5, 2016
 *      Author: yuri
 */

#include "VideoStreamer.h"


Mat VideoStreamer::getNextFame()
{

	Mat frame;
	VideoCapture cap = *capPtr;

	if(!cap.isOpened())  // check if we succeeded
			std::cout << " Failed open attempt ( getNextFame() )  \n" ;

	cap >> frame; // get a new frame from camera

	std::cout << "number of chanels is " <<  frame.channels() << " \n";

	std::cout << "matrix width  " <<  frame.rows << " \n" ;

	if(frame.empty())
	{
		std::cout << "Frame is empty  getNextFame() \n";
	     return frame;
	}
	 return frame;
}

VideoStreamer::VideoStreamer(const char *fileName)
{
	capPtr =  new VideoCapture(fileName);
	//capPtr = &cap;
}


void VideoStreamer::writeImageToFile(std::string fileName, Mat image)
{


	if(! (image.empty()))
	{
		Mat gray_image;
		cvtColor( image, gray_image, CV_BGR2GRAY );
		imwrite( fileName , gray_image );
	}
}
