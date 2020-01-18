/*
	code to generate output bar graph displaying the number of items sold by all the plants of 
	a company. Every 1000 items sold signifies one '*'. Data read in from a text file
*/

#include <iostream>
#include <fstream>
using namespace std;

void getData(int a[], int b[], int c[], int d[], int maxIndeces, istream& inputData);
// precondition: arrays exist, input file exists
// postcondition: every array holds all sold products for their respective plant

void readThroughLabels(istream& inputSource);
// precondition: input file is open and still has data to be read through info line
// postcondition: unwanted data is read through

void readThroughplantNumber(istream& inputSource);
// precondition: currently reading plant number value
// postcondition: reading "Categ 1" value

void generateValues(int& plant_1, int& plant_2, int& plant_3, int& plant_4, const int a[], const int b[], const int c[], const int d[]);
// precondition: all 4 arrays hold the number of items sold by each plant in its indexes.
// postcondition: the 4 pass-by-ref variables will hold the sum of the total number of items sold by their respective plant

void outputResults(ostream& outputFile, int plant_1, int plant_2, int plant_3, int plant_4);
// precondition: all the "int" variables hold values
// postcondition: output file will be generated conveying the results in desired form mentioned in description of project

const int NUM_CATEGORIES = 4;

int main()
{
	int plant1[4]; int plant2[4]; int plant3[4]; int plant4[4];

	ifstream inputValues;
	inputValues.open("inputData.txt");

	getData(plant1, plant2, plant3, plant4, NUM_CATEGORIES, inputValues);

	inputValues.close();





	int result1; int result2; int result3; int result4;
	generateValues(result1, result2, result3, result4, plant1, plant2, plant3, plant4);





	ofstream outputFile;
	outputFile.open("outputFile.txt");

	outputResults(outputFile, result1, result2, result3, result4);

}

void getData(int a[], int b[], int c[], int d[], int maxIndeces, istream& inputData)
{
	readThroughLabels(inputData); // after this line, we are now on '1'

	readThroughplantNumber(inputData);

	for (int i = 0; i <= NUM_CATEGORIES - 1; i++)
	{
		inputData >> a[i];
		cout << a[i] << " ";
	}
	cout << endl;

	readThroughplantNumber(inputData);
	readThroughplantNumber(inputData);

	for (int i = 0; i <= NUM_CATEGORIES - 1; i++)
	{
		inputData >> b[i];
		cout << b[i] << " ";
	}
	cout << endl;

	readThroughplantNumber(inputData);
	readThroughplantNumber(inputData);

	for (int i = 0; i <= NUM_CATEGORIES - 1; i++)
	{
		inputData >> c[i];
		cout << c[i] << " ";
	}
	cout << endl;

	readThroughplantNumber(inputData);
	readThroughplantNumber(inputData);

	for (int i = 0; i <= NUM_CATEGORIES - 1; i++)
	{
		inputData >> d[i];
		cout << d[i] << " ";
	}
	cout << endl;

	return;

}

void readThroughLabels(istream& inputSource)
{
	char value;

	do
	{
		inputSource.get(value);

	} while ((value != '\n'));

	return;
}

void readThroughplantNumber(istream& inputSource)
{
	char value;
	inputSource.get(value);

	return;

}


void generateValues(int& plant_1, int& plant_2, int& plant_3, int& plant_4, const int a[], const int b[], const int c[], const int d[])
{
	plant_1 = plant_2 = plant_3 = plant_4 = 0;

	for (int i = 0; i <= NUM_CATEGORIES - 1; i++)
	{
		plant_1 += a[i];
	}

	for (int i = 0; i <= NUM_CATEGORIES - 1; i++)
	{
		plant_2 += b[i];
	}

	for (int i = 0; i <= NUM_CATEGORIES - 1; i++)
	{
		plant_3 += c[i];
	}

	for (int i = 0; i <= NUM_CATEGORIES - 1; i++)
	{
		plant_4 += d[i];
	}

	return;
}


void outputResults(ostream& outputFile, int plant_1, int plant_2, int plant_3, int plant_4)
{
	double adjust1; double adjust2; double adjust3; double adjust4;



	adjust1 = plant_1 % 1000;
	plant_1 -= adjust1;
	if (adjust1 >= 500)
		plant_1 += 1000;

	outputFile << "Plant 1: ";
	int z = 0;
	for(int i = 500; i <= plant_1; i += 1000)
	{
		z += 1;
		outputFile << "*";
	}
	outputFile << " " << z << endl;






	adjust2 = plant_2 % 1000;
	plant_2 -= adjust2;
	if (adjust2 >= 500)
		plant_2 += 1000;

	outputFile << "Plant 2: ";
	int p = 0;
	for (int i = 500; i <= plant_2; i += 1000)
	{
		p += 1;
		outputFile << "*";
	}
	outputFile << " " << p << endl;





	adjust3 = plant_3 % 1000;
	plant_3 -= adjust3;
	if (adjust3 >= 500)
		plant_3 += 1000;

	outputFile << "Plant 3: ";
	int j = 0;
	for (int i = 500; i <= plant_3; i += 1000)
	{
		j += 1;
		outputFile << "*";
	}
	outputFile << " " <<  j << endl;






	adjust4 = plant_4 % 1000;
	plant_4 -= adjust4;
	if (adjust4 >= 500)
		plant_4 += 1000;

	outputFile << "Plant 4: ";
	int k = 0;
	for (int i = 500; i <= plant_4; i += 1000)
	{
		k += 1;
		outputFile << "*";
	}
	outputFile << " " << k << endl;



	return;
}