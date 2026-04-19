#include <bits/stdc++.h>
using namespace std;
using edge = pair<int, int>;

int N;
edge edg[1000000];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N;
	for (int i = 0, s, e; i < N; i++) {
		cin >> s >> e;
		edg[i].first = s;
		edg[i].second = e;
	}

	sort(edg, edg + N);

	for (int i = 1; i < N; i++) {
		if (edg[i - 1].second >= edg[i].first) {
			edg[i].first = edg[i - 1].first;
			if (edg[i - 1].second > edg[i].second) {
				edg[i].second = edg[i - 1].second;
			}
		}
	}

	int ans = 0;
	int check = edg[0].first;
	for (int i = 1; i < N; i++) {
		if (check == edg[i].first) continue;
		ans += edg[i - 1].second - edg[i - 1].first;
		check = edg[i].first;
	}
	ans += (edg[N - 1].second - edg[N - 1].first);
	cout << ans;
	
	return 0;
}