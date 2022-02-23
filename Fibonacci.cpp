#include <iostream>
using namespace std;

int main() {
	// Initializing variables
	int input;
	int output = 0;
	int digit1 = 0;
	int digit2 = 1;

	cout << "Welcome to the fibonacci sequence generator!\n" << "Enter in what value you want to generate up to: "; // Intro text
	cin >> input; // Getting the input

	// Checking to see if the input is below 0 or 1 then outputing the first 2 values acordingly
	if (input >= 0) { cout << digit1 << ", "; }
	if (input >= 1) { cout << digit2 << ", "; }
 
	while (output <= input) {
		output = digit1 + digit2; // Adding the last two values
		digit1 = digit2; // Assigning the new 1st digit
		digit2 = output; // Assigning the new 2nd digit
		if (output <= input) { // Checking to see if the newest output is above the input
			cout << output << ", ";
		}
	}
	return 0;
}