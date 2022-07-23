#ifndef EXCEPTION_H_
#define EXCEPTION_H_
#include <string>
using namespace std;

class ValidatorException
{
public:
	ValidatorException(string msj) 
	{
		mesaj = msj;
	}

	string getMesaj()
	{
		return mesaj;
	}

private:
	string mesaj;
};

#endif