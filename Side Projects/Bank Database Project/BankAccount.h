#ifndef BANK_ACCOUNT_H
#define BANK_ACCOUNT_H

#include <iostream>
#include <string>
using namespace std;

const int MAX_NAME_SIZE = 30;

class BankAccount
{
private:
	char name[MAX_NAME_SIZE]; // stores name of the Account Owner's name
	char accountType; // 'C' represents checkings, 'S' represents savings
	double amount; // stores amount of money in the account
	int accountNumber; // represents the Account Owner's ID used to access the data of the account
	double interestRate; // interest rate associated with the account

public:
	BankAccount();

	// if "inp_amount" <= 0, error message is shown
	void depositAmount(double inp_amount);

	// expects "inp_amount" to be a postive number
	void withdrawAmount(double inp_amount);

	// returns "amount" member
	double getAmount() const;
	
	// uses user input to fill all data members
	void getAccountInfo();

	double getAccountNumber() const;

	void outputAccountInfo() const;
	
	void setAccountType(char accountType);

	void setAccountNumber(int accountNumber);

	void setInterestRate(double interestRate);

};

#endif