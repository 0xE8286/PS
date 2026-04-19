#include <iostream>
using namespace std;

int N, M;
int mem[101];
int cost[101];
int dp[101][10012];
int min_cost = 10001;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> mem[i];
	}
	for (int i = 1; i <= N; i++) {
		cin >> cost[i];
	}
	for (int i = 1; i <= N; i++) {
		for (int c = 0; c <= 10000; c++) {

			if (cost[i] > c) {
				dp[i][c] = dp[i - 1][c];
			}
			else {
				dp[i][c] = max(
					dp[i - 1][c],
					dp[i - 1][c - cost[i]] + mem[i]
				);
			}
			if (dp[i][c] >= M) {
				min_cost = min(min_cost, c);
			}
		}
	}
	cout << min_cost;

	return 0;
}