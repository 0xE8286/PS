#include <iostream>
using namespace std;

int A, B, C;

int main() {

	cin >> A >> B >> C;

	if ((A + B) >= (C * 2)) {
		cout << (A + B) - (C * 2);
	}
	else {
		cout << (A + B);
	}

	return 0;
}