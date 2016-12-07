/*
 * FileTreater.cpp
 *
 *  Created on: Dec 5, 2016
 *      Author: yuri
 */

#include  "FileTreater.h"

char ** FileTreater::getDirsFilesNames( char * dirName)
{
	DIR *dir;

	files = (char **) malloc (sizeof (char *) * NUMBER_OF_QR_FILES);

	struct dirent *ent;

	if ((dir = opendir (dirName)) != NULL)
	{
	   int index = 0;
	  /* print all the files and directories within directory */
	  while ((ent = readdir (dir)) != NULL)
	  {
		files[index]  =  ( char * )  malloc(FILE_NAME_LENGTH * sizeof(char));

		if( ( strcmp(ent->d_name, ".") != 0 ) && (strcmp(ent->d_name, "..") != 0)){
	    	strcpy( files[index] , ent->d_name );
	    	std::cout << "file name is as " << files[index]  << " FileTreater::getDirsFilesNames \n";
	    	index ++; // Increment the index.
	    }
	  } // end of while
	  closedir (dir);
	}
	else
	{
	  /* could not open directory */
	  std::cout << "Error" ;
	}
	std::cout << "Array size " << sizeof(files) << " \n";

	return files;
}
