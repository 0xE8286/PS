#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

typedef pair<int, int> edge;

int N, M;
vector<edge> tree[40001];
int parent[40001];
int depth[40001];
int dist[40001];
bool visit[40001];

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
	int a, b, c;
	for (int i = 0; i < N - 1; i++) {
		cin >> a >> b >> c;
		tree[a].push_back({b, c});
		tree[b].push_back({a, c});
	}
	
	queue<int> q;
	q.push(1);

	visit[1] = 1;
	depth[1] = 1;

	while (!q.empty()) {
		int curr = q.front(); q.pop();
		for (edge e : tree[curr]) {
			int next = e.first;
			int cost = e.second;
			if (!visit[next]) {
				parent[next] = curr;
				depth[next] = depth[curr] + 1;
				dist[next] = dist[curr] + cost;
				visit[next] = 1;
				q.push(next);
			}
		}
	}
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		cout << (dist[a] + dist[b]) - (2 * dist[lca(a, b)]) << '\n';
	}
	return 0;
}