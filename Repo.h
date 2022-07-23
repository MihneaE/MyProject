#ifndef REPO_H_
#define REPO_H_
#include <exception>
#include <vector>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include "magazin.h"
using namespace std;

class Repository {
public:
	Repository() 
	{
		load_from_file();
	}

	~Repository() = default;

	void Adauga(const Produs&);
	Produs Modifica(Produs&);
	void Sterge(string nume);
	const vector<Produs>& getAll() const;
	void load_from_file();
	void save_to_file();
	int Size();

private:
	vector<Produs> vector_produse;
};

#endif