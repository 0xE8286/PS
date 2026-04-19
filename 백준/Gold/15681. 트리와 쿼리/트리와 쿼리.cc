#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, R, Q, U;
int u, v;

vector<int> edge[100001];
bool visit[100001];

vector<int> children[100001];
int treeSize[100001];

int getSize(int x) {
	treeSize[x] = 1;
	for (int child : children[x]) {
		treeSize[x] += getSize(child);
	}
	return treeSize[x];
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> R >> Q;

	for (int i = 0; i < N - 1; i++) {
		cin >> u >> v;
		edge[u].push_back(v);
		edge[v].push_back(u);
	}

	queue<int> q;
	visit[R] = true;
	q.push(R);
	
	while (!q.empty()) {
		int curr = q.front(); q.pop();

		for (int next: edge[curr]) {
			if (!visit[next]) {
				visit[next] = true;
				children[curr].push_back(next);
				q.push(next);
			}
		}
	}
	getSize(R);
	for (int i = 0; i < Q; i++) {
		cin >> U;
		cout << treeSize[U] << '\n';
	}
	return 0;
}