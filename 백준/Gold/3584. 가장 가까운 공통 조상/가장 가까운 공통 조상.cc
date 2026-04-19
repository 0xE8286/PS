#include <iostream>
#include <queue>
#include <vector>

using namespace std;
int T, N;
int p, c;
int a, b;

vector<int> children[10001];
int parent[10001];
int depth[10001];

void init(int n) {
	for (int i = 1; i <= n; i++) {
		children[i].clear();
		parent[i] = 0;
		depth[i] = 0;
	}
}

int LCA(int u, int v) {
	if (depth[u] < depth[v]) {
		swap(u, v);
	}
	while (depth[u] > depth[v]) {
		u = parent[u];
	}
	while (u != v) {
		u = parent[u];
		v = parent[v];
	}
	return u;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> T;
	for (int tc = 0; tc < T; tc++) {
		cin >> N;
		
		init(N);
		for (int i = 0; i < N - 1; i++) {
			cin >> p >> c;
			children[p].push_back(c);
			parent[c] = p;
		}

		//1. 트리의 root를 찾고
		int root;
		for (int i = 1; i <= N; i++) {
			if (parent[i] == 0) {
				root = i;
				break;
			}
		}
		//2. 트리의 depth 기록
		queue<int> q;
		q.push(root);
		depth[root] = 0;
		while (!q.empty()) {
			int curr = q.front(); q.pop();
			for (auto child : children[curr]) {
				depth[child] = depth[curr] + 1;
				q.push(child);
			}
		}
		//3. LCA 찾기
		cin >> a >> b;
		cout << LCA(a, b) <<'\n';
	}
	return 0;
} 