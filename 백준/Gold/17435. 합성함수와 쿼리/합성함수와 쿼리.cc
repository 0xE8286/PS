#include<iostream>

#define MAX_K 19

using namespace std;

int m, Q, n, x;
int dp[200001][MAX_K];

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> m;

	for (int i = 1; i <= m; i++) {
		cin >> dp[i][0];
	}

	for (int j = 1; j < MAX_K; j++) {
		for (int i = 1; i <= m; i++) {
			dp[i][j] = dp[dp[i][j - 1]][j - 1];
		}
	}

	cin >> Q;
	for (int i = 0; i < Q; i++) {
		cin >> n >> x;

		for (int k = MAX_K - 1; k >= 0; k--) {
			int now_k = 1 << k; //2의 k 승
			if (n >= now_k) {
				n -= now_k;
				x = dp[x][k];
			}
		}
		cout << x << '\n';
	}

	return 0;
}