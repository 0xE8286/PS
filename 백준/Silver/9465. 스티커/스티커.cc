#include <iostream>
using namespace std;

int T, N;
int sticker[100001][2];
int dp[100001][3];

void clear() {
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < 3; j++) {
			dp[i][j] = 0;
		}
	}
}

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		cin >> N;
		
		for (int i = 1; i <= N; i++) {
			cin >> sticker[i][0];
		}
		for (int i = 1; i <= N; i++) {
			cin >> sticker[i][1];
		}

		dp[1][1] = sticker[1][0];
		dp[1][2] = sticker[1][1];

		for (int i = 2; i <= N; i++) {
			dp[i][0] = max(dp[i - 1][0], max(dp[i - 1][1], dp[i - 1][2]));
			dp[i][1] = max(dp[i - 1][2], dp[i - 1][0]) + sticker[i][0];
			dp[i][2] = max(dp[i - 1][1], dp[i - 1][0]) + sticker[i][1];
		}
		cout << max(max(dp[N][0], dp[N][1]), dp[N][2]) <<'\n';
		clear();
	}

	return 0;
}