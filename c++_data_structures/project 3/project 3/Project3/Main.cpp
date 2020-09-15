// I Zachary Searle have not used any code other than my own (or that in the textbook) for this
//project.I understand that any violation of this disclaimer will result in a 0 for the
//project.


#include<string>
#include<iostream>
#include<fstream>
#include<stack>

using namespace std;
stack<char> operations;
string postFix;
double PostfixEvaluation(string postFix);
string InfixToPostfix(string inFix);



int main() {

	string fileDataName = "C:\\cs2420\\Assignment3\\data.txt";

	ifstream fileData;
	fileData.open(fileDataName, 0);
	if (fileData.good() == false)
	{
		cout << "can't open data file: " << fileDataName << endl;
	}
	while (fileData.eof() == false)
	{
		string fileInput;

		getline(fileData, fileInput);
		if (fileInput == "") {
			continue;
		}
		
		cout << "Infix: " << fileInput << endl;
		postFix = "";
		postFix = InfixToPostfix(fileInput);
		cout << "Postfix " << postFix << endl;
		double answer = PostfixEvaluation(postFix);
		cout << "Answer " << answer << endl;
	}


	getchar();
	return 0;
}

string InfixToPostfix(string inFix) {
	char currentInfo;
	for (unsigned i = 0; i < inFix.length(); i++) {
		currentInfo = inFix.at(i);
		switch (currentInfo) {
			case('('):
				operations.push(currentInfo);
				break;
			case(' '):
				break;
			default:
				postFix += currentInfo;
				postFix += ' ';
				break;
			case('*'):
				//intential fall through
			case('/'):
				while (!operations.empty() && operations.top() != '(' && (operations.top() == '*' || operations.top() == '/')) {
						postFix += operations.top();
						postFix += ' ';
						operations.pop();
				}
				operations.push(currentInfo);
				break;
			case('+'):
				//intential fall through
			case('-'):
				while (!operations.empty() && operations.top() != '(') {
					postFix += operations.top();
					postFix += ' ';
					operations.pop();
				}
				operations.push(currentInfo);
				break;
			case(')'):
				while (!operations.empty() && operations.top() != '(') {
					postFix += operations.top();
					postFix += ' ';
					operations.pop();
				}
				operations.pop();
				break;
		}
	}
	while (!operations.empty()) {
			postFix += operations.top();
			operations.pop();
	}
	return postFix;
}

double PostfixEvaluation(string postFix) {
	stack<double> numbers;

	for (int i = 0; i < postFix.length(); i++) {

		if (postFix.at(i) == '+' || postFix.at(i) == '-' || postFix.at(i) == '*' || postFix.at(i) == '/') {
			double rightNumber = numbers.top();
			numbers.pop();
			double leftNumber = numbers.top();
			numbers.pop();
			double answer = 0.0;
			switch (postFix.at(i)) {
			case '+':
				answer = leftNumber + rightNumber;
				break;
			case '-':
				answer = leftNumber - rightNumber;
				break;
			case '*':
				answer = leftNumber * rightNumber;
				break;
			case '/':
				answer = leftNumber / rightNumber;
				break;
			}
			numbers.push(answer);
		}
		else if (postFix.at(i) >= '0') {
			double number = 0.0;
			number += (postFix.at(i) - 48); // postfix.at(i) returns ascii code
			// subtract 48 to get actual value
			numbers.push(number);
		}
	}
	return numbers.top();
}