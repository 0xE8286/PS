#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, M;
vector<int> tree[50001];

int parent[50001];
int depth[50001];
bool visit[50001];

int lca(int v1, int v2) {
	if (depth[v1] < depth[v2]) {
		swap(v1, v2);
	}
	while (depth[v1] > depth[v2]) {
		v1 = parent[v1];
	}
	while (v1 != v2) {
		v1 = parent[v1];
		v2 = parent[v2];
	}
	return v1;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin >> N;
	int a, b;
	for (int i = 1; i < N; i++) {
		cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	queue<int> q;
	q.push(1);
	visit[1] = true;
	depth[1] = 1;
	while (!q.empty()) {
		int curr = q.front(); q.pop();
		for (auto next : tree[curr]) {
			if (!visit[next]) {
				visit[next] = true;
				parent[next] = curr;
				depth[next] = depth[curr] + 1;
				q.push(next);
			}
		}
	}
	cin >> M;
	for (int i = 0; i < M; i++){
		cin >> a >> b;
		cout << lca(a, b) << '\n';
	}
	
	return 0;
}