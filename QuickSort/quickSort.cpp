#include <iostream>
#include <string>

using namespace std;

void quickSort(string&,int,int);
int partition(string,int,int);
void display(string,int);

int main () {
	string input = "";

	cout << "Enter a string:\n";
	cin >> input;

	quickSort(input, 1, input.size());

	cout << "Sorted string:\n" << input << "\n";

	return 0;
}

void quickSort(string &input, int lo, int hi) {
	int p = 0;
	display("lo", lo);
	display("hi", hi);

	if (lo < hi) {
		display("p", p);
		p = partition(input, lo, hi);
		quickSort(input, lo, p - 1);
		cout << "\n" << "input = " << input << "\n";
		quickSort(input, p + 1, hi);
		cout << "\n" << "input = " << input << "\n";
	}
}

int partition(string input, int lo, int hi) {
	int i = 0;
	char p = ' ';

	p = input[hi];
	i = lo;

	for (int j = lo; j < hi - 1; j++) {
		if (input[j] <= p) {
			swap(input[i], input[j]);
			i++;
		}
	}

	swap(input[i], input[hi]);

	return i;
}

void display(string str, int n) {
	cout << "\n" << str << " = " << n << "\n";
}