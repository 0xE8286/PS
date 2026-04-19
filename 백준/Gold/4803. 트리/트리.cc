#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N, M;
int from, to;
vector<int> edge[501];
bool visit[501];
int parent[501];

void clear(int N) {
	for (int i = 1; i <= N; i++) {
		edge[i].clear();
		visit[i] = 0;
		parent[i] = 0;
	}
}

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;

	int tc = 0;

	while (!(N == 0 && M == 0)) {
		
		for (int i = 0; i < M; i++) {
			cin >> from >> to;
			edge[from].push_back(to);
			edge[to].push_back(from);
		}

		int tree = 0;
		for (int v = 1; v <= N; v++) {
			if (visit[v]) continue;

			visit[v] = true;
			parent[v] = -1;

			queue<int> q;
			q.push(v);

			bool isCycle = false;

			while (!q.empty() && !isCycle) {
				int curr = q.front();
				q.pop();

				for (auto next : edge[curr]) {
					if (!visit[next]) {
						visit[next] = true;
						parent[next] = curr;
						q.push(next);
					}
					else {
						if (next != parent[curr] && parent[next] != curr) { 
							isCycle = true;
							break;
						}
					}
				}
			}
			if (!isCycle) {
				tree++;
			}
		}

		cout << "Case " << ++tc << ": ";
		if (tree == 0) {
			cout << "No trees.\n";
		}
		else if (tree == 1) {
			cout << "There is one tree.\n";
		}
		else {
			cout << "A forest of " << tree << " trees.\n";
		}

		cin >> N >> M;
		clear(N);
	}

	return 0;
}