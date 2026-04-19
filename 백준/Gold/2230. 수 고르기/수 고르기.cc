#include <iostream>
#include <stdint.h>
#include <algorithm>
using namespace std;

typedef long long ll;

int N, M;
ll num[100000];
ll ans = INT64_MAX;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}

	sort(num, num + N);

	int s = 0;
	int e = 1;
	ll diff;

	while (s < N && e < N) {
		diff = num[e] - num[s];
		if (diff == M) {
			ans = diff;
			break;
		}
		else if (diff > M) {
			ans = min(ans, diff);
			s++;
		}
		else {
			e++;
		}
	}
	cout << ans;

	return 0;
}