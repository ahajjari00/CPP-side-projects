#include "BankAccount.h"

BankAccount::BankAccount()
{
	// empty
}

void BankAccount::depositAmount(double inp_amount)
{
	amount += inp_amount;
}

void BankAccount::withdrawAmount(double inp_amount)
{
	amount -= inp_amount;
}


double BankAccount::getAmount() const
{
	return amount;
}

double BankAccount::getAccountNumber() const
{
	return accountNumber;
}

void BankAccount::setAccountType(char accountType)
{
	this->accountType = accountType;
}

void BankAccount::setAccountNumber(int accountNumber)
{
	this->accountNumber = accountNumber;
}

void BankAccount::setInterestRate(double interestRate)
{
	this->interestRate = interestRate;
}


void BankAccount::getAccountInfo()
{
	cout << "Please enter the account type (S) or (C): ";
	cin >> accountType;

	cout << "Please enter your starting amount: ";
	cin >> amount;

	cout << "Please enter your interest rate: ";
	cin >> interestRate;

	cout << "Please enter your account number: ";
	cin >> accountNumber;

	cout << "Please enter your name: ";
	cin.ignore(); // needed when using "getline" functions or else the first character read will be '\n' !!!!!
	cin.getline(name, MAX_NAME_SIZE);
}

void BankAccount::outputAccountInfo() const
{
	cout << "NAME\t\t\t" << "TYPE\t\t" << "AMOUNT\t\t" << "ACC#\t\t" << "INT. RATE\n";
	cout << "---------------------------------------------------------------------------------\n";

	cout << name << "\t\t" << accountType << "\t\t" << amount << "\t\t" << accountNumber << "\t\t" << interestRate << endl << endl;
}