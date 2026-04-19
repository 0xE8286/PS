#include <iostream>

using namespace std;

int wallet[21];
int ans[10001];

void clear(int M) {
	for (int i = 0; i <= M; i++) {
		ans[i] = 0;
	}
}

int main() {
	int T;
	cin >> T;
	for (int tc = 0; tc < T; tc++) {
		int N, M;
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> wallet[i];
		}
		cin >> M;

		ans[0] = 1;
		
		for (int i = 0; i < N; i++) {
			int coin = wallet[i];
			for (int j = coin; j <= M; j++) {
				ans[j] = ans[j - coin] + ans[j];
			}
		}
		cout << ans[M] << '\n';
		clear(M);
	}
	return 0;
}