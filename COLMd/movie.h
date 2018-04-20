#ifndef __MOVIE
#define __MOVIE

#include <iostream>
#include <string>
#include <filesystem>
#include <fstream>
#include <list>
#include <sstream>
using namespace std;

class movie
{
private:
	string mName;
	int mviewed;

public:
	movie();
	movie(string name);

	~movie();
	
	/* Getter's and Setter's */
	void setName(string name);
	void setViewed();
	string getName();
	int getViewed();

};


#endif // !__MOVIE
