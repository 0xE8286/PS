#include <iostream>
#include <vector>
#include <algorithm>

#define LARGE 987654321

using namespace std;

int N;
int dp[1000001];
int p[1000001];

int main() {
	cin >> N;

	for (int i = 1; i <= N; i++) {
		dp[i] = LARGE;
	}

	dp[N] = 0;

	for (int i = N; i >= 1; i--) {
		if (i % 3 == 0 && dp[i / 3] > dp[i] + 1) {
			dp[i / 3] = dp[i] + 1;
			p[i / 3] = i;
		}
		if (i % 2 == 0 && dp[i / 2] > dp[i] + 1) {
			dp[i / 2] = dp[i] + 1;
			p[i / 2] = i;
		}
		if (dp[i - 1] > dp[i] + 1) {
			dp[i - 1] = dp[i] + 1;
			p[i - 1] = i;
		}
	}

	cout << dp[1] << '\n';

	vector<int> route;
	int curr = 1;
	
	while (curr != 0) {
		route.push_back(curr);
		curr = p[curr];
	}
	
	reverse(route.begin(), route.end());
	
	for (int n : route) {
		cout << n << ' ';
	}
	
	return 0;
}