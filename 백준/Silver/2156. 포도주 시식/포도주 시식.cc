#include <iostream>

using namespace std;

int N;
int arr[10001];
int dp[10001];

int max(int a, int b, int c) {
	if (a > b) {
		if (a > c)
			return a;
		else
			return c;
	}
	else {
		if (b > c)
			return b;
		else
			return c;
	}
}

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}
	dp[1] = arr[1];
	dp[2] = arr[1] + arr[2];

	for (int i = 3; i <= N; i++) {
		dp[i] = max(
			dp[i-2]+arr[i], //n-1을 건너뛰고 먹는다
			dp[i-3] + arr[i-1] + arr[i], //n-2를 건너뛰고 먹는다
			dp[i - 1]); //지금걸 안먹는다 (n-1까지의 최대값)
	}
	cout << dp[N] << endl;

	return 0;
}