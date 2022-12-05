#include "AccountNumber.h"

int AccountNumber::nextAccountNumber = 1;

/*
Create account numbers in an incremental rate of 1
@return	Respective account number as in int
*/
AccountNumber::AccountNumber()
{
	this->accountNumber = nextAccountNumber;
	nextAccountNumber++;
}

// Getter method to access private data 
int AccountNumber::getAccountNumber()
{
	return accountNumber;
}
