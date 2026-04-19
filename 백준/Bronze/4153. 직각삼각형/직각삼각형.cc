#include <iostream>
using namespace std;

int square(int a) {
	return a * a;
}

int main(void) {

	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int a, b, c;

	while (true) {
		cin >> a >> b >> c;

		if (a == 0 && b == 0 && c == 0) {
			return 0;
		}

		a = square(a);
		b = square(b);
		c = square(c);

		if (a + b == c || a + c == b || b + c == a) {
			cout << "right\n";
		}
		else {
			cout << "wrong\n";
		}
	}
	return 0;
}