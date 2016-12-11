/*
 * App.cpp
 *
 *  Created on: Dec 5, 2016
 *      Author: yuri
 */
#include "VideoStreamer.h"
#include <iostream>
#include <string>
#include <sstream>
#include "FileTreater.h"


int main( int argc, const char* argv[] )
{
	int count = 0;
	Mat frame;
	VideoStreamer 	videoStreamer("./udp.ts");
	Mat 			*im;
	Mat 			qrIm;
	FileTreater 	fileTreater;

	char **qrFiles = fileTreater.getDirsFilesNames("./qrimages");

	std::cout << "Array size " << sizeof(qrFiles) << " \n";

	videoStreamer.getMatFromFile(qrFiles[10]);
	for(int i =0; i < 10 ; i++)
	{
		videoStreamer.getMatFromFile(qrFiles[i]);
		std::cout <<  "From Return \n" ;
	}

	for ( ; count < NUMBER_OF_QR_FILES ; count ++)
	{
		std::ostringstream nameOfFileOfImageWithQrCode;

		std::ostringstream nameOfFileOfImageOnlyQrCode;

		frame  	    =	videoStreamer.getNextFame() ;

		qrIm  		= 	videoStreamer.getMatFromFile(qrFiles[count]);

		nameOfFileOfImageWithQrCode << "./procimages/im" << count << ".png" ;

		nameOfFileOfImageOnlyQrCode << "./cropped/im"    << count << ".png" ;

		videoStreamer.insertSmalltoBigImage(&qrIm, &frame);

		videoStreamer.writeImageToFile(nameOfFileOfImageWithQrCode.str() , frame);


		videoStreamer.writeImageToFile(nameOfFileOfImageOnlyQrCode.str() , videoStreamer.cropMat(frame, 87, 87));
	}
}
