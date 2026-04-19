#include <iostream>

#define MAX_N 100

using namespace std;

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;

	int card[MAX_N];
	int min_diff = M;

	for (int i = 0; i < N; i++) {
		cin >> card[i];
	}

	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			for (int k = j + 1; k < N; k++) {
				int sum = card[i] + card[j] + card[k];
				int diff = M - sum;
				if (sum <= M && (M - sum) < min_diff) {
					min_diff = diff;
				}
			}
		}
	}
	cout << M - min_diff;

	return 0;
}