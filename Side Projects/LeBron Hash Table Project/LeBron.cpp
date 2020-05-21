#include "LeBron.h"
#include <string>
using namespace std;

namespace AMIR_LEBRON
{

	LeBron::LeBron()
	{
		for (int i = 0; i < tableSize; i++)
		{
			HashTable[i] = new SeasonData;
			HashTable[i]->season = "";
			HashTable[i]->team = "";
			HashTable[i]->numGames = 0;
			HashTable[i]->mpg = 0;
			HashTable[i]->fg = 0;
			HashTable[i]->threePt = 0;
			HashTable[i]->twoPt = 0;
			HashTable[i]->ft = 0;
			HashTable[i]->ORB = 0;
			HashTable[i]->DRB = 0;
			HashTable[i]->ASST = 0;
			HashTable[i]->STL = 0;
			HashTable[i]->BLK = 0;
			HashTable[i]->TOV = 0;
			HashTable[i]->PTS = 0;
			HashTable[i]->next = nullptr;
		}
	}

	int LeBron::hash(string inp_season)
	{
		int hash = 0;

		for (int i = 0; i < inp_season.length(); i++)
		{
			hash = hash + static_cast<int>(inp_season[i]);
		}

		int index;
		index = hash % tableSize;

		return index;
	}
	void LeBron::AddItems(string data_input[][NUM_STATS])
	{
		int index;
		int count = 1; // testing where error is
		for (int i = 0; i < NUM_SEASONS; i++)
		{
			index = hash(data_input[i][0]); // 0th index is the season year, which is what we are hashing by

			if (HashTable[index]->season == "") // nothing in that specific index
			{
				HashTable[index]->season = data_input[i][0];
				HashTable[index]->team = data_input[i][1];
				HashTable[index]->numGames = stoi(data_input[i][2]);
				HashTable[index]->mpg = stod(data_input[i][3]);
				HashTable[index]->fg = stod(data_input[i][4]);
				HashTable[index]->threePt = stod(data_input[i][5]);
				HashTable[index]->twoPt = stod(data_input[i][6]);
				HashTable[index]->ft = stod(data_input[i][7]);
				HashTable[index]->ORB = stod(data_input[i][8]);
				HashTable[index]->DRB = stod(data_input[i][9]);
				HashTable[index]->ASST = stod(data_input[i][10]);
				HashTable[index]->STL = stod(data_input[i][11]);
				HashTable[index]->BLK = stod(data_input[i][12]);
				HashTable[index]->TOV = stod(data_input[i][13]);
				HashTable[index]->PTS = stod(data_input[i][14]);
				HashTable[index]->next = nullptr;
			}

			else // create new bucket to be stored at the index (now at least 2 items in a bucket)
			{
				SeasonData* Ptr = HashTable[index];
				SeasonData* newData = new SeasonData;

				newData->season = data_input[i][0];
				newData->team = data_input[i][1];
				newData->numGames = stoi(data_input[i][2]);
				newData->mpg = stod(data_input[i][3]);
				newData->fg = stod(data_input[i][4]);
				newData->threePt = stod(data_input[i][5]);
				newData->twoPt = stod(data_input[i][6]);
				newData->ft = stod(data_input[i][7]);
				newData->ORB = stod(data_input[i][8]);
				newData->DRB = stod(data_input[i][9]);
				newData->ASST = stod(data_input[i][10]);
				newData->STL = stod(data_input[i][11]);
				newData->BLK = stod(data_input[i][12]);
				newData->TOV = stod(data_input[i][13]);
				newData->PTS = stod(data_input[i][14]);
				newData->next = nullptr;

			
				while (Ptr->next != nullptr)
				{
					Ptr = Ptr->next;
				}
				Ptr->next = newData;
				

			}

			/* USED in testing 
			cout << "The " << count << " season worked\n";
			count++;
			*/
		}

	}

