#include "UI.h"
#include "Magazin.h"
#include "validator.h"
using namespace std;

void Consola::load_produs()
{
	serv.adauga_produs("Ton", "Peste", 10, "Pfizer");
	serv.adauga_produs("Somon", "Peste", 60, "Pfizer");
	serv.adauga_produs("Sissi", "Sunca", 20, "Kuku");
	serv.adauga_produs("Gastro", "Sunca", 30, "Kuku");
	serv.adauga_produs("Parizer", "Sunca", 20, "Pfizer");
}

void Consola::afiseaza_produs(vector<Produs> v) const
{
	for (size_t i = 0; i <(size_t) v.size(); ++i)
	{
		Produs p = v[i];
		cout << " Nume: " << p.getNume() << " Tip: " << p.getTip() << " Pret: " << p.getPret() << " Producator: " << p.getProducator() << endl;
	}
}

void Consola::adauga_ui()
{
	string nume, tip, producator;
	int pret;
	cout << "Nume: ";
	cin >> nume;
	cout << "Tip: ";
	cin >> tip;
	cout << "Pret: ";
	cin >> pret;
	cout << "Producator: ";
	cin >> producator;
	
	try
	{
		if (pret < 0)
			throw ValidationError("Pretul nu poate fi mai mic ca 0!");

		serv.adauga_produs(nume, tip, pret, producator);
		cout << "Adaugarea s-a efectuat" << endl;
	}
	catch(ValidationError& e)
	{
		cout << e.getMessage() << endl;
	}
}

void Consola::modifica_ui()
{
	string nume, tip, producator;
	int pret;
	cout << "Nume: ";
	cin >> nume;
	cout << "Tip: ";
	cin >> tip;
	cout << "Pret: ";
	cin >> pret;
	cout << "Producator: ";
	cin >> producator;

	try
	{
		if (pret < 0)
			throw ValidationError("Pretul nu poate fi mai mic ca 0!");

		serv.modifica_produs(nume, tip, pret, producator);
		cout << "Modificarea s-a efectuat" << endl;
	}
	catch (ValidationError& e)
	{
		cout << e.getMessage() << endl;
	}
}

void Consola::sterge_ui() 
{
	string nume;
	cout << "Nume: ";
	cin >> nume;
	serv.sterge_produs(nume);
	cout << "Stergerea s-a efectuat" << endl;
}

void Consola::filtreaza_pret_ui() const
{
	int pret;
	cout << "Pret: ";
	cin >> pret;
	vector<Produs> rez = serv.filtreaza_pret(pret);
	afiseaza_produs(rez);
}

void Consola::filtreaza_nume_ui() const
{
	string nume;
	cout << "Nume: ";
	cin >> nume;
	vector<Produs> rez = serv.filtreaza_nume(nume);
	afiseaza_produs(rez);
}

void Consola::filtreaza_producator_ui() const
{
	string producator;
	cout << "Producator: ";
	cin >> producator;
	vector<Produs> rez = serv.filtreaza_producator(producator);
	afiseaza_produs(rez);
}

void Consola::cauta_nume_ui() const
{
	string nume;
	cout << "Nume: ";
	cin >> nume;
	vector<Produs> rez = serv.cauta_nume(nume);
	afiseaza_produs(rez);
}

void Consola::cauta_tip_ui() const
{
	string tip;
	cout << "Tip: ";
	cin >> tip;
	vector<Produs> rez = serv.cauta_tip(tip);
	afiseaza_produs(rez);
}

void Consola::sorteaza_pret_crescator_ui()
{
	vector<Produs> rez = serv.sorteaza_pret_crescator();
	afiseaza_produs(rez);
}

void Consola::sorteaza_pret_descrescator_ui()
{
	vector<Produs> rez = serv.sorteaza_pret_descrescator();
	afiseaza_produs(rez);
}

void Consola::sorteaza_nume_crescator_ui()
{
	vector<Produs> rez = serv.sorteaza_nume_crescator();
	afiseaza_produs(rez);
}

void Consola::sorteaza_nume_descrescator_ui()
{
	vector<Produs> rez = serv.sorteaza_nume_descrescator();
	afiseaza_produs(rez);
}

void Consola::sorteaza_nume_tip_crescator_ui()
{
	vector<Produs> rez = serv.sorteaza_nume_tip_crescator();
	afiseaza_produs(rez);
}

void Consola::sorteaza_nume_tip_descrescator_ui()
{
	vector<Produs> rez = serv.sorteaza_nume_tip_descrescator();
	afiseaza_produs(rez);
}

void Consola::afiseaza_cos()
{
	vector<Produs> rez = serv.getAll_cos();
	
	if (!rez.empty())
		afiseaza_produs(rez);
	else
		cout << "Cosul este gol";
}

void Consola::adauga_cos_ui()
{
	vector<Produs> rez = serv.getAll_cos();
	string nume;
	cout << "Nume: ";
	cin >> nume;
	serv.adauga_cos(nume);
	cout << "Adaugarea s-a efectuat" << '\n';
}

