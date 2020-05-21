// LeBron Hash Table Project
// Created by Amir Hajjari
// Please reference "README.txt" for more info!

// ---------------------USE THIS FILE -> LeBron CSV data ADJUSTED.csv----------------------------------

#include "LeBron.h"
using namespace std;
using namespace AMIR_LEBRON;

// functions to test the functions in the switch case statements

// Adds the data from the csv to the Hash Table then outputs the Hash table
void testLeBron1(LeBron* object, string inp_data[][NUM_STATS]);

// Outputs all the Data Items in a specific index of the Hash table
void testLeBron2(LeBron* object);

// Outputs the specific stat data from whatever season the user specifies
void testLeBron3(LeBron* object, string& inp_season, string& stat_wanted);


int main()
{
	cout << "WELCOME TO THE LEBRON JAMES HASH TABLE PROJECT!\n";
	cout << "Created by Amir Hajjari\n\n\n";

	cout << "Input a CSV file to extract the data\n";
	ifstream LeBronInput;
	string data[NUM_SEASONS][NUM_STATS];
	string fileName = getDataCSV(LeBronInput, data);
	bool extractData = outputCSVData(LeBronInput, data, fileName);

	if (extractData)
		cout << "Good extraction!\n";
	else
	{
		cout << "Bad extraction!\n";
		exit(1);
	}

	cout << endl << endl;

	LeBron* test = new LeBron; // LeBron object used in the program/testing

	test->AddItems(data);

	int choice;
	do
	{
		cout << "Please enter your choice!\n\n";

		cout << "(1) Print the seasons' data in the stored hash table\n";
		cout << "(2) Print all the seasons' data in a specifc index of the hash table\n";
		cout << "(3) Find the specific statistic of any season\n";
		cout << "(4) Exit the program\n";

		cin >> choice;
		cout << endl << endl;

		string season, stat; // passed by reference in the "testLeBron3" function

		switch (choice)
		{
		case 1:
			testLeBron1(test, data);
			cout << endl << endl;
			break;

		case 2:
			testLeBron2(test);
			cout << endl << endl;
			break;

		case 3:
			testLeBron3(test, season, stat);
			cout << endl << endl;
			break;
		case 4:
			break;
		}

	} while (choice != 4); // signals user is finished

	cout << "Thanks!\n";
	
}

void testLeBron1(LeBron* object, string inp_data[][NUM_STATS])
{
	object->printTable();
}

void testLeBron2(LeBron* object)
{
	int index;
	cout << "Please enter the index you want to see the data of: ";
	cin >> index;

	if ((index < 0) || (index > object->getTableSize()))
	{
		cout << "Sorry, that is not a valid index\n";
		return;
	}

	object->printItemsInIndex(index);
}


void testLeBron3(LeBron* object, string& inp_season, string& stat_wanted)
{
	cout << "Please enter the statistic you would like to see the data of: ";
	cin >> stat_wanted;

	cout << "Please enter the season you would like to see the " << stat_wanted << " of: ";
	cin >> inp_season;

	object->findStatData(inp_season, stat_wanted);
}

