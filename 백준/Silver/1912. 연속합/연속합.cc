#include <iostream>
#define MAX_N 100000
using namespace std;

int num[MAX_N + 1];
int dp[MAX_N + 1];
int N;
int ans;

int max(int a, int b) {
	if (a >= b)return a;
	return b;
}

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}

	dp[0] = num[0];
	ans = num[0];

	for (int i = 1; i < N; i++) {
		dp[i] = max(dp[i - 1] + num[i], num[i]);
	}

	for (int i = 0; i < N; i++) {
		ans = max(ans, dp[i]);
	}

	cout << ans;

	return 0;
}