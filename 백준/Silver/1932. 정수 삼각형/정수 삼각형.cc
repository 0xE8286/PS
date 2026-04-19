#include <iostream>
using namespace std;

int dp[501][501];
int tri[501][501];
int N;

int max(int a, int b) {
	if (a > b) {
		return a;
	}
	return b;
}

int main() {
	cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= i; j++) {
			cin >> tri[i][j];
		}
	}

	dp[1][1] = tri[1][1];

	for (int n = 2; n <= N; n++) {
		for (int i = 1; i <= n; i++) {
			dp[n][i] = max(dp[n - 1][i], dp[n - 1][i - 1]) + tri[n][i];
		}
	}

	int ans = 0;

	for (int i = 1; i <= N; i++) {
		if (dp[N][i] > ans) {
			ans = dp[N][i];
		}
	}

	cout << ans;

	return 0;
}