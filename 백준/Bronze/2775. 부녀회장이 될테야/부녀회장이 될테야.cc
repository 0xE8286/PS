#include <iostream>

using namespace std;

int T, K, N;
int table[15][15];

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> T;
	for (int tc = 0; tc < T; tc++) {
		cin >> K >> N;

		for (int i = 0; i <= 14; i++) {
			table[0][i] = i;
		}
		for (int i = 1; i <= 14; i++) {
			table[i][1] = 1;
		}

		for (int i = 1; i <= K; i++) {
			for (int j = 2; j <= N; j++) {
				table[i][j] = table[i][j - 1] + table[i - 1][j];
			}
		}

		cout << table[K][N] << "\n";
	}

	return 0;
}