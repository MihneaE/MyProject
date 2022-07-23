#include "repo_dict.h"
#include "validator.h"
#include <random>

void Repo_dict::Adauga(const Produs& p)
{
	std::uniform_real_distribution<double> d(0.0, 1.0);
	std::default_random_engine r_e{ std::random_device{}() };
	if (d(r_e) > probabilitate)
		throw ValidationError("Eroare dictionar!");

	if (all.find(p.getNume()) != all.end())
		throw ValidationError("Eroare!");

	all[p.getNume()] = p;
}

Produs Repo_dict::Modifica(Produs& p)
{
	std::uniform_real_distribution<double> d(0.0, 1.0);
	std::default_random_engine r_e{ std::random_device{}() };
	if (d(r_e) > probabilitate)
		throw ValidationError("Eroare dictionar!");

	if (all.find(p.getNume()) == all.end())
		throw ValidationError("Eroare!");

	all[p.getNume()] = p;
}

void Repo_dict::Sterge(string nume)
{
	std::uniform_real_distribution<double> d(0.0, 1.0);
	std::default_random_engine r_e{ std::random_device{}() };
	if (d(r_e) > probabilitate)
		throw ValidationError("Eroare dictionar!");

	if (all.find(nume) == all.end())
		throw ValidationError("Eroare!");

	all.erase(nume);
}

const vector<Produs> Repo_dict::getAll() const
{
	vector<Produs> rez;
	
	for (auto& prod : all)
		rez.push_back(prod.second);

	return rez;
}

int Repo_dict::Size() const
{
	return all.size();
}
