#include <iostream>
using namespace std;
int main() {
	int T;
	cin >> T;
	string pw;
	for (int i = 0; i < T; i++) {
		cin >> pw;
		if (pw.size() >= 6 && pw.size() <= 9) {
			cout << "yes\n";
		}
		else {
			cout << "no\n";
		}
	}
	return 0;
}