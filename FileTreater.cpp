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

	struct dirent *ent;

	if ((dir = opendir (dirName)) != NULL)
	{
	   int index = 0;
	  /* print all the files and directories within directory */
	  while ((ent = readdir (dir)) != NULL)
	  {
		files[index]  =  ( char * )  malloc(FILE_NAME_LENGTH * sizeof(char));
	    if( (strcmp(ent->d_name, ".") != 0 ) && (strcmp(ent->d_name, "..") != 0)){
	    	std::cout << "file name is " << ent->d_name  << " \n";
	    	strcpy(files[index], ent->d_name);
	    }
	  }
	  closedir (dir);
	}
	else
	{
	  /* could not open directory */
	  std::cout << "Error" ;
	}
	return files;
}
