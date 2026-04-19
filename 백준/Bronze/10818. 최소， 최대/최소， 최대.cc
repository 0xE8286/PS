#include <iostream>

using namespace std;

int main() {

	int n; 
	cin >> n;

	int min = 1000000;
	int max = -1000000;

	int num;

	for (int i = 0; i < n; i++) {
		cin >> num;
		if (num < min) min = num;
		if (num > max) max = num;
	}

	cout << min << " " << max << "\n";

	return 0;
}