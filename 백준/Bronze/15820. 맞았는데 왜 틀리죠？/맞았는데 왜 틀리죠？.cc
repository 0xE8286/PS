#include <iostream>
using namespace std;

int s1, s2;
int ans, man;
bool wa, ww;

int main() {

	cin >> s1 >> s2;

	for (int i = 0; i < s1; i++) {
		cin >> ans >> man;
		if (ans != man) {
			wa = true;
		}
	}


	for (int i = 0; i < s2; i++) {
		cin >> ans >> man;
		if (ans != man) {
			ww = true;
		}
	}

	if (wa) {
		cout << "Wrong Answer\n";
	}
	else if (ww) {
		cout << "Why Wrong!!!\n";
	}
	else {
		cout << "Accepted\n";
	}
	return 0;
}