#ifndef __colmed
#define __colmed

#include <iostream>
#include <string>
#include <filesystem>
#include <fstream>
#include <list>
#include <sstream>

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
};

#endif // !__colmed
