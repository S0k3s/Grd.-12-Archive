#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>
#include "Header.h" // Holding clear function

using namespace std;

int main() {
	string input; // initializing input
	string line; // Line is to find selected lines from files

	cout << "New Game\n" << "Load Game\n"; // starting main menu screen
	getline(cin, input); // either New Game or Load Game

	for (;;) {

		// If New Game was selected

		if (input == "New Game") {
			string file; // input for file selection
			fstream File_Names("File_Names.txt"); // opening file names file

			for (;;) {
				cout << "What should the file be saved as: ";
				cin >> file; // getting the name of the new file

				bool check = true;

				while (getline(File_Names, line)) { // loop over each file name
					if (line == file) { // check if the name already exists
						check = false;
					}
				}
				File_Names.close();

				if (check == true) {
					fstream File_Names("File_Names.txt", ios::out | ios::app); // opening file names file
					File_Names << endl << file; // writing the name of the new file in the file names file for future use
					File_Names.close();
					ofstream New_File(file); // creating file with inputed name
					New_File << file;

					cout << "Welcome to Mining Mania!\n\n" << "This game requires no skill, just patience and GPU power.\n" << "The aim of the game is to mine the most gold as you possibly can.\n";
					cout << " Have fun and just let it run.";
					break;
				}
				else { cout << "File already exists\n"; }
			}
		}

		// If Load Game was selected

		else if (input == "Load Game") {
			for (;;) {
				fstream File_Names("File_Names.txt"); // oppening the file Names file
				string file;
				bool open = true;

				if (File_Names.is_open()) { // Checking if the file is open
					while (getline(File_Names, line)) { // looping over the lines
						cout << line << endl; // output current line
					}
				}
				else { cout << "Could not access saves\n"; } // if the file couldn't be found

				cout << endl << "What file would you like to open?: ";
				cin >> file;

				File_Names.clear();
				File_Names.seekg(0);
				while (getline(File_Names, line)) { // looping over the lines
					cout << "\n\n" << line;
					if (file == line) {
						break;
					}
					else {
						open = false;
					}
				}
				File_Names.close();
				if (open == true){
					break;
				}
			}
			break;
		}
	}

	// main upgrading screen

	int Current$ = 10;
	int Miners = 0;
	int Picklvl = 0;
	int Trucks = 0;
	int Dinamite = 0;
	int Nukes = 0;
	int FullPower = 0;

	cout << "Current $: " << Current$ << endl;
	cout << "Pick lvl: " << Picklvl << endl;
	cout << "Miners: " << Miners << endl;
	if (Trucks == 0) {
		cout << "Trucks: " << "Locked\n";
	}
	else {
		cout << "Trucks: " << Trucks << endl;
	}
	if (Dinamite == 0) {
		cout << "Dinamite: " << "Locked\n";
	}
	else {
		cout << "Dinamite: " << Dinamite << endl;
	}
	if (Nukes == 0) {
		cout << "Nukes: " << "Nukes \n";
	}
	else {
		cout << "Nukes: " << Nukes << endl;
	}
	if (FullPower == 0) {
		cout << "Full Power: " << "Locked\n";
	}
	else {
		cout << "Full Power: " << FullPower << endl;
	}

	return 0;
}
