#include <iostream>
#include <string>

using namespace std;

int main() {
	string word;
	int length;
	bool answer = true;
	bool retry = true;
	char option;

	while (retry == true) {
		cout << "Enter word to see if it's a palindrome: ";
		cin >> word; // Get word
		length = word.length(); // Getting length of the word

		int j = length - 1; // Assigning length of word to j

		// Checking if the word is a palidrome

		for (int i = 0; i < length; i++) {
			word[i] = tolower(word[i]);
			if (word[i] != word[j]) {
				answer = false;
				break;
			}
			j--;
		}

		// Outputting answer 

		if (answer == false) {
			cout << "Not a palindrome :(\n";
		}
		else {
			cout << "It is a palindrome!\n";
		}

		// Repeat code

		cout << "Do you want to try another one y/n\n";
		cin >> option;

		if (option == 'n') {
			retry = false;
		}
		else if (option == 'y') {
			retry = true;
		}
		else {
			retry = false;
		}
	}
	return 0;
}