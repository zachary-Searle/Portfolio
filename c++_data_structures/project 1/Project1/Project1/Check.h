#ifndef __Check__
#define __Check__

class Check
{
public:
	Check() = default;
	Check(int number, double amount);

	unsigned int checkNumber;
	double amount;
	bool cleared;
};

#endif

