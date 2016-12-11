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
	static int flag = 0;
	static VideoWriter *videoWriterPtr;
	if(! (image.empty()))
	{
		VideoCapture cap= *capPtr;
		Mat gray_image;
		//cvtColor( image, gray_image, CV_BGR2GRAY );
		imwrite( fileName, image );
		if(flag == 0)
		{
			int frame_width =   cap.get(CV_CAP_PROP_FRAME_WIDTH);
			int frame_height=   cap.get(CV_CAP_PROP_FRAME_HEIGHT);
			//static VideoWriter video("./sourceout/procsource.ts", CV_FOURCC('H','2','6','4'), cap.get(CAP_PROP_FPS), Size(frame_width,frame_height), true);
			static VideoWriter video("./sourceout/procsource.ts", CV_FOURCC('H','2','6','4'), 29.97 , Size(frame_width,frame_height), true);

			videoWriterPtr = &video;
			flag = 1;
		}
		videoWriterPtr -> write(image);
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

Mat VideoStreamer::cropMat(Mat imToCrop, int hight, int width)
{
	//Rect region 		= new Rect(0, 0, width, hight);
	Mat cropped         = imToCrop(Rect(0, 0, width, hight));
	//cropped.copyTo(imToCrop(region));
	return cropped;
}
