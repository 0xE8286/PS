#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

int N;
int ablity[10000];
ll cnt;

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> ablity[i];
	}

	sort(ablity, ablity + N);

	for (int i = 0; i < N - 2; i++) {
		for (int j = i + 1; j < N - 1; j++) {
			int sum = ablity[i] + ablity[j];
			auto s = ablity + j + 1;
			auto e = ablity + N;
			ll l_idx = lower_bound(s, e, (-1 * sum)) - ablity;
			ll u_idx = upper_bound(s, e, (-1 * sum)) - ablity;
			cnt += (u_idx - l_idx);
		}
	}

	cout << cnt;
	
	return 0;
}