#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>
#include "Header.h" // Holding clear function
#include <array>

using namespace std;

string NewGame() {
	string file; // input for file selection
	string line;
	fstream File_Names("File_Names.txt"); // opening file names file

	bool check = true;

	do {
		check = true;
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

			cout << "Welcome to Mining Mania!\n\n" << "This game requires no skill, just patience and CPU power.\n" << "The aim of the game is to mine the most gold as you possibly can.\n";
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
	array<int, 7>info;
	string line;

	fstream File(OpenFile);

	for (int i = 0; i <= 7; i++) {
		getline(File, line);
		if (i == 1) { info[i - 1] = stoi(line); }
		if (i == 2) { info[i - 1] = stoi(line); }
		if (i == 3) { info[i - 1] = stoi(line); }
		if (i == 4) { info[i - 1] = stoi(line); }
		if (i == 5) { info[i - 1] = stoi(line); }
		if (i == 6) { info[i - 1] = stoi(line); }
		if (i == 7) { info[i - 1] = stoi(line); }
	}
	File.close();

	cout << "Current $: " << info[0] << endl;
	cout << "Picklvl: " << info[1] << endl;
	cout << "Miners: " << info[2] << endl;
	if (info[1] < 10) {
		cout << "Trucks: " << "Locked until Picklvl 10\n";
	}
	else {
		cout << "Trucks: " << info[3] << endl;
	}
	if (info[1] < 50) {
		cout << "Dinamite: " << "Locked until Picklvl 50\n";
	}
	else {
		cout << "Dinamite: " << info[4] << endl;
	}
	if (info[1] < 100) {
		cout << "Nukes: " << "Locked until Picklvl 100\n";
	}
	else {
		cout << "Nukes: " << info[5] << endl;
	}
	if (info[1] < 1000) {
		cout << "Full Power: " << "Locked until Picklvl 1000\n";
	}
	else {
		cout << "Full Power: " << info[6] << endl;
	}
}
void Write(string OpenFile, array<int,7>info) {
	string line;

	fstream File(OpenFile);


}
void Shop(string OpenFile) {
	array<int, 7>info; // {Current$, Picklvl, Miners, Trucks, Dinamite, Nukes, FullPower}
	string input;
	string upgrade;
	int amount;
	string line;

	fstream File(OpenFile);

	for (int i = 0; i <= 7; i++) {
		getline(File, line);
		if (i == 1) { info[i-1] = stoi(line); } // Current$
		if (i == 2) { info[i-1] = stoi(line); } // Picklvl
		if (i == 3) { info[i-1] = stoi(line); } // Miners
		if (i == 4) { info[i-1] = stoi(line); } // Trucks
		if (i == 5) { info[i-1] = stoi(line); } // Dinamite
		if (i == 6) { info[i-1] = stoi(line); } // Nukes
		if (i == 7) { info[i-1] = stoi(line); } // FullPower
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

		if (upgrade == "Picklvl") { 
			info[1] += amount; 
		}
		if (upgrade == "Miners") { 
			info[2] += amount; 
		}
		if (upgrade == "Trucks") { 
			info[3] += amount; 
		}
		if (upgrade == "Dinamite") { 
			info[4] += amount; 
		}
		if (upgrade == "Nukes") { 
			info[5] += amount; 
		}
		if (upgrade == "FullPower") {
			info[6] += amount; 
		}
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

	Shop(OpenFile);
	
	return 0;
}
