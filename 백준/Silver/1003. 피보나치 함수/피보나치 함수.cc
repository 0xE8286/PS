#include <iostream>
using namespace std;

int T, N ;
int dp[41][2];

int main() {
	cin >> T;

	dp[0][0] = 1;
	dp[0][1] = 0;

	dp[1][0] = 0;
	dp[1][1] = 1;
	
	for (int test_case = 1; test_case <= T; test_case++) {
		cin >> N;
		for (int n = 2; n <= N; n++) {
			if (dp[n][0] == 0) {
				dp[n][0] = dp[n - 1][0] + dp[n - 2][0];
				dp[n][1] = dp[n - 1][1] + dp[n - 2][1];
			}
		}
		cout << dp[N][0] << " " << dp[N][1] << endl;
	}
	return 0;
}