#include <iostream>
#include <vector>

using namespace std;

int main() {
	int DataSize; // user inputed size
	int data;
	vector<int> container; // vector for all inputed data

	cin >> DataSize;

	for (int i = 0; i < DataSize; i++) { // one line cin seperated by spaces
		cin >> data;
		container.push_back(data);
	}

	bool loop = true;
	while (loop == true) { // loop until no swaps
		bool swaped = false; // reset boolean
		for (int i = 0; i < (DataSize - 1); i++) { // loop for data size: ascending
			if (container[i] > container[i + 1]) { // if number is bigger than the one above, swap
				swap(container[i], container[i + 1]); // swaps the two numbers places
				swaped = true;
			}
		}

		for (int i = (DataSize - 1); i > 0; i--) { // loop for data size: descending
			if (container[i] < container[i - 1]) { // if number is smaller than the oone bellow it, swap
				swap(container[i], container[i - 1]); // swaps the two numbers places
				swaped = true;
			}
		}

		if (swaped == false) {
			loop = false;
		}
	}

	for (int i = 0; i < DataSize; i++) { // cout sorted data set
		cout << container[i] << " ";
	}

	return 0;
}
