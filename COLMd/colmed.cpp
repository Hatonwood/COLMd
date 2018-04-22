#include "colmed.h"

colmed::colmed(string path)
{
	if (path.empty()) return;
	this->mpath = path;
}


colmed::~colmed()
{

}



bool colmed::Scan()
{
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
			if(MyOwnUtility::video_check(extension))
			{
				smovie = new movie(name);
				mMovieList.push_back(smovie);
				std::cout << "Name: [" << name << "]" << std::endl;
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

bool colmed::DataScan() 
{
	path colm_data = mpath;
	colm_data.concat("\\.colmed");
	cout << "COLM_DATA_HIDDEN_DIRECTORY: [" << colm_data << "]" << endl;
	if (exists(colm_data))
	{
		std::cout << "Found data for this directory! Loading it as fast as Usain Bolt" << std::endl;
		//Loads Data from a XML, txt or something else yet to see
		//Load_Data_XML();
		return true;
	}
	else
	{
		this->Scan();
		return false;
	}
}


