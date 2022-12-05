#include "InvestmentAccount.h"
#include <vector>

/*
Create Investment Account objects with respective data - NO MONTHLY CONTRIBUTION DESPOSIT
@param accountNumber:		Account number, accessed from AccountNumber as a pointer
@param initialAmount:		Begining balance of the account as a double
@param annualInterestRate:	Annual interest rate as a double
@return						Investment Account object, inherited from Account class
*/
InvestmentAccount::InvestmentAccount(AccountNumber* accountNumber, double initialAmount, double annualInterestRate)
:Account(accountNumber, "Investment Compund Interest Account - Excludes Monthly Contribution")
{
	this->initialAmount			= initialAmount;
	this->annualInterestRate	= annualInterestRate;
	this->monthlyDeposit		= 0;					// Set to 0 for to exclude contribution
}

/*
Create Investment Account objects with respective data - WITH MONTHLY CONTRIBUTION DEPOSIT
@param accountNumber:		Account number, accessed from AccountNumber as a pointer
@param initialAmount:		Begining balance of the account as a double
@param annualInterestRate:	Annual interest rate as a double
@param monthlyDeposit:		Monthly contribution ammount 
@return						Investment Account object, inherited from Account class
*/
InvestmentAccount::InvestmentAccount(AccountNumber* accountNumber, double initialAmount, double annualInterestRate, double monthlyDeposit)
	:Account(accountNumber, "Investment Compund Interest Account - Includes Monthly Contribution")
{
	this->initialAmount			= initialAmount;
	this->annualInterestRate	= annualInterestRate;
	this->monthlyDeposit		= monthlyDeposit;
}

/*
Calculates the ending balance of the account per annum
@param numYears:			Number of years to invest
@return						Ending balance per year, based on number of years and interest rate
*/
double InvestmentAccount::getEndingBalance(int numYears) {
	double endingBalance = initialAmount;

	for (int i = 1; i <= (12 * numYears); i++) {
		double monthlyInterestEarned = (monthlyDeposit + endingBalance) * ((annualInterestRate / 100) / 12);
		endingBalance += monthlyInterestEarned + monthlyDeposit;
	}

	return endingBalance;
}

/*
Calculates the amount of interest earned per year
@param numYears:	Number of years to invest
@return				Compounded interest per annum
*/
double InvestmentAccount::getInterestEarned(int numberOfYears)
{
	double interestEarned;
	if (numberOfYears == 1) {
		interestEarned = getEndingBalance(numberOfYears) - initialAmount;
	}
	else {
		interestEarned = getEndingBalance(numberOfYears) - getEndingBalance(numberOfYears - 1);
	}
	
	interestEarned -= (monthlyDeposit * 12);

	return interestEarned;
}

/*
Formats the ending balance first by rounding to two decimal places, then format into a string
@param numYears:	Number of years to invest
@return				Ending balance rounded in string type
*/
string InvestmentAccount::getEndingBalanceFormatted(int numberOfYears)
{
	return format(round(getEndingBalance(numberOfYears), 2));
}

/*
Formats the interest earned first by rounding to two decimal places, then format into a string
@param numYears:	Number of years to invest
@return				Interest earned rounded in string type
*/
string InvestmentAccount::getInterestEarnedFormatted(int numberOfYears)
{
	return format(round(getInterestEarned(numberOfYears), 2));
}

/*
Displays a concatinated string containing all pertinent information about the account:
	Initial Amount
	Monthly Deposit
	Annual Interest Rate
@return	String of account details
*/
string InvestmentAccount::getAccountDetails()
{
	string accountDetails;
	accountDetails = "Initial Amount: $" + format(round(initialAmount, 2)) +" | Monthly Deposit: $" + format(round(monthlyDeposit, 2)) + " | Annual Interest Rate: " + format(round(annualInterestRate, 2)) + "%\n";
	return accountDetails;
}

// Three getter methods to access private data types in initial class
double InvestmentAccount::getInitialAmount()
{
	return initialAmount;
}

double InvestmentAccount::getMonthlyDeposit()
{
	return monthlyDeposit;
}

double InvestmentAccount::getAnnualInterestRate()
{
	return annualInterestRate;
}
