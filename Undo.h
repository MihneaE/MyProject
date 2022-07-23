#pragma once
#include <iostream>
#include "Magazin.h"
#include "Repo.h"
using namespace std;

class ActiuneUndo {
public:
	virtual void doUndo() = 0;
	virtual ~ActiuneUndo() {};
};

class UndoAdauga : public ActiuneUndo {
	Produs produsAdaugat;
	Repository& repo;
public:
	UndoAdauga(Repository& repo, const Produs& prod) : repo {repo}, produsAdaugat {prod}
	{}

	void doUndo() override
	{
		repo.Sterge(produsAdaugat.getNume());
	}
};

class UndoSterge : public ActiuneUndo {
	Produs produsSters;
	Repository& repo;
public:
	UndoSterge(Repository& repo, const Produs& prod) : repo{ repo }, produsSters{ prod }
	{}

	void doUndo() override
	{
		repo.Adauga(produsSters);
	}
};

class UndoModifica : public ActiuneUndo {
	Produs produsModificat;
	Repository& repo;
public:
	UndoModifica(Repository& repo, const Produs& prod) : repo{ repo }, produsModificat{ prod }
	{}

	void doUndo() override
	{
		repo.Modifica(produsModificat);
	}
};



