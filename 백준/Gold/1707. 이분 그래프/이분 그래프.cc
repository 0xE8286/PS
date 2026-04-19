#include <iostream>
#include <queue>

#define MAX_V 20001
#define RED 1
#define BLUE -1

using namespace std;

int T, V, E;
int from, to;

vector<int> edge[MAX_V];
int color[MAX_V];
bool visit[MAX_V];

typedef pair<int, int> info;

void clear() {
	for (int i = 0; i < MAX_V; i++) {
		edge[i].clear();
		color[i] = 0;
		visit[i] = false;
	}
}

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> T;
	for (int tc = 0; tc < T; tc++) {

		cin >> V >> E;

		for (int i = 0; i < E; i++) {
			cin >> from >> to;
			edge[from].push_back(to);
			edge[to].push_back(from);
		}

		bool isBinTree = true;

		for (int v = 1; v <= V; v++) {
			if (visit[v] == true) continue;
			
			queue<int> q;
			color[v] = RED;
			visit[v] = true;
			q.push(v);

			while (!q.empty() && isBinTree) {
				int curr = q.front();
				q.pop();

				for (auto next : edge[curr]) {
					int next_color = color[curr] * -1;
					if (!visit[next]) {
						visit[next] = true;
						color[next] = next_color;
						q.push(next);
					}
					else {
						if (color[next] != next_color) {
							isBinTree = false;
							break;
						}
					}
				}
			}
			if (!isBinTree) {
				break;
			}
		}
		
		if (isBinTree) cout << "YES\n";
		else cout << "NO\n";

		clear();
	}

	return 0;
}