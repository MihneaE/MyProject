#ifndef VALIDATOR_H_
#define VALIDATOR_H_
#include "Magazin.h"
#include <string>
using namespace std;

class POSError{
public:
	POSError(string message) : message(message) {
	}
	const string & getMessage() const {
	return message;
	}
private:
	string message;
};

class ValidationError : public POSError{
public:
	ValidationError(string message) : POSError(message) 
	{}
};

class ValidatorProdus {
public:
	void validate(Produs prod);
};

void TestValidator();

#endif