#include <iostream>
#include <algorithm>
using namespace std;

int N, K;
int ex[300001];
long long sum[300002];
long long ans;

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		cin >> ex[i];
	}
	sort(&ex[1], &ex[N + 1]);

	for (int i = N; i >= 1; i--) {
		sum[i] += sum[i + 1] + ex[i];
	}

	for (int i = 2; i <= K + 1; i++) {
		ans += sum[i];
	}

	cout << ans;

	return 0;
}