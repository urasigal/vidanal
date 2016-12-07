/*
 * VideoStreaner.cpp
 *
 *  Created on: Dec 5, 2016
 *      Author: yuri
 */

#include "VideoStreamer.h"

Mat VideoStreamer::getNextFame()
{
	Mat		frame;
	//VideoCapture cap = *capPtr;

	if(!(*capPtr).isOpened())  // check if we succeeded
			std::cout << " Failed open attempt ( getNextFame() )  \n" ;

	(*capPtr) >> frame; // get a new frame from camera

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


Mat VideoStreamer::getMatFromFile(const char* fileName){

	char 	*dName;
	dName = (char *)malloc(60);
	strcpy(dName, "./qrimages/");
	strcat( dName, fileName );
	std::cout <<  "Picture name is " << dName <<" \n" ;

	image = imread( dName , IMREAD_COLOR ); // Read the file

	if( image.empty() )                      // Check for invalid input
	{
		std::cout <<  "Could not open or find the image" << " \n" ;
	}

	free(dName);
	std::cout <<  "Return \n" ;
	return image;
}


void VideoStreamer::insertSmalltoBigImage(Mat *small, Mat *big)
{
	Mat smallLoc = *small;
	Mat bigLoc 	 = *big;
	smallLoc.copyTo(bigLoc(cv::Rect( 0,0, smallLoc.cols, smallLoc.rows)));
	big = &bigLoc;
}
