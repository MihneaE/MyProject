#pragma once
#include "Magazin.h"
#include <vector>

class Repo_Abs {
public:
	virtual ~Repo_Abs() = default;
	virtual void Adauga(const Produs&) = 0;
	virtual Produs Modifica(Produs&) = 0;
	virtual void Sterge(string nume) = 0;
	virtual const vector<Produs> getAll() const = 0;
	virtual int Size() const = 0;
};