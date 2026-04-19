#include <iostream>
#include <set>
#include <algorithm>

#define MAX 999999

using namespace std;

set<int> wallet;
int ans[10001];

int N, K, coin;

int main() {

	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);
	
	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		cin >> coin;
		wallet.insert(coin);
	}
	for (int i = 1; i <= K; i++) {
		ans[i] = MAX;
	}
	
	for (int i = 1; i <= K; i++) {
		for (auto iter = wallet.begin(); iter != wallet.end(); iter++) {
			if (i - *iter < 0) continue;
			if (ans[i - *iter] + 1 < ans[i]) {
				ans[i] = ans[i - *iter] + 1;
			}
		}
	}

	if (ans[K] == MAX) {
		cout << -1;
	}
	else {
		cout << ans[K];
	}
	return 0;
}