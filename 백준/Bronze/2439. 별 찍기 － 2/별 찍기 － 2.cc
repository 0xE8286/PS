#include <iostream>
using namespace std;

int N;

int main() {

	cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i + j > N)
				cout << "*";
			else
				cout << " ";
		}
		cout << endl;
	}

	return 0;
}