void Consola::sterge_cos_ui()
{
	serv.sterge_cos();
	cout << "Stergerea s-a efectuat" << '\n';
}

void Consola::genereaza_cos_ui()
{
	int number;
	cout << "Numarul: ";
	cin >> number;
	serv.genereaza_cos(number);
	cout << "Generarea s-a efectuat" << '\n';
}

void Consola::raport_ui()
{
	map<string, int> rez = serv.raport();
	for (const auto& prod : rez)
		cout << "Tipul: " << prod.first << "\nNumar de produse: " << prod.second << '\n';
}

void text()
{
	cout << "1. Afisare" << endl;
	cout << "2. Adauga" << endl;
	cout << "3. Modifica" << endl;
	cout << "4. Sterge" << endl;
	cout << "5. Filtreaza" << endl;
	cout << "6. Cauta" << endl;
	cout << "7. Sorteaza" << endl;
	cout << "8. Afisare cos" << endl;
	cout << "9. Adauga cos" << endl;
	cout << "10. Sterge cos" << endl;
	cout << "11. Genereaza cos" << endl;
	cout << "12. Raport" << endl;
	cout << "13. Undo" << endl;
	cout << "0. Iesire" << endl;
}

void Consola::Run()
{
	load_produs();

	while (true)
	{
		vector<Produs> v = serv.getAll();
		text();
		int cmd;
		cout << "Introduceti comanda: ";
		cin >> cmd;

		if (cmd == 1)
		{
			afiseaza_produs(v);
		}

		if (cmd == 2)
		{
			adauga_ui();
		}

		if (cmd == 3)
		{
			modifica_ui();
		}

		if (cmd == 4)
		{
			sterge_ui();
		}

		if (cmd == 5)
		{
			cout << "1. Dupa pret" << endl;
			cout << "2. Dupa nume" << endl;
			cout << "3. Dupa producator" << endl;

			int cmd_filtrare;
			cout << "Alegeti filtrarea: ";
			cin >> cmd_filtrare;

			if (cmd_filtrare == 1)
			{
				filtreaza_pret_ui();
			}

			if (cmd_filtrare == 2)
			{
				filtreaza_nume_ui();
			}

			if (cmd_filtrare == 3)
			{
				filtreaza_producator_ui();
			}
		}

		if (cmd == 6)
		{
			cout << "1. Dupa nume" << endl;
			cout << "2. Dupa tip" << endl;

			int cmd_cautare;
			cout << "Alegeti cautarea: ";
			cin >> cmd_cautare;

			if (cmd_cautare == 1)
			{
				cauta_nume_ui();
			}

			if (cmd_cautare == 2)
			{
				cauta_tip_ui();
			}
		}

		if (cmd == 7)
		{
			cout << "1. Dupa pret" << endl;
			cout << "2. Dupa nume" << endl;
			cout << "3. Dupa tip + nume" << endl;

			int cmd_sortare;
			cout << "Alegeti sortarea: ";
			cin >> cmd_sortare;

			if (cmd_sortare == 1)
			{
				cout << "1. Crescator" << endl;
				cout << "2. Descrescator" << endl;

				int cmd_sortare_1;
				cout << "Alegeti tipul de sortare: ";
				cin >> cmd_sortare_1;

				if (cmd_sortare_1 == 1)
				{
					sorteaza_pret_crescator_ui();
				}
				
				if (cmd_sortare_1 == 2)
				{
					sorteaza_pret_descrescator_ui();
				}
			}

			if (cmd_sortare == 2)
			{
				cout << "1. Crescator" << endl;
				cout << "2. Descrescator" << endl;

				int cmd_sortare_2;
				cout << "Alegeti tipul de sortare: ";
				cin >> cmd_sortare_2;

				if (cmd_sortare_2 == 1)
				{
					sorteaza_nume_crescator_ui();
				}

				if (cmd_sortare_2 == 2)
				{
					sorteaza_nume_descrescator_ui();
				}
			}

			if (cmd_sortare == 3)
			{
				cout << "1. Crescator" << endl;
				cout << "2. Descrescator" << endl;

				int cmd_sortare_3;
				cout << "Alegeti tipul de sortare: ";
				cin >> cmd_sortare_3;

				if (cmd_sortare_3 == 1)
				{
					sorteaza_nume_tip_crescator_ui();
				}

				if (cmd_sortare_3 == 2)
				{
					sorteaza_nume_tip_descrescator_ui();
				}
			}
		}

		if (cmd == 8)
		{
			afiseaza_cos();
		}

		if (cmd == 9)
		{
			adauga_cos_ui();
		}

		if (cmd == 10)
		{
			sterge_cos_ui();
		}

		if (cmd == 11)
		{
			genereaza_cos_ui();
		}

		if (cmd == 12)
		{
			raport_ui();
		}

		if (cmd == 13)
		{
			serv.undo();
		}

		if (cmd == 0)
		{
			break;
		}
	}
}

