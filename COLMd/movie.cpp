#include "movie.h"


movie::movie()
{

}

movie::movie(string name)
{
	this->mName = name;
	this->mviewed = 0;
}

movie::movie(string name, int status)
{
	this->mName = name;
	this->mviewed = status;
}


movie::~movie()
{
}

/* Getter's and Setter's */

/* Name Set */
void movie::setName(string name) { this->mName = name; }
/* Viewed Set */
void movie::setViewed() { this->mviewed = !mviewed; }
/* Name Get */
string movie::getName() { return mName; }
/* Viewed Get */
int movie::getViewed() { return mviewed; }
