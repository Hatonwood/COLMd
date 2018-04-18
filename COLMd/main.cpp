#include <iostream>
#include <string>
#include <filesystem>
#include <fstream>
#include <list>
#include <sstream>

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
* Lê os ficheiros na directoria atual
*/
int main(int argc, char* argv[])
{
	printf("COLMd \n\n");
	printf("Folder: [%s]\n", argv[1]);
	system("pause");
	//menu();
	//Load_aux(path_Recebido, LDados);
}
