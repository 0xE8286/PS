#include <iostream>
#include <tuple>
#include <queue>
#define LARGE 987654321

using namespace std;

int map[1001][1001];
int cost[1001];
int visit[1001];

int N, M;
int S, E;
int from, to, weight;
typedef pair<int, int> e;

int main() {

	cin >> N >> M;

	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= N; j++) {
			map[i][j] = -1;
		}
	}
	
	for (int i = 0; i < M; i++) {
		cin >> from >> to >> weight;
		if (map[from][to] > -1 && map[from][to] < weight) continue;
		map[from][to] = weight;
	}

	for (int i = 1; i <= N; i++) {
		cost[i] = LARGE;
	}

	cin >> S >> E;

	cost[S] = 0;
	priority_queue<e, vector<e>, greater<e>> q;
	q.push(e(0, S));
	//sum of weight, vertex

	while (!q.empty()) {
		e now = q.top(); q.pop();
		int v = now.second;
		visit[v] = 1;

		for (int i = 1; i <= N; i++) {
			if (visit[i] == 0 && map[v][i] > -1) {
				int next_cost = now.first + map[v][i];
				if (next_cost < cost[i]) {
					cost[i] = next_cost;
					q.push(e(next_cost, i));
				}
			}
		}
	}

	cout << cost[E] << endl;

	return 0;
}