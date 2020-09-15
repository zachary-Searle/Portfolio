/********************************************************************************************
**	Project: Recursive List
**  Programmer: Zachary Searle
**  Course:		cs2420
**	Section:	001
**	Assignment: 1
**	Data:		August 28, 2017
**  UVID:       10812599
**
**	I certify that I, Zachary Searle, wrote all code in this project except that which was
**	provided by the instructor.
**
***********************************************************************************************/

#include <iostream>
#include <fstream>

#include "LinkedList.h"

using namespace std;

// the format for the data file is:
// <Course Number> , <Name> , <Credits>, <Grade>
//
// for example, the following would add four courses to the
// Linked List:
//
//	1400,Introduction to Programming,4,3.6
//	1410,C++ Programming,4,2.6
//	2420,Introduction to Data Structures,4,3.2
//	2810,Computer Architecture,3,3.8

int main()
{
	// specify the input data file (MUST BE HERE. Don't change this location or the grader will have problems!!!!)
	// orginal filepath char dataFileName[] = "C:\\CS2420\\Assignment2\\data.txt";
	char dataFileName[] = "C:\\Users\\Owner\\.cs2420 folder\\project 2\\Project2\\Project2\\data.txt"
		// I've got the file name, now try to open the file for reading
	ifstream fileData;
	fileData.open(dataFileName, 0);
	if (fileData.good() == false)
	{
		cout << "ERROR: can't open data file: " << dataFileName << endl;

		// wait for the user to press enter to quit
		cout << endl << "Press the [Enter] key to quit...";
		getchar();
		return -1;
	}

	// I've got the data file open.
	// read and use the data
	{
		LinkedList courses;
		unsigned int courseNumber;
		std::string courseName;
		unsigned int credits;
		double grade;
//
//		/*********************************
//		Psuedo Code (students must implement this)
//		(hint: this is a comma-separated-file)
//		1. while NOT end-of-file
		while()
//		2.		read in from data file the course number
//		3.		read in from data file the course name
//		4.		read in from data file the course cedit hours
//		5.		read in from data file the course grade
//		6.		with this data, create a new Course
//		7.		insert new Course into the LinkedList
//		*********************************/
//
		fileData.close();

		// display the ordered list of courses
		courses.PrintList();

		double gpa = courses.CalculateGPA();
		cout.precision(4);
		cout << "Cumulative GPA: " << gpa << endl;

		// wait for the user to press enter to quit
		cout << endl << "Press the [Enter] key to quit...";
		getchar();
	}
	return 0;
}
