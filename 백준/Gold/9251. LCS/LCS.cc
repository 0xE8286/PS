#include <iostream>

using namespace std;

char a[1001];
char b[1001];
int dp[1001][1001];

int max(int a, int b) {
	if (a >= b) return a;
	return b;
}

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> a;
	cin >> b;

	int n = 0;
	int m = 0;

	while (a[n] != '\0') n++;
	while (b[m] != '\0') m++;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (a[i-1] == b[j-1]) //인덱스 1부터 시작 했으므로
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		}
	}
	cout << dp[n][m];

	return 0;
}