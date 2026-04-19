#include <iostream>
using namespace std;

int N;
int price[10001];
int dp[10001];

int main() {

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> price[i];
		dp[i] = price[i];
	}

	for (int i = 2; i <= N; i++) {
		for (int j = 1; j < i; j++) {
			dp[i] = max(dp[i], dp[j] + price[i - j]);
		}
	}
	cout << dp[N];
	return 0;
}