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
	char opcao;
	printf("\n");
	printf("**********************");
	printf("* 1. Scan Folder *");
	printf("* 2. *");
	printf("**********************");
	gets_s(&opcao, 1);
	switch (opcao)
	{
	case '1':
		//Load();
	default: 
		printf("The chosen option is not valid!");
		break;
	}
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
	system("pause");
}
