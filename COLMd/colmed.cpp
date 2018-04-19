#include "colmed.h"

colmed::colmed(string path)
{
	this->m_path = path;
}


colmed::~colmed()
{

}

bool Load_aux()
{
	string *CDirectoria = nullptr;
	for (auto & p : directory_iterator(path_Recebido))
		{
		path cam = p.path();
		string nome = cam.filename().string();
		string caminho = cam.string();
		file_type CHECK = p.status().type();
		auto ftime = last_write_time(p);
		time_t cftime = decltype(ftime)::clock::to_time_t(ftime);
		string data = asctime(localtime(&cftime));
		if (CHECK == file_type::regular;)
		{
			CDirectoria = new Directoria(nome, caminho, data, 0, 0);
			list<Entidades *> *Ltemp = (CDirectoria)->GetList();
			Load_aux(caminho, *Ltemp);
			CDirectoria->Set_Num_Ficheiros(Ltemp->size());
			Lista.push_back(CDirectoria);
			CDirectoria = nullptr;
		}
		if (CHECK == FICH)
		{
			CFicheiro = new Ficheiro(nome, caminho, data, file_size(p));
			Lista.push_back(CFicheiro);
			CFicheiro = nullptr;
		}
	}
}

bool colmed::Scan()
{
	if (m_path.empty()) return false;
	if(Load_aux(path_Recebido, LDados));
	return true;
}



