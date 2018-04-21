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
		path common = p.path();
		string name = common.filename().string();
		string extension = common.extension().string();
		file_type CHECK = p.status().type();
		if (CHECK == file_type::regular)
		{
			/* verificar se é ficheiro video */
			if(MyOwnUtility::video_check(extension))
			{
			smovie = new movie(name);
			mMovieList.push_back(smovie);
			cout << "Name: [" << name << "]" << endl;
			}
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



