#include <iostream>

using namespace std;

int main() {

	int a, b, c, prize;

	cin >> a >> b >> c;

	if (a == b && b == c) {
		prize = 10000 + (a * 1000);
	}
	else if (a == b || b == c) {
		prize = 1000 + (b * 100);
	}
	else if (c == a) {
		prize = 1000 + (a * 100);
	}
	else {
		if (a > b) {
			if (a > c) {
				prize = a * 100;
			}
			else {
				prize = c * 100;
			}
		}
		else {
			if (b > c) {
				prize = b * 100;
			}
			else {
				prize = c * 100;
			}
		}
	}

	cout << prize;

	return 0;
}