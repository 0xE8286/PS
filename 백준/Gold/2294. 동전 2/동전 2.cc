#include <iostream>
#define MAX_K 100001

using namespace std;

int N, K;
int coin[101];
int dp[MAX_K];

int min(int a, int b) {
	if (a <= b)
		return a;
	return b;
}

int main(void) {
    cin.tie(NULL);
	ios::sync_with_stdio(false);
    
	cin >> N >> K;

	for (int i = 1; i <= N; i++) {
		cin >> coin[i];
	}
	for (int i = 1; i <= K; i++) {
		dp[i] = MAX_K;
	}
	
	for (int i = 1; i <= N; i++) {
		for (int j = coin[i]; j <= K; j++) {
			dp[j] = min(dp[j], dp[j - coin[i]] + 1);
		}
	}

	if (dp[K] == MAX_K) dp[K] = -1;
	cout << dp[K];

	return 0;
}