#include "colmed.h"

colmed::colmed(string path)
{
	if (path.empty()) return;
	this->mpath = path;
	numberOfReadableFiles = 0;
	numberOfNonReadableFiles = 0;
}


colmed::~colmed()
{

}



bool colmed::Scan()
{
	movie *smovie = nullptr;
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
				numberOfReadableFiles++;
				cout << "hey";
			}
		}
		else 
		{
			mUnknowFiles.push_back(name);
			numberOfNonReadableFiles++;
		}
	}
	if(numberOfReadableFiles != 0)	return true;
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

void colmed::MovieListShow()
{
	if (this->numberOfReadableFiles == 0) return;
	std::cout << std::endl;
	std::cout << "|------------------------------" << std::endl;
	std::cout << "| Movie List" << std::endl;
	std::cout << "|------------------------------" << std::endl;
	for (list<movie *>::iterator it = mMovieList.begin(); it != mMovieList.end(); ++it)
	{
		std::cout << "|->" << (*it)->getName() << "] Viewed: [";
		if ((*it)->getViewed()) std::cout << "YES";
		else std::cout << "NO";
		std::cout << "]" << std::endl;
	}
	std::cout << "|------------------------------" << std::endl;
	std::cout << "| End of Movie List" << std::endl;
	std::cout << "|------------------------------" << std::endl;
}

movie * colmed::NextMovie()
{
	for (list<movie *>::iterator it = mMovieList.begin(); it != mMovieList.end(); ++it)
	{
		if (!((*it)->getViewed()))
		{
			return (*it);
		}
	}
	return nullptr;
}

void colmed::PlaynextMovie()
{
	//Default Installation of VLC maybe it can be asked or detected somehow later for versatility
	std::string execute = "\"\"C:\\Program Files (x86)\\VideoLAN\\VLC\\vlc.exe\" \"";
	movie * nmovie = NextMovie();
	std::string nmoviename = (nmovie->getName());
	if (nmoviename.compare("0")==0)
	{
		std::cout << "There are no movies available to see" << std::endl;
		return;
	}
	execute.append(mpath);
	execute.append("\\");
	execute.append(nmoviename);
	execute.append("\"\"");
	cout << "[" << execute << "]" << endl;
	system(execute.c_str());
	nmovie->setViewed();
}

bool colmed::SaveData()
{

}