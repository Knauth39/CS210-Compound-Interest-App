#pragma once
#include "Account.h"

class InvestmentAccount : public Account
{

public:
	InvestmentAccount(AccountNumber* accountNumber, double initialAmount, double annualInterestRate);
	InvestmentAccount(AccountNumber* accountNumber, double initialAmount, double annualInterestRate, double monthlyDeposit);

	// Inherited methods from Account Parent Class
	virtual double getEndingBalance(int numberOfYears);
	virtual double getInterestEarned(int numberOfYears);
	virtual string getEndingBalanceFormatted(int numberOfYears);
	virtual string getInterestEarnedFormatted(int numberOfYears);
	virtual string getAccountDetails();

	double getInitialAmount();			// initialAmount
	double getMonthlyDeposit();			// monthlyDeposit
	double getAnnualInterestRate();		// annualInterestRate


private:
	double initialAmount;
	double monthlyDeposit;
	double annualInterestRate;

};

