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

int main( int argc, const char* argv[] )
{
	VideoStreamer 	videoStreamer("./udp.ts");

	Mat 			frame 			= 	videoStreamer.getNextFame();

	videoStreamer.writeImageToFile(std::string("./procimages/im.png"), frame);
}
