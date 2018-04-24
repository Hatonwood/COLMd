#include <iostream>
#include <string>
#include <filesystem>
#include <fstream>
#include <list>
#include <sstream>

#include "colmed.h"

using namespace std;
using namespace std::experimental::filesystem;

void menu()
{
	std::cout << "\n" << std::endl;
	std::cout << "**********************" << std::endl;
	std::cout << "* 1. Play first *" << std::endl;
	std::cout << "* 2. Play next *" << std::endl;
	std::cout << "* 0. Exit *" << std::endl;
	std::cout << "**********************" << std::endl;
}

/**
* Main Function
*/
int main(int argc, char* argv[])
{
	std::cout << std::endl << "\t*" <<"COLMd" << "*" <<std::endl << std::endl;
	std::string temp = argv[0];
	std::string treatedFolder = temp.erase(temp.rfind('\\'));
	std::cout << "Folder: [" << treatedFolder << "]" << std::endl;
	colmed mColmed(treatedFolder);
	//mColmed.DataScan();
	if (mColmed.Scan()) std::cout << "Load Sucessfull" << std::endl;
	mColmed.MovieListShow();
	int opcao;
	do { 
		menu(); 
		cin >> opcao; 
		switch (opcao)
		{
		case 1:
			std::cout << mColmed.NextMovie();
			break;

		case 2:
			mColmed.PlaynextMovie();
			break;

		case 0: 
			mColmed.SaveData();
			system("pause");
			exit(1);
			break;

		default:
			std::cout << "The chosen option is not valid!" << std::endl;
			break;
		}
	} while (opcao != 0);
}

