#ifndef LEBRON_H
#define LEBRON_H

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

// these two values were computed in the Excel spreadsheet included
// in this project file.
// Depending on the player being analyzed, the "NUM_SEASONS" variable 
// will vary, but the "NUM_STATS" will remain constant w/ website being
// used to extract the data
const int NUM_SEASONS = 17;
const int NUM_STATS = 15;

namespace AMIR_LEBRON
{

	class LeBron
	{
	public:
		// create empty buckets at each index of size "tableSize"
		LeBron();


		// hash by the season
		// ex: "2003-2004"
		int hash(string inp_season);

		// function will do the work of adding a season and its 
		// data into a bucket
		void AddItems(string data_input[][NUM_STATS]);

		void printTable();

		void printItemsInIndex(int index);

		void findStatData(string inp_season, string stat_wanted); // returns specific stat data for specified season

		int getTableSize(); // accessor to return table size (used in the switch case of the main program)


		~LeBron();

	private:
		int numberOfItemsInIndex(int index);

		static const int tableSize = 5;


		struct SeasonData
		{
			string season;
			string team; // "1" relative to the function named "statNameFinder"
			int numGames; // "2" ...
			double mpg; 
			double fg; // "4"
			double threePt;
			double twoPt; // "6"
			double ft;
			double ORB; // "8"
			double DRB;
			double ASST; // "10"
			double STL;
			double BLK; // "12"
			double TOV;
			double PTS; // "14"
			SeasonData* next;

		};

		SeasonData* HashTable[tableSize];
	};


	// function to get the file name of the Excel file
	string getFileName(ifstream& inp);


	// function to extract data from the CSV file and store into the 2D array
	// for the the specific Hash Table Object (specific player)
	// returns the name of the file which will be used in the "headerOutput" function
	string getDataCSV(ifstream& inp, string data[][NUM_STATS]);



	// outputs the header of the file passed
	void headerOutput(ifstream& inp, string fileName);



	// precondition: already extracted data from CSV file
	// postcondition: if extracted correctly, NUM_SEASONS * NUM_STATS = "count" variable
	bool outputCSVData(ifstream& inp, string data[][NUM_STATS], string fileName);


}

#endif
