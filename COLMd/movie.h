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
	string mNome;
	int estado;

public:
	movie();

	~movie();
	
	/* Getter's and Setter's */
	bool setNome();
	bool setEstado();
	int getNome();
	string getEstado()

};


#endif // !__MOVIE
