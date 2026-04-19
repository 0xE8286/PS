#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int N, M;
int parent[1001];
vector<int> child[1001];
int depth[1001];
int p, a, b;

int LCS(int a, int b) {
	if (depth[a] < depth[b]) {
		swap(a, b);
	}
	while (depth[a] > depth[b]) {
		a = parent[a];
	}
	while (a != b) {
		a = parent[a];
		b = parent[b];
	}
	return a;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;

	for (int i = 2; i <= N; i++) {
		cin >> p;
		parent[i] = p;
		child[p].push_back(i);
	}
	queue<int> q;
	q.push(1);
	depth[1] = 1;
	
	while (!q.empty()) {
		int curr = q.front(); q.pop();
		for (int next : child[curr]) {
			if (depth[next] == 0) {
				depth[next] = depth[curr] + 1;
				q.push(next);
			}
		}
	}
	
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		cout << LCS(a, b) << '\n';
	}

	return 0;
}