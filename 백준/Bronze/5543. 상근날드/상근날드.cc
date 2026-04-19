#include <iostream>

using namespace std;

int main() {
	int burger = 2001;
	int coke = 2001;
	int input;

	for (int i = 0; i < 3; i++) {
		cin >> input;
		if (input < burger) burger = input;
	}

	for (int i = 0; i < 2; i++) {
		cin >> input;
		if (input < coke) coke = input;
	}
	cout << burger + coke - 50;

	return 0;
}