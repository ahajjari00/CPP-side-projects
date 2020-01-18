// twoDimGrading.cpp

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

const int NUM_STUD = 4;
const int NUM_QUIZZES = 3;

void get_scores(int quiz_scores[][NUM_QUIZZES], int NUM_STUD);

void student_quiz_avg( int quiz_scores[][NUM_QUIZZES], double individ_data[]);

void class_quiz_avg(const int quiz_scores[][NUM_QUIZZES], double class_avg_score[]);

void output_grades(const int quiz_scores[][NUM_QUIZZES], const double class_avgs[], const double individ_avgs[], ofstream& output_stream);

int main()
{
	int quiz_data[NUM_STUD][NUM_QUIZZES];
	get_scores(quiz_data, NUM_STUD);

	double stud_score_data[NUM_STUD]; // should return avg scores across all quizzes for each student. HAD WRONG CONSTANT IN PARAMETER ORIGINALLY!
	student_quiz_avg(quiz_data, stud_score_data);

	double class_score_data[NUM_QUIZZES];
	class_quiz_avg(quiz_data, class_score_data);

	ofstream outputFile;
	outputFile.open("outputFile.txt");
	output_grades(quiz_data, class_score_data, stud_score_data, outputFile);
	outputFile.close();


}

void get_scores(int quiz_scores[][NUM_QUIZZES], int NUM_STUD) // must pass 2nd param. as compiler does not look at first dimension's value
{
	for (int student = 0; student < NUM_STUD; student++)
	{
		for (int quiz_grade = 0; quiz_grade < NUM_QUIZZES; quiz_grade++)
		{
			cout << "Please enter student number " << student + 1 << "'s " << quiz_grade + 1 << " st/nd quiz grade: ";
			cin >> quiz_scores[student][quiz_grade];
		}

		cout << endl << endl << endl;
	}
}

void student_quiz_avg( int quiz_scores[][NUM_QUIZZES], double individ_score_data[])
{
	double sum_of_scores;

	for (int student_num = 0; student_num < NUM_STUD; student_num++)
	{
		sum_of_scores = 0;

		for (int quiz_num = 0; quiz_num < NUM_QUIZZES; quiz_num++)
		{
			sum_of_scores += quiz_scores[student_num][quiz_num];
		}

		individ_score_data[student_num] = sum_of_scores / NUM_QUIZZES;
	}
}

void class_quiz_avg(const int quiz_scores[][NUM_QUIZZES], double class_avg_score[])
{
	double total_quiz_score = 0;

	for (int quiz_num = 0; quiz_num < NUM_QUIZZES; quiz_num++)
	{
		total_quiz_score = 0;

		for (int student_num = 0; student_num < NUM_STUD; student_num++)
		{
			total_quiz_score += quiz_scores[student_num][quiz_num];
		}

		class_avg_score[quiz_num] = total_quiz_score / NUM_STUD;
	}
}

void output_grades(const int quiz_scores[][NUM_QUIZZES], const double class_avgs[], const double individ_avgs[], ofstream& output_stream)
{
	output_stream.setf(ios::fixed);
	output_stream.setf(ios::showpoint);
	output_stream.precision(1);

	output_stream << setw(10) << "Student" << setw(5) << "Avg" << setw(13) << "Quizzes" << endl;

	for (int student_num = 0; student_num < NUM_STUD; student_num++)
	{
		output_stream << setw(10) << student_num + 1 << setw(5) << individ_avgs[student_num];

		for (int quiz_grade = 0; quiz_grade < NUM_QUIZZES; quiz_grade++)
		{
			output_stream << setw(5) << quiz_scores[student_num][quiz_grade];
		}

		output_stream << endl;
	}
	output_stream << setw(10) << "Quiz averages = ";

	for (int quiz_avgs = 0; quiz_avgs < NUM_QUIZZES; quiz_avgs++)
	{
		output_stream << setw(5) << class_avgs[quiz_avgs];
	}


}