#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>
#include "Header.h" // Holding clear function

using namespace std;

string NewGame() {
	string file; // input for file selection
	string line;
	fstream File_Names("File_Names.txt"); // opening file names file

	bool check = true;

	do {
		cout << "What should the file be saved as: ";
		cin >> file; // getting the name of the new file

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

			/* file layout
				file name
				Current$
				Picklvl
				Miners
				Trucks
				Dinamite
				Nukes
				FullPower
			*/

			ofstream New_File(file); // creating file with inputed name
			New_File << file << endl << "0\n1\n0\n0\n0\n0\n0";

			cout << "Welcome to Mining Mania!\n\n" << "This game requires no skill, just patience and GPU power.\n" << "The aim of the game is to mine the most gold as you possibly can.\n";
			cout << "Have fun and just let it run.";
		}
		else { cout << "File already exists\n"; }
	} while (check == false);
	return file;
}
string LoadGame() {
	string file;
	string line;
	bool check = true;
	
	do {
		fstream File_Names("File_Names.txt"); // oppening the file Names file

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
			if (file == line) {
				check = true;
				break;
			}
			else {
				check = false;
			}
		}
		File_Names.close();
	} while (check == false);
		return file;
}
void Print(string OpenFile) {
	int Current$ = 0;
	int Picklvl = 0;
	int Miners = 0;
	int Trucks = 0;
	int Dinamite = 0;
	int Nukes = 0;
	int FullPower = 0;
	string line;

	fstream File(OpenFile);

	for (int i = 0; i <= 7; i++) {
		getline(File, line);
		if (i == 1) { Current$ = stoi(line); }
		if (i == 3) { Picklvl = stoi(line); }
		if (i == 2) { Miners = stoi(line); }
		if (i == 4) { Trucks = stoi(line); }
		if (i == 5) { Dinamite = stoi(line); }
		if (i == 6) { Nukes = stoi(line); }
		if (i == 7) { FullPower = stoi(line); }
	}
	File.close();

	cout << "Current $: " << Current$ << endl;
	cout << "Picklvl: " << Picklvl << endl;
	cout << "Miners: " << Miners << endl;
	if (Picklvl < 10) {
		cout << "Trucks: " << "Locked until Picklvl 10\n";
	}
	else {
		cout << "Trucks: " << Trucks << endl;
	}
	if (Picklvl < 50) {
		cout << "Dinamite: " << "Locked until Picklvl 50\n";
	}
	else {
		cout << "Dinamite: " << Dinamite << endl;
	}
	if (Nukes < 100) {
		cout << "Nukes: " << "Locked until Picklvl 100\n";
	}
	else {
		cout << "Nukes: " << Nukes << endl;
	}
	if (FullPower == 1000) {
		cout << "Full Power: " << "Locked until Picklvl 1000\n";
	}
	else {
		cout << "Full Power: " << FullPower << endl;
	}
}
void Write(string OpenFile) {

}
void Shop(string OpenFile) {
	int Current$ = 0;
	int Picklvl = 0;
	int Miners = 0;
	int Trucks = 0;
	int Dinamite = 0;
	int Nukes = 0;
	int FullPower = 0;
	string input;
	string upgrade;
	string amount;
	string line;

	fstream File(OpenFile);

	for (int i = 0; i <= 7; i++) {
		getline(File, line);
		if (i == 1) { Current$ = stoi(line); }
		if (i == 3) { Picklvl = stoi(line); }
		if (i == 2) { Miners = stoi(line); }
		if (i == 4) { Trucks = stoi(line); }
		if (i == 5) { Dinamite = stoi(line); }
		if (i == 6) { Nukes = stoi(line); }
		if (i == 7) { FullPower = stoi(line); }
	}
	File.close();

	Print(OpenFile);

	cout << "Would you like to UPGRADE or go MINE? ";
	cin >> input;

	if (input == "UPGRADE") {
		Print(OpenFile);

		cout << "What would you like to upgrade? ";
		cin >> upgrade;
		cout << "How much do you want to upgrade by? ";
		cin >> amount;

		if (upgrade == "Picklvl") {}
		if (upgrade == "Miners") {}
		if (upgrade == "Trucks") {}
		if (upgrade == "Dinamite") {}
		if (upgrade == "Nukes") {}
		if (upgrade == "FullPower") {}
	}
	else if (input == "MINE") {

	}
}

int main() {
	string input;
	string OpenFile;
	bool check = false;

	do {
		cout << "New Game\n" << "Load Game\n"; // starting main menu screen
		getline(cin, input); // either New Game or Load Game

		// If New Game was selected
		if (input == "New Game") {
			OpenFile = NewGame();
			check = true;
		}
		// If Load Game was selected
		else if (input == "Load Game") {
			OpenFile = LoadGame();
			check = true;
		}
	} while (check == false);

	// Load current stats
	Shop(OpenFile);
	
	return 0;
}
