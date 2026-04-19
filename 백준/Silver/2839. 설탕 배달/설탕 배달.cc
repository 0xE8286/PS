#include <iostream>

using namespace std;

int dp[5001];
int N;

int small(int a, int b) {
	if (a < b)
		return a;
	return b;
}

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	dp[3] = 1;
	dp[5] = 1;

	for (int i = 6; i <= N; i++) {
		if (dp[i - 3] == 0 && dp[i - 5] == 0)
			dp[i] = 0;
		else if (dp[i - 3] == 0)
			dp[i] = dp[i - 5] + 1;
		else if (dp[i - 5] == 0)
			dp[i] = dp[i - 3] + 1;
		else
			dp[i] = small(dp[i - 3] + 1, dp[i - 5] + 1);
	}
	if (dp[N] == 0)
		cout << -1;
	else
		cout << dp[N];

	return 0;
}