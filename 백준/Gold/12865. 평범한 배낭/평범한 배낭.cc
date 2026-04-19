#include <iostream>

using namespace std;

int weight[101];
int value[101];
int dp[101][1000001];
int N;
int K;

int max(int a, int b) {
	if (a >= b) return a;
	return b;
}

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> K;

	for (int i = 1; i <= N; i++) {
		cin >> weight[i] >> value[i];
	}

	for (int i = 1; i <= N; i++) {
		for (int w = 1; w <= K; w++) {
			if (w >= weight[i]) {
				dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - weight[i]] + value[i]);
			}
			else {
				dp[i][w] = dp[i - 1][w];
			}
		}
	}
	cout << dp[N][K];

	return 0;
}