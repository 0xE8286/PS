#include <iostream>
using namespace std;

int N;
int ans;
int num[501];
int arr[501];
int dp[501];

int max(int a, int b) {
	if (a >= b)return a;
	return b;
}

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin >> N;
	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		num[a] = b;
	}

	int k = 0;
	for (int i = 0; i <= 500; i++) {
		if (num[i] != 0)
			arr[k++] = num[i];
	}

	for (int i = 0; i < N; i++) {
		dp[i] = 1;
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j])
				dp[i] = max(dp[j] + 1, dp[i]);
		}
		ans = max(ans, dp[i]);
	}

	cout << N - ans;

	return 0;
}