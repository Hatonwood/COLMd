#include "colmed.h"

colmed::colmed(string path)
{
	this->mpath = path;
}


colmed::~colmed()
{

}

bool colmed::Scan()
{
	if (mpath.empty()) return false;
	movie *smovie = nullptr;
	int numberOffFiles = 0;
	for (auto & p : directory_iterator(mpath))
	{
		string name = p.path().filename().string();
		file_type CHECK = p.status().type();
		if (CHECK == file_type::regular)
		{
			/* verificar se é ficheiro video */
			smovie = new movie(name);
			mMovieList.push_back(smovie);
		}
		else 
		{
			mUnknowFiles.push_back(name);
			numberOffFiles++;
		}
	}
	if(numberOffFiles != 0)	return true;
	return false;
}



