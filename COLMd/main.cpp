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
	cout << "COLMd" << endl << endl;
	std::string asd = argv[0];
	std::string treatedFolder = asd.erase(asd.rfind('\\'));
	cout << "Folder: [" << treatedFolder << "]" << endl;
	colmed mColmed(argv[0]);
	system("pause");
	//Load_aux(path_Recebido, LDados);
}
