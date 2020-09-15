#ifndef __CheckBook__
#define __CheckBook__

#include "Check.h"
#include "DynamicArray.h"

class CheckBook
{
public:
	CheckBook();
	~CheckBook();

	void SetNewAccountBalance(double newBalance);
	void SetExpectedBalance(double newExpectedBalance);
	void Deposit(double amount);
	void WriteCheck(int checkNumber, double amount);
	void ClearCheck(int checkNumber);
	void DisplayResults();

private:
	double accountBalance;
	double expectedBalance;
	double totalOfDeposits;
	int numChecksCleared;

	DynamicArray checks;
};

#endif

