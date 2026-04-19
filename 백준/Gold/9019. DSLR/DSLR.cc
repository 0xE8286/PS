#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

int T;
int from, to;
int ans;
typedef pair<int, string> ns;
int vs[10000];

void clear() {
	for (int i = 0; i < 10000; i++) {
		vs[i] = 0;
	}
}

int D(int n) {
	return (n * 2) % 10000;
}
int S(int n) {
	if (n == 0) return 9999;
	return n - 1;
}
int L(int n) {
	int left = n / 1000;
	n = (n % 1000) * 10;
	return n + left;
}

int R(int n) {
	int right = n % 10;
	n = n / 10;
	return (right * 1000) + n;
}

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> T;
	for (int tc = 0; tc < T; tc++) {
		cin >> from >> to;
		
		string ans;
		queue<ns> q;
		q.push(ns(from, ""));

		while (!q.empty()) {
			int num = q.front().first;
			string step = q.front().second;
			q.pop();

			if (num == to) {
				ans = step;
				break;
			}

			int d = D(num);
			int s = S(num);
			int l = L(num);
			int r = R(num);

			if (vs[d] == 0) {
				vs[d] = 1;
				q.push(ns(d, step + "D"));
			}
			if (vs[s] == 0) {
				vs[s] = 1;
				q.push(ns(s, step + "S"));
			}
			if (vs[l] == 0) {
				vs[l] = 1;
				q.push(ns(l, step + "L"));
			}
			if (vs[r] == 0) {
				vs[r] = 1;
				q.push(ns(r, step + "R"));
			}
		}
		cout << ans << endl;
		clear();
	}
	return 0;
}