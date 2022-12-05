#include "Account.h"

// Two getter methods to access private data: accountNumber and accountType
// @return respective data

AccountNumber* Account::getAccountNumber() {
	return accountNumber;
}

string Account::getAccountType() {
	return accountType;
}

//The following method rounds a value to the specified number of places.
//NOTE: It works for most values...but is not guaranteed to work for all values!
//@param value:		The value to round
//@param places:	The number of places to round
//@returns			The rounded number
double Account::round(double value, int places) {
	const int multiplier = pow(10, places);

	double roundedValue = (int)(value * multiplier + 0.5);
	roundedValue = (double)roundedValue / multiplier;
	return roundedValue;
}

//Formats a double value for output purposes.
//This method will not append with any 0s...so the value should be rounded prior to use.
//@param value:	The value to format
//@returns:		The formatted value.
string Account::format(double value) {
	string valueAsString = to_string(value);
	string formatted;

	bool decimalFound = false;
	int decimalCount = 0;

	int i;
	for (i = 0; i < valueAsString.size(); i++) {
		char currentChar = valueAsString[i];

		if (decimalCount == 2) {
			break;
		}

		if (currentChar == '.') {
			decimalFound = true;
		} else if (decimalFound && decimalCount != 2) {
			decimalCount++;
		}

		formatted.append(string(1, currentChar));
	}

	return formatted;
}

Account::Account(AccountNumber* accountNumber, string accountType)
{
	this->accountNumber = accountNumber;
	this->accountType = accountType;
}
