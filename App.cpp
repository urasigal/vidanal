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

	VideoStreamer 	videoStreamer("./udp.ts");

	Mat 			frame 			= 	videoStreamer.getNextFame();
	Mat 			*im;

	FileTreater fileTreater;

	fileTreater.getDirsFilesNames("qrimages");


	videoStreamer.writeImageToFile(std::string("./procimages/im1.png"), frame);
	videoStreamer.writeImageToFile(std::string("./procimages/im2.png"), frame);
	videoStreamer.writeImageToFile(std::string("./procimages/im3.png"), frame);
	videoStreamer.writeImageToFile(std::string("./procimages/im4.png"), frame);
	videoStreamer.writeImageToFile(std::string("./procimages/im5.png"), frame);

//	for ( ; count < NUMBER_OF_QR_FILES ; count ++)
//	{
//		std::ostringstream name ;
//		frame              =	 videoStreamer.getNextFame() ;
//		name << "./procimages/im" << count << ".png" ;
//		videoStreamer.writeImageToFile(name.str() , frame);
//	}
}
