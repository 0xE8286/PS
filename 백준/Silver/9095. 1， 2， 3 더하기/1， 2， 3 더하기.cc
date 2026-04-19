#include <iostream>
using namespace std;

int T, N;
int dp[11];

int main() {

	cin >> T;
	for (int tc = 0; tc < T; tc++) {
		cin >> N;
		
		dp[1] = 1;
		dp[2] = 2;
		dp[3] = 4;

		for (int i = 4; i <= N; i++) {
			dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
		}
		cout << dp[N] << '\n';
	}
	return 0;
}