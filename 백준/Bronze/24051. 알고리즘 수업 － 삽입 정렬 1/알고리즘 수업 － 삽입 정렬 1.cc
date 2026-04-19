#include <iostream>
using namespace std;

int N, K;
int A[10000];

int main() {

	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	int cnt = 0;

	for (int i = 1; i < N; i++) {
		int loc = i - 1;
		int newItem = A[i];

		while (0 <= loc && newItem < A[loc]) {
			if (++cnt == K) {
				cout << A[loc];
				return 0;
			}
			A[loc + 1] = A[loc];
			loc--;
		}
		if ((loc + 1) != i) {
			if (++cnt == K) {
				cout << newItem;
				return 0;
			}
			A[loc + 1] = newItem;
		}
	}

	cout << -1;

	return 0;
}