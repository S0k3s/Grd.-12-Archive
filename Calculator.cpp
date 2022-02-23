#include <iostream>

using namespace std;

int main() {
	// Initializing variables
	int operand1;
	int operand2;
	char symbol;
	double answer;
	char newCalc;
	bool repeat = true;
	

	// Etrance greeting
	cout << "Welcome to the calculator.\n" << "Hope you have a good time!\n\n";
	
	while (repeat == true) {
		bool valid = true;
		// First operand input
		cout << "Enter the first operand: ";
		cin >> operand1;
		// Operator input
		cout << "Available operators are: +, -, *, /, %" << "\nEnter your operator: ";
		cin >> symbol;
		// Second operand input
		cout << "Enter second operand: ";
		cin >> operand2;

		if (symbol == '+') { // Addition calculation 
			answer = operand1 + operand2;
		}
		else if (symbol == '-') { // Subtraction calculation
			answer = operand1 - operand2;
		}
		else if (symbol == '*') { // Multiplication calculation
			answer = operand1 * operand2;
		}
		else if (symbol == '/') { // Division calculation
			answer = operand1 / operand2;
		}
		else if (symbol == '%') { // Modulos calculation
			answer = operand1 % operand2;
		}
		else {
			cout << "Not valid operator\n";
			valid = false;
		}

		// Making another calculation

		if (valid) { // must be valid operator
			cout << "Answer: " << answer << "\nDo you want to make another calculation: y/n\n";
			cin >> newCalc;
			if (newCalc == 'n') {
				repeat = false;
			}
			else if (newCalc == 'y') {
				repeat = true;
			}
			else {
				repeat = false;
			}
		}
		cout << "\n\n\n";
	}
	return 0;
}