/********************************************************************************************
**	Project: Dynamic Sequence
**  Programmer: Dana Doggett
**  Course:		cs2420
**	Section:	001
**	Assignment: 1
**	Data:		August 22, 2017
**
**	I certify that I wrote all code in this project except that which was
**	provided by the instructor.
**
***********************************************************************************************/

#include <iostream>
#include <fstream>

#include "CheckBook.h"

using namespace std;

// the format for the data file is:
// <cmd> data
//
// the recognized commands and their corresponding data are:
// b xxxx.xx	- sets the "Origianl Balance" to the number xxxx.xx
// e xxxx.xx	- expected "New Balance" of xxxx.xx
// d xxxx.xx	- deposits $xxxx.xx into the checking account
// w xxx yyyy.yy - writes a check of number xxx with the amount of yyyy.yy
// c xxx		- check xxx has been cached

int main()
{
	// specify the input data file
	char dataFileName[] = "C:\\Users\\Owner\\.cs2420 folder\\project 1\\Project1\\Project1\\data.txt";

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
	// so create the Checkbook
	CheckBook checkbook;

	// read and use the data
	while (fileData.eof() == false)
	{
		char command[256];
		fileData >> command;

		// attempt to perform the specified command
		switch (command[0])
		{
		case 'b':	// sets the balance of the account
		{
			double newAccountBalance = 0.0;
			fileData >> newAccountBalance;
			checkbook.SetNewAccountBalance(newAccountBalance);
			break;
		}

		case 'n':	// expected "new" balance
		{
			double newExpectedBalance = 0.0;
			fileData >> newExpectedBalance;
			checkbook.SetExpectedBalance(newExpectedBalance);
			break;
		}

		case 'd':	// deposits funds into the account
		{
			double deposit;
			fileData >> deposit;
			checkbook.Deposit(deposit);
			break;
		}

		case 'w':	// write a check from your checkbook
		{
			unsigned int checkNumber;
			double amount;
			fileData >> checkNumber;
			fileData >> amount;
			checkbook.WriteCheck(checkNumber, amount);
			break;
		}

		case 'c':	// the specified check has been cashed
		{
			unsigned int checkNumber;

			fileData >> checkNumber;
			checkbook.ClearCheck(checkNumber);
			break;
		}

		default:
			break;
		}
	}

	fileData.close();

	// at this point, all data has been processes, so output the required data
	checkbook.DisplayResults();

	// wait for the user to press enter to quit
	cout << endl << "Press the [Enter] key to quit...";
	getchar();


	return 0;
}

