#include <iostream>
#include <cmath>
using namespace std;

int dp[50001];

int main() {

	int N;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		dp[i] = dp[i-1] + 1;
	}

	for (int i = 2; i <= sqrt(N); i++) {
		int sq = i * i;
		for (int j = sq; j <= N; j++) {
			dp[j] = min(dp[j - sq] + 1, dp[j]);
		}
	}
	cout << dp[N];

	return 0;
}