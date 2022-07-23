#include <vector>
#include <algorithm>
#include <stdexcept>
#include "service.h"
#include <assert.h>
#include "validator.h"
#include "repo.h"
#include <random>
#include <chrono>
using namespace std;

void Service::adauga_produs(string nume, string tip, int pret, string producator)
{
	Produs p(nume, tip, pret, producator);
	repo.Adauga(p);
	undoActions.push_back(make_unique<UndoAdauga>(repo, p));
}

void Service::modifica_produs(string nume, string tip, int pret, string producator)
{
	auto prod = cauta_nume(nume);
	Produs p(nume, tip, pret, producator);
	repo.Modifica(p);
	undoActions.push_back(make_unique<UndoModifica>(repo, prod.at(0)));
}

void Service::sterge_produs(string nume)
{
	auto prod = cauta_nume(nume);
	repo.Sterge(nume);
	undoActions.push_back(make_unique<UndoSterge>(repo, prod.at(0)));
}

const vector<Produs>& Service::getAll() const
{
	return repo.getAll();
}

const vector<Produs> Service::filtreaza_pret(int pret) const
{
	vector<Produs> all = repo.getAll();
	vector<Produs> rez(all.size());

	auto it = copy_if(all.begin(), all.end(), rez.begin(), [pret](const Produs& prod) {return prod.getPret() == pret;});
	rez.resize(distance(rez.begin(), it));

	return rez;
}

const vector<Produs> Service::filtreaza_nume(string nume) const
{
	vector<Produs> all = repo.getAll();
	vector<Produs> rez(all.size());

	auto it = copy_if(all.begin(), all.end(), rez.begin(), [nume](const Produs& prod) {return prod.getNume() == nume; });
	rez.resize(distance(rez.begin(), it));

	return rez;
}

const vector<Produs> Service::filtreaza_producator(string producator) const
{
	vector<Produs> all = repo.getAll();
	vector<Produs> rez(all.size());

	auto it = copy_if(all.begin(), all.end(), rez.begin(), [producator](const Produs& prod) {return prod.getProducator() == producator; });
	rez.resize(distance(rez.begin(), it));

	return rez;
}

const vector<Produs> Service::cauta_nume(string nume) const
{
	vector<Produs> all = repo.getAll();
	vector<Produs>::iterator it = find_if(all.begin(), all.end(), [nume](const Produs& prod) {return prod.getNume() == nume; });
	vector<Produs> rez;

	if (it != all.end())
		rez.push_back(*it);
		
	return rez;
}

const vector<Produs> Service::cauta_tip(string tip) const
{
	vector<Produs> all = repo.getAll();
	vector<Produs>::iterator it = find_if(all.begin(), all.end(), [tip](const Produs& prod) {return prod.getTip() == tip; });
	vector<Produs> rez;

	if (it != all.end())
		rez.push_back(*it);

	return rez;
}

vector<Produs> Service::sorteaza_pret_crescator()
{
	vector<Produs> rez;
	vector<Produs> all = repo.getAll();

	for (const Produs& prod : all)
		rez.push_back(prod);

	for (size_t i = 0; i < (size_t)rez.size(); ++i)
		for (size_t j = i + 1; j < (size_t)rez.size(); ++j)
		{
			if (rez[i].getPret() > rez[j].getPret())
			{
				Produs aux = rez[i];
				rez[i] = rez[j];
				rez[j] = aux;
			}
		}

	return rez;
}

vector<Produs> Service::sorteaza_pret_descrescator()
{
	vector<Produs> rez;
	vector<Produs> all = repo.getAll();

	for (const Produs& prod : all)
		rez.push_back(prod);

	for (size_t i = 0; i < (size_t)rez.size(); ++i)
		for (size_t j = i + 1; j < (size_t)rez.size(); ++j)
		{
			if (rez[i].getPret() < rez[j].getPret())
			{
				Produs aux = rez[i];
				rez[i] = rez[j];
				rez[j] = aux;
			}
		}

	return rez;
}

vector<Produs> Service::sorteaza_nume_crescator()
{
	vector<Produs> rez;
	vector<Produs> all = repo.getAll();

	for (const Produs& prod : all)
		rez.push_back(prod);

	for (size_t i = 0; i < (size_t)rez.size(); ++i)
		for (size_t j = i + 1; j < (size_t)rez.size(); ++j)
		{
			if (rez[i].getNume() > rez[j].getNume())
			{
				Produs aux = rez[i];
				rez[i] = rez[j];
				rez[j] = aux;
			}
		}

	return rez;
}

vector<Produs> Service::sorteaza_nume_descrescator()
{
	vector<Produs> rez;
	vector<Produs> all = repo.getAll();

	for (const Produs& prod : all)
		rez.push_back(prod);

	for (size_t i = 0; i < (size_t)rez.size(); ++i)
		for (size_t j = i + 1; j < (size_t)rez.size(); ++j)
		{
			if (rez[i].getNume() < rez[j].getNume())
			{
				Produs aux = rez[i];
				rez[i] = rez[j];
				rez[j] = aux;
			}
		}

	return rez;
}

