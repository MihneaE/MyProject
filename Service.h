#ifndef SERVICE_H_
#define SERVICE_H_
#include <stdexcept>
#include <algorithm>
#include <vector>
#include <list>
#include "repo.h"
#include "Undo.h"
#include "CosCumparaturi.h"
#include <map>
using namespace std;

class Service {
private:
	Repository& repo;
	Cos& cos;
	list<unique_ptr<ActiuneUndo>> undoActions;

public:
	Service(Repository& repo, Cos& cos) : repo {repo}, cos {cos} {}

	void adauga_produs(string nume, string tip, int pret, string producator);
	void modifica_produs(string nume, string tip, int pret, string producator);
	void sterge_produs(string nume);
	const vector<Produs>& getAll() const;
	const vector<Produs> filtreaza_pret(int pret) const;
	const vector<Produs> filtreaza_nume(string nume) const;
	const vector<Produs> filtreaza_producator(string producator) const;
	const vector<Produs> cauta_nume(string nume) const;
	const vector<Produs> cauta_tip(string tip) const;
	vector<Produs> sorteaza_pret_crescator();
	vector<Produs> sorteaza_pret_descrescator();
	vector<Produs> sorteaza_nume_crescator();
	vector<Produs> sorteaza_nume_descrescator();
	vector<Produs> sorteaza_nume_tip_crescator();
	vector<Produs> sorteaza_nume_tip_descrescator();
	int size();
	void adauga_cos(string nume);
	void sterge_cos();
	void genereaza_cos(int number);
	const vector<Produs>& getAll_cos() const;
	map<string, int> raport();
	void undo();

	~Service()
	{}
};

void Test_Service();

#endif