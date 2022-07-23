#ifndef MAGAZIN_H_
#define MAGAZIN_H_
#include <iostream>
#include <string>
#include <assert.h>
using namespace std;

class Produs {
private:
	string nume;
	string tip;
	int pret;
	string producator;

public:
	Produs()
	{}

	Produs(string _nume, string _tip, int _pret, string _producator) : nume(_nume), tip(_tip), pret(_pret), producator(_producator)
	{}

	friend bool operator== (Produs p1, Produs p2)
	{
		return p1.nume == p2.nume;
	}

	Produs(const Produs& p) : nume(p.getNume()), tip(p.getTip()), pret(p.getPret()), producator(p.getProducator())
	{}

	const string& getNume() const;
	void setNume(string nume);
	const string& getTip() const;
	void setTip(string tip);
	const int getPret() const;
	void setPret(int pret);
	const string& getProducator() const;
	void setProducator(string producator);

	~Produs() {}
};

void Test_Magazin();

#endif