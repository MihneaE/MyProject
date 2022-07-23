#ifndef COSCUMPARATURI_H_
#define COSCUMPARATURI_H_
#include <iostream>
#include <string>
#include <assert.h>
#include <vector>
#include "Magazin.h"
using namespace std;

class Cos {
private:
	vector<Produs> cos_cumparaturi;
public:
	Cos() = default;
	~Cos() = default;
	void Adauga(const Produs& p);
	void StergeAll();         
	void save_to_file_cos();
	const vector<Produs>& getAllCos() const;
};

#endif