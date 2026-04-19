#include <bits/stdc++.h>
using namespace std;
using pos = pair<int, int>;
using dijk = pair<int, int>;

int TC, N;
pos sg;
pos conv[100];
pos rock;
vector<bool> check(100);
bool canMove(pos a, pos b) {
	return 1000 >= abs(a.first - b.first) + abs(a.second - b.second);
}

bool dfs(int n) {
	pos now = n == -1 ? sg : conv[n];
	if (canMove(now, rock)) return true;
	if (n >= 0) check[n] = true;
	for (int i = 0; i < N; i++) {
		if (!check[i] && canMove(now, conv[i])) {
			if(dfs(i)) return true;
		}
	}
	return false;
}

void solve() {
	bool ans = dfs(-1);
	cout << (ans ? "happy" : "sad") << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> TC;
	for (int tc = 0; tc < TC; tc++) {
		cin >> N;
		check.assign(N, false);
		cin >> sg.first >> sg.second;
		for (int i = 0; i < N; i++) {
			cin >> conv[i].first >> conv[i].second;
		}
		cin >> rock.first >> rock.second;
		solve();
	}

	return 0;
}