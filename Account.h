#pragma once

#include <string>
#include "AccountNumber.h"
#include <cmath>

using namespace std;

class Account
{
public:
	// Abstract class - contains virtual methods that need to be implimented by the child class
	Account(AccountNumber* accountNumber, string accountType);
	
	// Calculation methods
	virtual double getEndingBalance(int numberOfYears) = 0;				// Balance after so many number of years
	virtual double getInterestEarned(int numberOfYears) = 0;			// Interest earned after so many number of years
	
	// Format to string methods for display
	virtual string getEndingBalanceFormatted(int numberOfYears) = 0;	// Formated string of getEndingBalance
	virtual string getInterestEarnedFormatted(int numberOfYears) = 0;	// Formated string of getInterestEarned
	virtual string getAccountDetails() = 0;								// String with account information

	AccountNumber* getAccountNumber();									// Returns a pointer 
	string getAccountType();											// Returns account type

protected:
	double round(double value, int places);								// Rounds a double to two decimal spaces
	string format(double value);										// Formats for display purposes

private:
	AccountNumber* accountNumber;										
	string accountType;

	
};

