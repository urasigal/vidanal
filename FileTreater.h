/*
 * FileTreater.h
 *
 *  Created on: Dec 5, 2016
 *      Author: yuri
 */

#ifndef FILETREATER_H_
#define FILETREATER_H_

#include "Constants.h"
#include <dirent.h>
#include <iostream>
#include <string>
#include <sstream>
#include <stdio.h>
#include <string.h>
#include <cstdlib>

class FileTreater {

public:
	 char * files[NUMBER_OF_QR_FILES];

	 char ** getDirsFilesNames( char * dirName);
};

#endif /* FILETREATER_H_ */