vector<Produs> Service::sorteaza_nume_tip_crescator()
{
	vector<Produs> rez;
	vector<Produs> all = repo.getAll();

	for (const Produs& prod : all)
		rez.push_back(prod);

	for (size_t i = 0; i < (size_t)rez.size(); ++i)
		for (size_t j = i + 1; j < (size_t)rez.size(); ++j)
		{
			if (rez[i].getTip() > rez[j].getTip())
			{
				Produs aux = rez[i];
				rez[i] = rez[j];
				rez[j] = aux;
			}
			else if (rez[i].getTip() == rez[j].getTip())
				if (rez[i].getNume() > rez[j].getNume())
				{
					Produs aux = rez[i];
					rez[i] = rez[j];
					rez[j] = aux;
				}
		}
	
	return rez;
}

vector<Produs> Service::sorteaza_nume_tip_descrescator()
{
	vector<Produs> rez;
	vector<Produs> all = repo.getAll();

	for (const Produs& prod : all)
		rez.push_back(prod);

	for (size_t i = 0; i < (size_t)rez.size(); ++i)
		for (size_t j = i + 1; j < (size_t)rez.size(); ++j)
		{
			if (rez[i].getTip() < rez[j].getTip())
			{
				Produs aux = rez[j];
				rez[i] = rez[j];
				rez[j] = aux;
			}
			else if (rez[i].getTip() == rez[j].getTip())
				if (rez[i].getNume() < rez[j].getNume())
				{
					Produs aux = rez[i];
					rez[i] = rez[j];
					rez[j] = aux;
				}
		}

	return rez;
}

int Service::size()
{
	return repo.Size();
}

void Service::adauga_cos(string nume)
{
	vector<Produs> all = repo.getAll();

	for (size_t i = 0; i < (size_t)all.size(); ++i)
		if (all[i].getNume() == nume)
			cos.Adauga(all[i]);
}

void Service::sterge_cos()
{
	cos.StergeAll();
}

void Service::genereaza_cos(int number)
{
	vector<Produs> all = repo.getAll();
	auto seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::shuffle(all.begin(), all.end(), std::default_random_engine((unsigned int)seed));

	vector<Produs>::iterator it = all.begin();

	for (size_t i = 0; i < (size_t)number; ++i)
	{
		cos.Adauga(*it);
		it++;
		cos.save_to_file_cos();
	}
}

const vector<Produs>& Service::getAll_cos() const
{
	return cos.getAllCos();
}

map<string, int> Service::raport()
{
	vector<Produs> all = repo.getAll();
	map<string, int> rez;

	for (const auto& prod : all)
		rez[prod.getTip()] = 0;
	for (const auto& prod : all)
		rez[prod.getTip()]++;

	return rez;
}

void Service::undo()
{
	if (undoActions.empty())
		throw ValidationError("Nu au fost efectuate modificari asupra listei!\n");

	undoActions.back()->doUndo();
	undoActions.pop_back();
}

void Test_Service()
{
	Repository repo;
	Cos cos;
	Service serv(repo, cos);
	serv.adauga_produs("A", "B", 10, "C");
	assert(serv.size() == 1);
	serv.sterge_produs("A");
	assert(serv.size() == 0);
	serv.adauga_produs("A", "B", 10, "C");
	serv.adauga_produs("F", "C", 30, "C");
	serv.adauga_produs("D", "B", 20, "C");
	serv.adauga_produs("A", "C", 20, "C");
	serv.adauga_produs("Y", "C", 20, "C");
	serv.adauga_produs("X", "C", 20, "C");
	serv.adauga_produs("F", "C", 20, "C");
	serv.adauga_produs("A", "X", 20, "C");
	serv.adauga_produs("A", "Y", 20, "C");
	serv.adauga_produs("A", "H", 20, "C");
	serv.adauga_produs("X", "H", 20, "C");
	serv.adauga_produs("B", "H", 20, "C");
	serv.adauga_produs("H", "H", 20, "C");
	serv.adauga_produs("M", "J", 20, "C");
	serv.adauga_produs("N", "J", 20, "C");
	serv.adauga_produs("Z", "X", 20, "C");
	serv.modifica_produs("A", "D", 5, "E");

	serv.filtreaza_nume("A");
	serv.filtreaza_pret(20);
	serv.filtreaza_producator("E");
	serv.cauta_nume("A");
	serv.cauta_tip("D");
	serv.adauga_produs("B", "F", 10, "H");
	vector<Produs> v = serv.getAll();
	serv.sorteaza_pret_crescator();
	v = serv.getAll();
	serv.sorteaza_pret_descrescator();
	serv.sorteaza_nume_crescator();
	serv.sorteaza_nume_descrescator();
	serv.sorteaza_nume_tip_crescator();
	serv.sorteaza_nume_tip_descrescator();
	serv.adauga_cos("A");
	serv.sterge_cos();
	serv.genereaza_cos(3);
	serv.getAll_cos();
	serv.raport();

	vector<Produs> el;
	el = el;
	Produs p1("A", "B", 10, "D");
	Produs p2("B", "B", 10, "D");
	Produs p3("C", "B", 10, "D");
	el.push_back(p1);
	el.push_back(p2);
	el.push_back(p3);
	el.erase(el.begin() + 0);

	vector<Produs> el1;
	el1 = el;
}
