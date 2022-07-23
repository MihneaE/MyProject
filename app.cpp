#define _CRTDBG_MAP_ALLOC
#include <iostream>
#include "repo.h"
#include "service.h"
#include "UI.h"
#include "Magazin.h"
#include "Validator.h"
using namespace std;

int main()
{
	Test_Magazin();
	Test_Service();
	TestValidator();

	{
		Repository repo;
		Cos cos;
		Service serv(repo, cos);
		Consola consola(serv);
		consola.Run();
	}

    //_CrtDumpMemoryLeaks();
	
	return 0;
}
