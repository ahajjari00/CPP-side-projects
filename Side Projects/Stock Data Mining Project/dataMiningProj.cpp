// dataMiningProj.cpp
// CREATED BY AMIR HAJJARI - 1/17/2020
// Data extracted from: https://finance.yahoo.com/quote/GOOG?p=GOOG
// Please refer to "README" before using program

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;


const int NUM_DATA_PIECES = 121; // FORMULA: (Number of years of data) * (12) + 1

void fill_up_arrays(ifstream& inputCSV, string dates[], string closingVals[], string volumes[], string volumeAdj[]);
// function will fill up the arrays to store info from the CSV file



void skip_over_line(istream& inputSource);
// function will read through first line of CSV file



void check_arrays(ostream& output, string dates[], string closingVals[], string volumes[], string volumeAdj[]);
// function will output to the console window the data that was stored in order to make sure that the arrays were filled correctly



void output_results(ofstream& outputSource, string dates[], string closingVals[], string volumes[], string volumeAdj[], int closingValsAdj[], int volumesAdj[]);
// function will output the 10 best months and 10 worst months for google stock onto a text file



void selec_sort(int a[], int total_indeces, string dates[], int volumesAdj[]);

int find_smallest_index(const int a[], int current_index, int total_indeces);

void swap_values(string& x, string& y);

void swap_values(int& x, int& y);



int main()
{
	ifstream inputSource;

	cout << "Please enter the name of the CSV file to be parsed: ";
	string inputFile;
	cin >> inputFile;
	inputSource.open(inputFile);

	if (inputSource.fail())
	{
		do
		{
			cout << "Sorry, that file was not in the directory, please try again: ";
			cin >> inputFile;
			inputSource.open(inputFile);
		} while (inputSource.fail());
	}

	string dates[NUM_DATA_PIECES];
	string closingVals[NUM_DATA_PIECES];
	string volume[NUM_DATA_PIECES];
	string volumeAdj[NUM_DATA_PIECES];

	fill_up_arrays(inputSource, dates, closingVals, volume, volumeAdj);
	inputSource.close();

	check_arrays(cout, dates, closingVals, volume, volumeAdj);


	ofstream outputSource;
	string outputFile;
	cout << "Please enter the name of the output .txt file you "
		"would like the results to be output to: ";
	cin >> outputFile;
	outputSource.open(outputFile);

	int closingValsAdj[NUM_DATA_PIECES];
	int volumesAdj[NUM_DATA_PIECES];

	for (int i = 0; i < NUM_DATA_PIECES - 1; i++)
	{
		closingValsAdj[i] = stoi(closingVals[i]);
		volumesAdj[i] = stoi(volumeAdj[i]);
	}

	output_results(outputSource, dates, closingVals, volume, volumeAdj, closingValsAdj, volumesAdj);

}

void skip_over_line(istream& inputSource)
{
	char next;
	do
	{
		inputSource.get(next);

	} while (next != '\n');
}

void fill_up_arrays(ifstream& inputCSV, string dates[], string closingVals[], string volumes[], string volumeAdj[])
{
	skip_over_line(inputCSV);

	int i = 0;
	while (i < NUM_DATA_PIECES - 1)
	{
		getline(inputCSV, dates[i], ',');
		getline(inputCSV, closingVals[i], ',');
		getline(inputCSV, volumes[i], ',');
		getline(inputCSV, volumeAdj[i], '\n');
		i++;
	}

	cout << "Data has been entered.\n";
	cout << "Press any character to continue.\n\n\n";
	char next;
	cin >> next;

	return;
}

void check_arrays(ostream& output, string dates[], string closingVals[], string volumes[], string volumeAdj[])
{
	output << "Here is the data that was extraced.\n\n";

	output << "Date" << "\t\t" "Close" << "\t\t" "Volume" << "\t\t" << "Volume Adjusted * E^6" << endl;

	for (int i = 0; i < NUM_DATA_PIECES -1; i++)
	{
		output << i+1 << "\t" << dates[i] << "\t" << closingVals[i] << "\t\t" << volumes[i] << "\t\t" << volumeAdj[i] << endl;
	}


	output << "Press any character to continue.\n\n\n";
	char next;
	cin >> next;

	return;
}

void output_results(ofstream& outputSource, string dates[], string closingVals[], string volumes[], string volumeAdj[], int closingValsAdj[], int volumesAdj[])
{

	selec_sort(closingValsAdj, NUM_DATA_PIECES, dates, volumesAdj);

	outputSource << "Worst months" << "\t" << "Closing" << "\t\t" << "Vol Adj * E^6" << endl;
	for (int k = 1; k < 11; k++)
	{
		outputSource << k << ": " << dates[k] << "\t" << closingValsAdj[k] << "\t\t" << volumesAdj[k] << endl;
	}


	outputSource << endl << endl;


	outputSource << "Best months" << "\t" << "Closing" << "\t\t" << "Vol Adj * E^6" << endl;
	int j = 1;
	for (int i = NUM_DATA_PIECES - 1; i > (NUM_DATA_PIECES -1) - 10; i--)
	{
		outputSource << j << ": " << dates[i] << "\t" << closingValsAdj[i] << "\t\t" << volumesAdj[i] << endl;
		j++;
	}


}

void selec_sort(int a[], int total_indeces, string dates[], int volumesAdj[])
{
	int next_smallest_index;
	for (int i = 0; i < total_indeces; i++)
	{
		next_smallest_index = find_smallest_index(a, i, total_indeces);

		swap_values(a[i], a[next_smallest_index]);
		swap_values(dates[i], dates[next_smallest_index]);
		swap_values(volumesAdj[i], volumesAdj[next_smallest_index]);
	}
}

int find_smallest_index(const int a[], int current_index, int total_indeces)
{
	int minVal = a[current_index];
	int minIndex = current_index;
	for (int i = current_index + 1; i < total_indeces; i++)
	{
		if (minVal > a[i])
		{
			minVal = a[i];
			minIndex = i;
		}
	}

	return minIndex;
}

void swap_values(string& x, string& y)
{
	string temp;
	temp = x;
	x = y;
	y = temp;

	return;
}

void swap_values(int& x, int& y)
{
	int temp;
	temp = x;
	x = y;
	y = temp;

	return;

}
