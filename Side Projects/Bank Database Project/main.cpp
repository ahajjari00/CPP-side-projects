// Bank Account Database project
// Created by Amir Hajjari on 5-22-20
// Please reference "README.txt" for more info!


// NOTE: .bin files did not work, use .dat files instead

#include "BankAccount.h"
#include <string>
#include <fstream> // used for the binary file storage/extraction/manipulation
using namespace std;

// Option screened displayed throughout operation of the program
void displayScreen();

// creates new account in the database
void createAccount();

// displays an account's information
// takes the accountNumber as the input to find the account info
void displayAccountDetails(int accNum);

// function to deposit to an account
void depositToAccount(int accNum, double inp_deposit);

// function to withdraw from an account
void withdrawFromAccount(int accNum, double inp_deposit);

// function to see all accounts in the database
void outputAll();

// will remove an account by moving all accounts that should not be deleted to a
// new account, then renaming that new account to the old account
void removeAccount(int accNum);


int main()
{
	cout << "Welcome to the Bank Account Database project!\n";
	cout << "Press any character to continue.";

	cin.get();

	int accountNumber;
	double inputAmount; // for withdraw and deposit
	char input;
	do
	{
		system("cls");
		displayScreen();
		cin >> input;														

		switch (input)
		{
		case '1':
			createAccount();
			break;

		case '2':
			cout << "Please enter your account number: ";
			cin >> accountNumber;

			cout << "Please enter your deposit amount: ";
			cin >> inputAmount;
			depositToAccount(accountNumber, inputAmount);
			break;

		case '3':
			cout << "Please enter your account number: ";
			cin >> accountNumber;

			cout << "Please enter your withdraw amount: ";
			cin >> inputAmount;
			withdrawFromAccount(accountNumber, inputAmount);
			break;

		case '4':
			cout << "Please enter your account number: ";
			cin >> accountNumber;
			displayAccountDetails(accountNumber);
			break;

		case '5':
			outputAll();
			break;

		case '6':
			cout << "Please enter your account number: ";
			cin >> accountNumber;
			removeAccount(accountNumber);
			break;

		case '7': // exits program
			break;

		default: // accounts for random input
			break;

		}
		cin.get();

	} while (input != '7');

	cout << "Have a nice rest of your day!\n";
}

void displayScreen()
{
	cout << "(1) Create a new account\n";										// GOOD
	cout << "(2) Deposit to an account\n";										// GOOD
	cout << "(3) Withdraw from an account\n";									// GOOD
	cout << "(4) Check information/balance of an account\n";					// GOOD
	cout << "(5) See all accounts' information in the database\n";				// GOOD
	cout << "(6) Delete an account\n";
	cout << "(7) Exit\n";
}

void createAccount()
{
	BankAccount newAccount;
	newAccount.getAccountInfo();

	ofstream outputFile;
	outputFile.open("database.dat", ios::binary | ios::app); // using "append" so if the file already exists, just add on to it

	outputFile.write(reinterpret_cast<char *>(&newAccount), sizeof(BankAccount));
	outputFile.close();

	newAccount.outputAccountInfo();
	cin.ignore();
}

void displayAccountDetails(int accNum)
{
	BankAccount depositAccount;

	bool found = false;

	ifstream inputFile;
	inputFile.open("database.dat", ios::binary);
	if (inputFile.fail())
	{
		cout << "Sorry, I could not find that file.\n";
		cin.ignore();
		return;
	}


	while (inputFile.read(reinterpret_cast<char*> (&depositAccount), sizeof(BankAccount)))
	{
		if (depositAccount.getAccountNumber() == accNum)
		{
			found = true;
			depositAccount.outputAccountInfo();
			cin.ignore();
		}
	}

	inputFile.close();

	if (found == false)
		cout << "\n\nAccount number does not exist";
}


