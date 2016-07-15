/*	Merge Sort
	Nathan Cobb
	Sorts input using merge sort.
	TODO: Implement own list function
*/

#include <iostream>
#include <string>

void merge (string);

int main () {
	string input;

	cout << "Enter a string:\n";
	cin >> input;

	merge(input);

	cout << "\nYour string is:\n";

	return 0;
}

string merge (string input) {
	string left;
	string right;

	//Base Case
	if (input.size() <= 1) {
		return input;
	}

	for (int i = 0; i < input.size() - 1; i++) {
		if (i % 2 == 1) {
			left += input[i];
		}
		else {
			right += input[i];
		}
	}

	left = merge(left);
	right = merge(right);

	return mergeSort(left, right);
}

string mergeSort (string left, string right) {
	string result;

	if (!left.empty() && !right.empty()) {
		if (left[0] < right[0]) {
			result += left[0];
			left.erase(0,1);
		}
		else {
			result += right[0];
			right.erase(0,1);
		}
	}

	if (!left.empty()) {
		result += left[0];
		left.erase(0,1);
	}

	if (!right.empty()) {
		result += right[0];
		right.erase(0,1);
	}

	return result;
}

