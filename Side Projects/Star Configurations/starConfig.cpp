// starConfig.cpp

/*
	code to allow user to choose amongst a pyramid of right-aligned, left-alligned, or center-aligned
	pyramid of stars to be output to the string
*/

#include <iostream>
using namespace std;

void right_pyram(int num_rows);

void left_pyram(int num_rows);

void center_pyram(int num_rows);

void new_line();

int main()
{
	char choice;
	do
	{

		cout << "Please type in '1' for a right-aligned pyramid, "
			<< "'2' for a left-aligned pyramid, '3' for a center aligned pyramid.\n";
		int pyram_choice;
		cin >> pyram_choice;

		cout << "Please type in number of rows you would like your pyramid to have: ";
		int num_rows;
		cin >> num_rows;


		switch (pyram_choice)
		{
		case 1:
			right_pyram(num_rows);
			break;

		case 2:
			left_pyram(num_rows);
			break;

		case 3:
			center_pyram(num_rows);
			break;

		default:
			cout << "That was not a valid choice!\n";

		}
		cout << "Would you like to see another pyramid?\n";
		cout << "Type in \"yes\" or \"no\"" << endl;
		cin >> choice;
		new_line();

	} while ((choice != 'n') && (choice != 'N'));

	cout << "END OF PROGRAM\n";
	
	return 0;
}

void right_pyram(int num_rows)
{
	for (int i = 1; i <= num_rows; i++)
	{
		for (int spaces = i; spaces < num_rows; spaces++)
		{
			cout << " ";
		}

		for (int j = 1; j <= i; j++)
		{
			cout << "*";
		}

		cout << endl;
	}

	return;
}

void left_pyram(int num_rows)
{
	for (int i = 1; i <= num_rows; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			cout << "*";
		}

		cout << endl;
	}

	return;
}

void center_pyram(int n)
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= 2 * n - 1; j++)
		{
			if ( j >= n - (i - 1) && j <= n + (i - 1))
				cout << "*";

			else
				cout << " ";
		}

		cout << endl;
	}

	return;
}

void new_line()
{
	char next;
	do
	{
		cin.get(next);
	} while (next != '\n');
}