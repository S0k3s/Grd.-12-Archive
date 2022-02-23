#include <iostream>

using namespace std;

int main() {
	// Initializing variables
	int current = 3; // Starting at 3
	int primeCounter = 1; 

	cout << "2, "; // Output first prime number

	while (primeCounter < 1000) { // Loop up to 1000th prime 
		for (int i = 2; i <= current; i++) { // Loop through middle numbers
			if (i == current) { // If it made it through all numbers
				cout << current << ", "; // Output current prime
				primeCounter++; // Add prime
			}
			else if (current % i == 0) { // Not prime
				break;
			}
		}
		current++; // Next numnber
	}
	return 0;
}