#include <iostream>
#include <set>

using namespace std;

int N, K;
int coin;

set<int> wallet;
int ans[100001];

int main() {

	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> coin;
		wallet.insert(coin);
	}

	ans[0] = 1;
	for (auto iter = wallet.begin(); iter != wallet.end(); iter++) {
		for (int i = *iter; i <= K; i++) {
			ans[i] = ans[i] + ans[i - *iter];
		}
	}
	cout << ans[K];

	return 0;
}