void depositToAccount(int accNum, double inp_deposit)
{
	BankAccount inputAccount;

	fstream inputFile;
	inputFile.open("database.dat", ios::binary | ios::in | ios::out); // "in" and "out" as we are both reading and writing to the file
	if (inputFile.fail())
	{
		cout << "Error in opening the file.\n";
		cin.ignore();
		return;
	}

	bool found = false;

	while (!inputFile.fail() && found == false)
	{
		inputFile.read(reinterpret_cast<char*>(&inputAccount), sizeof(BankAccount));

		if (inputAccount.getAccountNumber() == accNum)
		{
			inputAccount.depositAmount(inp_deposit);
			inputAccount.outputAccountInfo();

			int position = -1 * static_cast<int>(sizeof(BankAccount)); // since we are essentially creating a new entry (relative to the database), 
																		// we must use "seekp" to move back one place in the .dat file from the current
																			// position to overide the current entry
			inputFile.seekp(position, ios::cur);

			inputFile.write(reinterpret_cast<char*>(&inputAccount), sizeof(BankAccount)); // writes the new info into the binary file
																							// not just to the object in the cpp program

			cin.ignore();
			found = true;
		}
	}

	inputFile.close();

	if (found == false)
	{
		cout << "Could not find the account in the database\n";
		cin.ignore();
	}


}

void withdrawFromAccount(int accNum, double inp_deposit)
{
	BankAccount inputAccount;

	fstream inputFile;
	inputFile.open("database.dat", ios::binary | ios::in | ios::out); // "in" and "out" as we are both reading and writing to the file
	if (inputFile.fail())
	{
		cout << "Error in opening the file.\n";
		cin.ignore();
		return;
	}

	bool found = false;

	while (!inputFile.eof() && found == false)
	{
		inputFile.read(reinterpret_cast<char*>(&inputAccount), sizeof(BankAccount));

		if (inputAccount.getAccountNumber() == accNum)
		{
			inputAccount.withdrawAmount(inp_deposit);
			inputAccount.outputAccountInfo();

			int position = -1 * static_cast<int>(sizeof(BankAccount)); // since we are essentially creating a new entry (relative to the database), 
																		// we must use "seekp" to move back one place in the .dat file from the current
																			// position to overide the current entry
			inputFile.seekp(position, ios::cur);

			inputFile.write(reinterpret_cast<char*>(&inputAccount), sizeof(BankAccount)); // writes the new info into the binary file
																							// not just to the object in the cpp program

			cin.ignore();
			found = true;
		}
	}

	inputFile.close();

	if (found == false)
	{
		cout << "Could not find the account in the database\n";
		cin.ignore();
	}
}

void outputAll()
{
	BankAccount traverseAccount;
	ifstream inputFile;
	inputFile.open("database.dat", ios::binary); // if no data is in the file, then will execute if block as we are not using
													// "ios::app"

	if (inputFile.fail())
	{
		cout << "Sorry, could not open the file\n";
		cin.ignore();
		return;
	}


	while (inputFile.read(reinterpret_cast<char*>(&traverseAccount), sizeof(BankAccount)))
	{
		traverseAccount.outputAccountInfo();
	}
	inputFile.close();
	cin.ignore();

}


void removeAccount(int accNum)
{
	BankAccount tempAccount;

	ifstream inputFile;
	ofstream outputFile;

	inputFile.open("database.dat", ios::binary);
	if (inputFile.fail())
	{
		cout << "Error in opening file.\n";
		cin.get();
		return;
	}

	outputFile.open("temporary.dat", ios::binary);

	while (inputFile.read(reinterpret_cast<char*>(&tempAccount), sizeof(BankAccount)))
	{
		if (tempAccount.getAccountNumber() != accNum)
		{
			outputFile.write(reinterpret_cast<char*>(&tempAccount), sizeof(BankAccount));
			// only writes to this temporary file if we do not find that same account number
		}
	}

	inputFile.close();
	outputFile.close();

	remove("database.dat");
	rename("temporary.dat", "database.dat");


	cout << "Record has been deleted.\n";
	cin.ignore();
}