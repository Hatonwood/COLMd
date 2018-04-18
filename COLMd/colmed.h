#ifndef __colmed
#define __colmed

#include <iostream>
#include <string>
#include <filesystem>
#include <fstream>
#include <list>
#include <sstream>
using namespace std;

class colmed
{
private:
	string m_path;
public:
	colmed(string path);
	~colmed();
	bool Scan();
};

#endif // !__colmed
