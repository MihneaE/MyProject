#include "validator.h"
#include <assert.h>

void ValidatorProdus::validate(Produs prod) 
{
	string mesaj = "";

	if (prod.getNume() == "")
		mesaj += "Numele nu poate fi gol!";
	if (prod.getTip() == "")
		mesaj += "Tip nu poate fi gol!";
	if (prod.getPret() < 0)
		mesaj += "Pretul nu poate fi negativ!";
	if (prod.getProducator() == "")
		mesaj += "Producatorul nu poate fi gol!";

	if (mesaj != "")
		throw ValidationError(mesaj);
}

void TestValidator()
{
	Produs p1("A", "B", 10, "C");
	ValidatorProdus vp;
	vp.validate(p1);
	Produs p2("", "B", 10, "C");
	try
	{
		vp.validate(p2);
		assert(false);
	}
	catch (ValidationError& ex)
	{
		assert(ex.getMessage() == "Numele nu poate fi gol!");
	}
	Produs p3("A", "", 10, "C");
	try
	{
		vp.validate(p3);
		assert(false);
	}
	catch (ValidationError& ex)
	{
		assert(ex.getMessage() == "Tip nu poate fi gol!");
	}
	Produs p4("A", "B", -1, "C");
	try
	{
		vp.validate(p4);
		assert(false);
	}
	catch (ValidationError& ex)
	{
		assert(ex.getMessage() == "Pretul nu poate fi negativ!");
	}
	Produs p5("A", "B", 10, "");
	try
	{
		vp.validate(p5);
		assert(false);
	}
	catch (ValidationError& ex)
	{
		assert(ex.getMessage() == "Producatorul nu poate fi gol!");
	}
}

