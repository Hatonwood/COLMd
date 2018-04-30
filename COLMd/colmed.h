#ifndef __colmed
#define __colmed

#include <iostream>
#include <string>
#include <filesystem>
#include <fstream>
#include <list>
#include <sstream>
#include <Windows.h>

using namespace std;
using namespace std::experimental::filesystem;

#include "movie.h"
#include "MyOwnUtility.h"

class colmed
{
private:
	list<movie *> mMovieList;
	list<string> mUnknowFiles;
	string mpath;
	int numberOfReadableFiles;
	int numberOfNonReadableFiles;

public:
	colmed(string path);
	~colmed();
	
	/*
	* Scan's the current Directory for movie files
	*/
	bool Scan();

	/*
	* Scan's the current Directory to check for previous Scan's
	*/
	bool DataScan();

	/*
	* Lists the movie list
	*/
	void MovieListShow();

	/*
	* Returns a string with the next movie
	*/
	movie * NextMovie();

	/*
	* Plays the next movie that has not been played yet
	*/
	void PlaynextMovie();

	/*
	* Saves the current COLMd data
	*/
	bool SaveData();

	/*
	* Saves Data to a File (MUST: SAVEDATA ALWAYS EXECUTES FIRST)
	*/
	bool SaveDataToFile(const char * file);
};

#endif // !__colmed
