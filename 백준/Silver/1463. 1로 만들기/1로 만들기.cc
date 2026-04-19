#include <iostream>
#include <cmath>
using namespace std;

int N;
int dp[1000001];

int main() {

	cin >> N;

	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 1;

	for (int i = 4; i <= N; i++) {
		int a = 99999999;
		if (i % 3 == 0 && dp[i / 3] + 1 < a) a = dp[i / 3] + 1;
		if (i % 2 == 0 && dp[i / 2] + 1 < a) a = dp[i / 2] + 1;
		if (dp[i - 1] + 1 < a) a = dp[i - 1] + 1;
		dp[i] = a;
	}

	cout << dp[N];

	return 0;
}