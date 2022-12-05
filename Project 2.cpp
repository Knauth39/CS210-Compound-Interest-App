#include <iostream>
#include <iomanip>
#include "Account.h"
#include "InvestmentAccount.h"
#include "AccountNumber.h"
#include <string>

using namespace std;

// Epsilon value
const double TOLERANCE = 0.01;

// Main Class function prototypes

// Displays output tables
void displayOutput(Account* account, int numberOfYears) {  
    // Format variables
    string bufferTab1 = "\t";
    string bufferTab2 = "\t\t";

    // Print account bullet point data
    cout << bufferTab1 << "ACCOUNT DETAILS" << endl;
    cout << bufferTab1 << "Account Number: " << account->getAccountNumber()->getAccountNumber() << endl;
    cout << bufferTab1 << "Account Type: " << account->getAccountType() << endl;
    cout << bufferTab1 << "Account Details: " << account->getAccountDetails() << endl;
    cout << endl;

    // Header row for table
    cout << bufferTab1 << right << "Year" << bufferTab2 << right << setw(5) << "Balance" << bufferTab2 << "Interest Earned" << endl;
    
    // Data rows for table - loop
    // Iterate through number of years to print the year
    int i;
    for (i = 1; i <= numberOfYears; i++) {      
        cout << bufferTab1 << right << i;
        cout << bufferTab2 << right << setw(5) << "$" << account->getEndingBalanceFormatted(i);
        cout << bufferTab2 << "$" << account->getInterestEarnedFormatted(i) << endl;
        cout << endl;
    }
}


int main()
{
    // Declare main input variables
    double initialAmount;
    double monthlyContribution;
    double annualInterest;
    int numYears;
    bool inputValid = false;
    
    // Loop of user input - calculations will execute as long as there are no negative numbers
    do {
        cout << "Enter initial amount: " << endl;
        cin >> initialAmount;
        cout << "Enter your monthly contribution amount: " << endl;
        cin >> monthlyContribution;
        cout << "Enter the annual interest rate in percent form (number only): " << endl;
        cin >> annualInterest;
        cout << "Enter the number of years to invest: " << endl;
        cin >> numYears;

        if (initialAmount < 0 || monthlyContribution < 0 || annualInterest < 0 || numYears < 0) {
            inputValid = false;
        }
        else {
            inputValid = true;
        }
    } while (inputValid == false);

    // InvestmentAccount pointer variables - Exclude Monthly Deposits and Include Monthly Deposits
   
    AccountNumber* accountNumberOne = new AccountNumber();
    AccountNumber* accountNumberTwo = new AccountNumber();
    
    InvestmentAccount* exclueMonthlyContribution    = new InvestmentAccount(accountNumberOne, initialAmount, annualInterest);
    InvestmentAccount* includeMonthlyContribution   = new InvestmentAccount(accountNumberTwo, initialAmount, annualInterest, monthlyContribution);

    // Display the output for each investment account
    displayOutput(exclueMonthlyContribution, numYears);
    displayOutput(includeMonthlyContribution, numYears);


}
