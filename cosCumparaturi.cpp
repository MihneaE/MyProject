#include <iostream>
#include <vector>
#include <exception>
#include <algorithm>
#include <string>
#include <fstream>
#include "CosCumparaturi.h"
using namespace std;

void Cos::Adauga(const Produs& p)
{
	cos_cumparaturi.push_back(p);
	save_to_file_cos();
}

void Cos::StergeAll()
{
	cos_cumparaturi.clear();
	save_to_file_cos();
}

const vector<Produs>& Cos::getAllCos() const
{
	return cos_cumparaturi;
}

void Cos::save_to_file_cos()
{
	ofstream fout("cos_cumparaturi.txt");
	
	for (size_t i = 0; i < (size_t)cos_cumparaturi.size(); ++i)
		fout << cos_cumparaturi[i].getNume() << ";" << cos_cumparaturi[i].getTip() << ";" << cos_cumparaturi[i].getPret() << ";"
		<< cos_cumparaturi[i].getProducator() << "\n";

	fout.close();
}
