#include <iostream>

using namespace std;

int main() {

	int N;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= 2 * N; j++) {
			if (j <= i || j > 2 * N - i) {
				cout << "*";
			}
			else
				cout << " ";
		}
		cout << endl;
	}

	for (int i = N - 1; i > 0; i--) {
		for (int j = 1; j <= 2 * N; j++) {
			if (j <= i || j > 2 * N - i) {
				cout << "*";
			}
			else
				cout << " ";
		}
		cout << endl;
	}


	return 0;
}