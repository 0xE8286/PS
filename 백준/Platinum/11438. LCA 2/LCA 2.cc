#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

#define MAX_N 100001
#define MAX_K 17
using namespace std;

int N, M;
vector<int> tree[MAX_N];

int parents[MAX_N][MAX_K];
int depth[MAX_N];
int visit[MAX_N];

int lca(int v1, int v2) {
	if (depth[v1] < depth[v2]) {
		swap(v1, v2);
	}
	int K = log2(depth[v1]);
	for (int k = K; k >= 0; k--) {
		if (depth[v1] - (1 << k) >= depth[v2]) {
			v1 = parents[v1][k];
		}
	}
	if (v1 == v2) return v1;

	K = log2(depth[v1]);
	for (int k = K; k >= 0; k--) {
		if (parents[v1][k] != parents[v2][k]) {
			v1 = parents[v1][k];
			v2 = parents[v2][k];
		}
	}
	return parents[v1][0];
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	int a, b;
	for (int i = 0; i < N - 1; i++) {
		cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	
	queue<int> q;
	q.push(1);

	visit[1] = 1;
	depth[1] = 0;

	while (!q.empty()) {
		int curr = q.front(); q.pop();

		for (int next : tree[curr]) {
			if (!visit[next]) {
				visit[next] = 1;
				depth[next] = depth[curr] + 1;
				parents[next][0] = curr;
				q.push(next);
			}
		}
	}

	for (int k = 1; k < MAX_K; k++) {
		for (int i = 1; i <= N; i++) {
			if (parents[i][k - 1] != 0) {
				parents[i][k] = parents[parents[i][k - 1]][k - 1];
			}
		}
	}

	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		cout << lca(a, b) << '\n';
	}

	return 0;
}