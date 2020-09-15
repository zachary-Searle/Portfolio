#include "CheckBook.h"
#include "DynamicArray.h"
#include<iostream>
using namespace std;




CheckBook::CheckBook(){
	accountBalance = 0;
	expectedBalance = 0;
	totalOfDeposits = 0;
	numChecksCleared = 0;
}


CheckBook::~CheckBook(){
}

void CheckBook::SetNewAccountBalance(double newBalance){
	accountBalance = newBalance;
}

void CheckBook::SetExpectedBalance(double newExpectedBalance){
	expectedBalance = newExpectedBalance;
}

void CheckBook::Deposit(double amount){
	accountBalance += amount;
	totalOfDeposits += amount;
}

void CheckBook::WriteCheck(int checkNumber, double amount){
	checks.push_back(Check(checkNumber, amount));
}

void CheckBook::ClearCheck(int checkNumber){
	for (int i = 0; i < checks.size(); i++) {
		if (checks.at(i).checkNumber == checkNumber) {
			numChecksCleared++;
			accountBalance -= checks.at(i).amount;
			checks.at(i).cleared = true;
		}
	}
}

void CheckBook::DisplayResults(){
	cout << "total checks cashed: " << numChecksCleared << endl;
	cout << "total deposits: $" << totalOfDeposits << endl;
	cout << "Actual balance is $" << accountBalance << endl;
	cout << "Difference between actual and expected balance is: $" << expectedBalance - accountBalance << endl;
	cout << "List of cashed checks: " << endl;
	for (int i = 0; i < checks.size(); i++) {
		if (checks.at(i).cleared == true) {
			cout << "#" << checks.at(i).checkNumber << " for $" << checks.at(i).amount << endl;
		}	
	}
	cout << "List of outstanding checks: " << endl;
	for (int i = 0; i < checks.size(); i++) {
		if (checks.at(i).cleared == false) {
			cout << "#" << checks.at(i).checkNumber << " for $" << checks.at(i).amount << endl;
		}
	}
}
