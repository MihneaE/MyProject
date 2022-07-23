#include "Magazin.h"

const string& Produs::getNume() const
{
	return this->nume;
}

void Produs::setNume(string _nume)
{
	this->nume = _nume;
}

const string& Produs::getTip() const
{
	return this->tip;
}

void Produs::setTip(string _tip)
{
	this->tip = _tip;
}

const int Produs::getPret() const
{
	return this->pret;
}

void Produs::setPret(int _pret)
{
	this->pret = _pret;
}

const string& Produs::getProducator() const
{
	return this->producator;
}

void Produs::setProducator(string Producator)
{
	this->producator = Producator;
}

void Test_Magazin()
{
	Produs p("A", "B", 10, "C");
	assert(p.getNume() == "A");
	assert(p.getTip() == "B");
	assert(p.getPret() == 10);
	assert(p.getProducator() == "C");
	p.setNume("Marian");
	p.setTip("D");
	p.setPret(30);
	p.setProducator("E");
	assert(p.getNume() == "Marian");
	assert(p.getTip() == "D");
	assert(p.getPret() == 30);
	assert(p.getProducator() == "E");
}
