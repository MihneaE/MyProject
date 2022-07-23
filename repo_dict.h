#pragma once
#include "Repo_abstract.h"
#include "Repo.h"
#include <map>
using std::map;

class Repo_dict : public Repo_Abs {
private:
	map<string, Produs> all;
	double probabilitate;

public:
	Repo_dict(double prob) : probabilitate{ prob } 
	{}
	~Repo_dict() = default;
	void Adauga(const Produs&) override;
	Produs Modifica(Produs&) override;
	void Sterge(string nume) override;
	const vector<Produs> getAll() const override;
	int Size() const override;
};

