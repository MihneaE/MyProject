#include <iostream>
#include <vector>
#include <exception>
#include <algorithm>
#include <string>
#include <stdexcept>
#include <fstream>
#include "Repo.h"
using namespace std;

const vector<Produs>& Repository::getAll() const
{
	return vector_produse;
}

void Repository::Adauga(const Produs& p) 
{
	for (const Produs& prod : vector_produse)
		if (prod == p) return;

	vector_produse.push_back(p);
	save_to_file();
}

Produs Repository::Modifica(Produs& p)
{
	Produs prd;
	for (Produs& prod : vector_produse)
	{
		if (prod.getNume() == p.getNume())
		{
			prd = prod;
			prod.setTip(p.getTip());
			prod.setPret(p.getPret());
			prod.setProducator(p.getProducator());
			save_to_file();
		}
	}

	return prd;
}

void Repository::Sterge(string nume)
{
	size_t poz = 0;
	size_t i = 0;

	for (const Produs& prod : vector_produse)
	{
		if (prod.getNume() == nume)
		{
			poz = i;
			break;
		} 
		
		i++;	
	}

	vector_produse.erase(vector_produse.begin() + poz);
	save_to_file();
}

int Repository::Size()
{
	return (int)vector_produse.size();
}

void Repository::load_from_file()
{
	ifstream fin("magazin.txt");
	string nume, tip, producator;
	int pret;

	while (fin >> nume >> tip >> pret >> producator)
	{
		Produs p(nume, tip, pret, producator);
		Adauga(p);
	}

	fin.close();
}

void Repository::save_to_file()
{
	ofstream fout("magazin.txt");
	
	for (size_t i = 0; i < (size_t)vector_produse.size(); ++i)
		fout << vector_produse[i].getNume() << ";" << vector_produse[i].getTip() << ";" << vector_produse[i].getPret() << ";"
		<< vector_produse[i].getProducator() << "\n";

	fout.close();
}