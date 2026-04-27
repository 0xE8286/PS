#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

struct dish {
	ll t, a, b;
};
int N; ll D;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> D;
	vector<dish> dishes(N);
	
	for (int i = 0; i < N; i++) {
		cin >> dishes[i].t >> dishes[i].a >> dishes[i].b;
	}

	sort(dishes.begin(), dishes.end(), [](const dish& d1, const dish& d2) {
		return d1.t < d2.t;
	});

	vector<ll> times(N);
	vector<ll> max_a_score(N);

	for (int i = 0; i < N; i++) {
		times[i] = dishes[i].t;
		if (i == 0) max_a_score[i] = dishes[i].a;
		else max_a_score[i] = max(max_a_score[i - 1], dishes[i].a);
	}

	ll ans = 0;

	for (int i = 0; i < N; i++) {
		if (dishes[i].t <= D) {
			ans = max(ans, dishes[i].a + dishes[i].b);
		}

		ll remain_time = D - dishes[i].t;
		if (remain_time > 0) {
			auto iter = upper_bound(times.begin(), times.end(), remain_time);

			if (iter != times.begin()) {
				int idx = distance(times.begin(), iter) - 1;
				ans = max(ans, max_a_score[idx] + dishes[i].b);
			}
		}
	}
	cout << ans << "\n";

	return 0;
}