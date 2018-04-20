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

class colmed
{

private:
	list<movie *> mMovieList;
	list<string> mUnknowFiles;
	string mpath;

public:
	colmed(string path);
	~colmed();
	bool Scan();
};

#endif // !__colmed