	void LeBron::printTable()
	{
		int number;

		for (int i = 0; i < tableSize; i++)
		{
			number = numberOfItemsInIndex(i);
			cout << number << " of buckets in index " << i << endl;
			cout << "Season: " << HashTable[i]->season << endl;
			cout << "Team: " << HashTable[i]->team << endl;
			cout << "Number of games played: " << HashTable[i]->numGames << endl;
			cout << "Minutes: " << HashTable[i]->mpg << endl;
			cout << "Field goal percentage: " << HashTable[i]->fg << endl;
			cout << "Three point percentage: " << HashTable[i]->threePt << endl;
			cout << "Two point percentage: " << HashTable[i]->twoPt << endl;
			cout << "Free throw percentage: " << HashTable[i]->ft << endl;
			cout << "Offensive rebounds: " << HashTable[i]->ORB << endl;
			cout << "Defensive rebounds: " << HashTable[i]->DRB << endl;
			cout << "Assists: " << HashTable[i]->ASST << endl;
			cout << "Steals: " << HashTable[i]->STL << endl;
			cout << "Blocks: " << HashTable[i]->BLK << endl;
			cout << "Turnovers: " << HashTable[i]->TOV << endl;
			cout << "Points: " << HashTable[i]->PTS << endl;
			cout << "---------------------" << endl;
		}
	}

	int LeBron::numberOfItemsInIndex(int index)
	{
		int count = 0;

		if (HashTable[index]->season == "")
			return count; // signifies nothing in the index

		count++;

		SeasonData* Ptr = HashTable[index];
		while (Ptr->next != nullptr)
		{
			Ptr = Ptr->next;
			count++;
		}

		return count;
	}

	void LeBron::printItemsInIndex(int index)
	{
		SeasonData* temp = HashTable[index];

		if (temp->season == "")
		{
			cout << "There is no data in this specific index.\n";
			return;
		}

		while (temp != nullptr)
		{

			cout << "Season: " << temp->season << endl;
			cout << "Team: " << temp->team << endl;
			cout << "Number of games played: " << temp->numGames << endl;
			cout << "Minutes: " << temp->mpg << endl;
			cout << "Field goal percentage: " << temp->fg << endl;
			cout << "Three point percentage: " << temp->threePt << endl;
			cout << "Two point percentage: " << temp->twoPt << endl;
			cout << "Free throw percentage: " << temp->ft << endl;
			cout << "Offensive rebounds: " << temp->ORB << endl;
			cout << "Defensive rebounds: " << temp->DRB << endl;
			cout << "Assists: " << temp->ASST << endl;
			cout << "Steals: " << temp->STL << endl;
			cout << "Blocks: " << temp->BLK << endl;
			cout << "Turnovers: " << temp->TOV << endl;
			cout << "Points: " << temp->PTS << endl;
			cout << "---------------------" << endl;

			temp = temp->next;
		}
	}

	void LeBron::findStatData(string inp_season, string stat_wanted)
	{

		int index = hash(inp_season); // gets us to the correct index

		int numItems = numberOfItemsInIndex(index);

		if (numItems == 0)
			cout << "Sorry, there was an error in the input.\n";


		else // numItems >= 1
		{
			SeasonData* temp = HashTable[index];
			while (temp->season != inp_season) // if numItems == 1, this loop will not execute
			{
				temp = temp->next;
			}

			if (stat_wanted == "team")
				cout << "In the " << inp_season << ", LeBron played for " << temp->team << endl;

			else if (stat_wanted == "numGames")
				cout << "In the " << inp_season << ", LeBron played " << temp->numGames << " games" << endl;

			else if (stat_wanted == "mpg")
				cout << "In the " << inp_season << ", LeBron played " << temp->mpg << " minutes per game" << endl;

			else if (stat_wanted == "fg")
				cout << "In the " << inp_season << ", LeBron averaged " << temp->fg << " field goal percentage" << endl;

			else if (stat_wanted == "threePt")
				cout << "In the " << inp_season << ", LeBron averaged " << temp->threePt << " three point field goal percentage" << endl;

			else if (stat_wanted == "twoPt")
				cout << "In the " << inp_season << ", LeBron averaged " << temp->twoPt << " two point field goal percentage" << endl;

			else if (stat_wanted == "ORB")
				cout << "In the " << inp_season << ", LeBron averaged " << temp->ORB << " offensive rebounds per game" << endl;

			else if (stat_wanted == "DRB")
				cout << "In the " << inp_season << ", LeBron averaged " << temp->DRB << " defensive rebounds per game" << endl;

			else if (stat_wanted == "ASST")
				cout << "In the " << inp_season << ", LeBron averaged " << temp->ASST << " assists per game" << endl;

			else if (stat_wanted == "STL")
				cout << "In the " << inp_season << ", LeBron averaged " << temp->STL << " assists per game" << endl;

			else if (stat_wanted == "BLK")
				cout << "In the " << inp_season << ", LeBron averaged " << temp->BLK << " blocks per game" << endl;

			else if (stat_wanted == "TOV")
				cout << "In the " << inp_season << ", LeBron averaged " << temp->TOV << " turnovers per game" << endl;

			else if (stat_wanted == "PTS")
				cout << "In the " << inp_season << ", LeBron averaged " << temp->PTS << " per game" << endl;

			else
				cout << "Sorry, invalid input\n";
		}

		return;
	}

