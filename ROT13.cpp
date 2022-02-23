#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
	string line;
	fstream source ("source.txt");

	if (source.is_open()) {
		while (getline(source,line)) {
			for (int i = 0; i < line.length(); i++) {
				if ( (65 <= int(line[i]) && 77 >= int(line[i])) || (97 <= int(line[i]) && 109 >= int(line[i])) ) {
					line[i] += 13;
				}
				else if ( (78 <= int(line[i]) && 90 >= int(line[i])) || (110 <= int(line[i]) && 122 >= int(line[i])) ) {
					line[i] -= 13;
				}
			}
			cout << line << endl;
		}
		source.close();
	}
	else { cout << "Failed to open file";}

	return 0;
}