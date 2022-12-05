#pragma once
class AccountNumber
{
public:
	AccountNumber();
	int getAccountNumber();

private:
	static int nextAccountNumber;		
	int accountNumber;
};
