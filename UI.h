#ifndef UI_H_
#define UI_H_
#include "Service.h"
using namespace std;

class Consola {
private:
	Service& serv;

public:
	Consola(Service& serv) : serv {serv}
	{}

	void load_produs();
	void afiseaza_produs(vector<Produs> v) const;
	void adauga_ui();
	void modifica_ui();
	void sterge_ui();
	void filtreaza_pret_ui() const;
	void filtreaza_nume_ui() const;
	void filtreaza_producator_ui() const;
	void cauta_nume_ui() const;
	void cauta_tip_ui() const;
	void sorteaza_pret_crescator_ui();
	void sorteaza_pret_descrescator_ui();
	void sorteaza_nume_crescator_ui();
	void sorteaza_nume_descrescator_ui();
	void sorteaza_nume_tip_crescator_ui();
	void sorteaza_nume_tip_descrescator_ui();
	void afiseaza_cos();
	void adauga_cos_ui();
	void sterge_cos_ui();
	void genereaza_cos_ui();
	void raport_ui();
	void Run();

	~Consola() {}
};

#endif