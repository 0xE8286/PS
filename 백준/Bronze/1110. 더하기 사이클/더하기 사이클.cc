#include <iostream>

using namespace std;

int main() {
	int start;
	int f[2];
	int r[2];

	cin >> start;

	int n = 0;
	int item = start;
	
	while (true) {
		n++;

		f[0] = item / 10;
		f[1] = item % 10;
		
		r[0] = (f[0] + f[1]) / 10;
		r[1] = (f[0] + f[1]) % 10;

		item = (f[1]*10) + r[1];

		if (item == start)
			break;
	}

	cout << n;

	return 0;
}