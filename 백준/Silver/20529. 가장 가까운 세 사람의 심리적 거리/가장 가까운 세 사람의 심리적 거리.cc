#include <iostream>
#include <set>
#include <map>
#include <vector>

using namespace std;
int T, N;

string param;
map<string, int> m;
vector<string> v;
int ans;

void init() {
	m.clear();
	v.clear();

	ans = 999999;
}

int distance(const string a, const string b, const string c) {
	int dist = 0;
	for (int i = 0; i < 4; i++) {
		if (a[i] != b[i]) dist++;
	}
	for (int i = 0; i < 4; i++) {
		if (b[i] != c[i]) dist++;
	}
	for (int i = 0; i < 4; i++) {
		if (c[i] != a[i]) dist++;
	}
	return dist;
}

void nC3(int depth) {
	if (depth == 3) {
		int dist = distance(v[0], v[1], v[2]);
		if (dist < ans) ans = dist;
		return;
	}
	for (auto i = m.begin(); i != m.end(); i++) {
		if (i->second != 0) {
			i->second--;
			v.push_back(i->first);

			nC3(depth + 1);
			
			i->second++;
			v.pop_back();
		}
	}
}

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> T;
	for (int tc = 0; tc < T; tc++) {

		init();
		cin >> N;

		for (int i = 0; i < N; i++) {
			cin >> param;
			if (m.find(param) == m.end()) {
				m.insert(make_pair(param, 1));
			}
			else {
				m[param]++;
			}
		}

		if (N > 32) {
			cout << 0 << '\n';
		}
		else {
			nC3(0);
			cout << ans << '\n';
		}
		
	}
	return 0;
}