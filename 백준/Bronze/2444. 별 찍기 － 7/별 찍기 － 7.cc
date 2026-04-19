#include <iostream>

using namespace std;

int N;

int main() {
	cin >> N;

	int range = 2 * N - 1;
	int handle_star = 0;

	for (int i = 1; i <= range; i++) {
		for (int j = 1; j <= N + handle_star; j++) {
			if (j >= N - handle_star && j <= N + handle_star)
				cout << "*";
			else
				cout << " ";
		}
		if (i < N)
			handle_star++;
		else
			handle_star--;
		cout << endl;
	}
	return 0;
}