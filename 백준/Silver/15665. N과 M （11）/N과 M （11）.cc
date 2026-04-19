#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
int num[7];
vector<int> v;

void dfs(int d) {
	if (d == M) {
		for (auto i = v.begin(); i != v.end(); i++) {
			cout << *i << ' ';
		}
		cout << '\n';
		return;
	}
	int prev = -1;
	for (int i = 0; i < N; i++) {
		if (num[i] != prev) {
			v.push_back(num[i]);
			dfs(d + 1);
			v.pop_back();
			prev = num[i];
		}
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> N >> M;
	
	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}
	sort(num, &num[N]);
	dfs(0);
	
	return 0;
}