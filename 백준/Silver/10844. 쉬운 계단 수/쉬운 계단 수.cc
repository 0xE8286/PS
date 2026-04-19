#include<iostream>
#define MOD 1000000000
using namespace std;

int N;
long long dp[101][10];
long long ans;

int main() {

	cin >> N;

	for (int i = 1; i <= 9; i++) {
		dp[1][i]++;
	}
	
	for (int n = 2; n <= N; n++) {
		for (int i = 0; i <= 9; i++) {
			if (i == 0) {
				dp[n][i] += dp[n - 1][i + 1];
			}
			else if (i == 9) {
				dp[n][i] += dp[n - 1][i - 1];
			}
			else {
				//dp[n][i] += dp[n - 1][i + 1];
				//dp[n][i] += dp[n - 1][i - 1];
				dp[n][i] = (dp[n - 1][i + 1] + dp[n - 1][i - 1]) % MOD;
			}
			
		}
	}

	for (int i = 0; i <= 9; i++) {
		ans += dp[N][i];
	}

	cout << ans % MOD;

	return 0;
}