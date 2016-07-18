#include <string>

using namespace std;

string quickSort();

int main () {
	string input = "";
	string sorted = "";

	cout << "Enter a string:\n"
	cin >> input;

	sorted = quickSort(input, 1, input.size());

	return 0;
}

string quickSort (string input, int lo, int hi) {
	if (lo < hi) {
		p = partition(A, lo, hi);
		quickSort(A, lo, p - 1);
		quickSort(A, p + 1, hi);
	}
}

string partition (A, lo, hi) {
	int i = lo;

	return i;
}