	int LeBron::getTableSize()
	{
		return tableSize;
	}



	LeBron::~LeBron()
	{
		SeasonData* delPtr;
		for (int i = 0; i < tableSize; i++)
		{
			while (HashTable[i] != nullptr)
			{
				delPtr = HashTable[i];
				HashTable[i] = HashTable[i]->next;
				delete delPtr;
			}
		}

		cout << "DESTRUCTOR\n";
	}







	// --------------STREAM HELPER FUNCTIONS USED TO EXTRACT DATA FROM THE CSV FILE AND STORE IN 2D ARRAY--------------------------------


	// function to get the file name of the Excel file
	string getFileName(ifstream& inp)
	{
		string fileName = "";
		cout << "Please enter the name of the input .csv file: ";
		getline(cin, fileName);
		return fileName;
	}



	// function to extract data from the CSV file and store into the 2D array
	// for the the specific Hash Table Object (specific player)
	// returns the name of the file which will be used in the "headerOutput" function
	string getDataCSV(ifstream& inp, string data[][NUM_STATS])
	{
		string fileName = getFileName(inp);

		inp.open(fileName);

		while (inp.fail())
		{
			cout << "Sorry, could not find the file named " << "\"" << fileName
				<< "\"" << " in the directory\n";
			cout << "Please try to enter the name of the file again: ";
			cin >> fileName;
		}

		cout << "Found the file!\n";
		cout << "About to extract the data from the file...\n";

		// only "csv" file type will work for the extraction, "xlsx" will not

		char next;
		do
		{
			inp.get(next); // allows us to not get the first line of input from the CSV
							// which is the line where the labels are

		} while (next != '\n');

		string line;
		for (int i = 0; i < NUM_SEASONS; i++)
		{
			getline(inp, line, '\n');
			stringstream ss(line);
			int j = 0;
			while (getline(ss, line, ','))		// implemented stringstream because at the end of the line, there is no ',' delimeter
			{
				data[i][j] = line;
				j++;
			}
		}
		inp.close();


		cout << "Data extraction has finished!\n";
		cout << "File has been closed!\n";

		return fileName;
	}

	// outputs the header of the file passed
	void headerOutput(ifstream& inp, string fileName)
	{
		inp.open(fileName); // assuming the file exists and is correct due to the
							// checks implemented eariler before this point

		string next;
		getline(inp, next, '\n');

		stringstream ss(next);
		while (getline(ss, next, ','))
			cout << next << "\t";

		cout << endl;

		inp.close();
	}

	// precondition: already extracted data from CSV file
	// postcondition: if extracted correctly, NUM_SEASONS * NUM_STATS = "count" variable
	bool outputCSVData(ifstream& inp, string data[][NUM_STATS], string fileName)
	{
		bool goodExtraction;
		cout << "Here is what was found for the player:\n\n";

		headerOutput(inp, fileName);

		int count = 0;
		for (int i = 0; i < NUM_SEASONS; i++)
		{
			for (int j = 0; j < NUM_STATS; j++)
			{
				cout << data[i][j] << "\t";
				count++;
			}
			cout << endl; // one season of data per line
		}
		cout << endl << endl;
		cout << "COUNT " << count << endl;

		if (count == NUM_SEASONS * NUM_STATS)
			goodExtraction = true;
		else
			goodExtraction = false;

		return goodExtraction;
	}
}