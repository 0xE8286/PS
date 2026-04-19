#include <iostream>
#include <queue>

#define LARGE 987654321

using namespace std;

int graph[1001][1001];
int floyd[1001][1001];

int dijk[1001];
int visit[1001];

int N, M, X;
typedef pair<int, int> tv;

void init() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i == j) continue;
			floyd[i][j] = LARGE;
		}
		dijk[i] = LARGE;
	}
	dijk[X] = 0;
}

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin >> N >> M >> X;
	init();
	
	int from, to, time;

	for (int i = 0; i < M; i++) {
		cin >> from >> to >> time;
		graph[from][to] = time;
		floyd[from][to] = time;
	}

	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				floyd[i][j] = min(floyd[i][j], floyd[i][k] + floyd[k][j]);
			}
		}
	}

	priority_queue<tv, vector<tv>, greater<tv>> q;
	q.push(tv(0, X));

	while (!q.empty()) {
		tv now = q.top(); q.pop();
		visit[now.second] = 1;
		
		for (int i = 1; i <= N; i++) {
			if (graph[now.second][i] == 0 || visit[i] != 0) continue;
			int next_time = now.first + graph[now.second][i];
			if (next_time < dijk[i]) {
				dijk[i] = next_time;
				q.push(tv(next_time, i));
			}
		}
	}

	int max = -1;

	for (int i = 1; i <= N; i++) {
		int time = floyd[i][X] + dijk[i];
		if (time > max) max = time;
	}

	cout << max;
	
	return 0;
}