#include <iostream>
using namespace std;

int dp[17];
int schedule[2][16];

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	
	int N;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> schedule[0][i] >> schedule[1][i];
	}

	for (int i = N; i >= 1; i--) {
		int day = schedule[0][i];
		int pay = schedule[1][i];
		
		if (i + day > N + 1) {
			dp[i] = dp[i + 1];
		}
		else {
			dp[i] = max(dp[i + 1], dp[i + day] + pay);
		}
	}

	cout << dp[1];
	
	return 0;
}