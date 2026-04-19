#include <iostream>
#include <queue>

#define LARGE 987654321

using namespace std;

typedef pair<int, int> pii;

int N, M;
int S, E;
int from, to, weight;

int map[1001][1001];
int cost[1001];
int visit[1001];
int prevv[1001];

int main() {

	cin >> N >> M;
	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= N; x++) {
			if (y == x) continue;
			map[y][x] = -1;
		}
	}
	for (int i = 1; i <= N; i++) {
		cost[i] = LARGE;
		prevv[i] = -1;
	}
	for (int i = 1; i <= M; i++) {
		cin >> from >> to >> weight;
		if (map[from][to] == -1) {
			map[from][to] = weight;
		}
		else {
			if (weight < map[from][to] ) {
				map[from][to] = weight;
			}
		}
	}
	cin >> S >> E;

	priority_queue<pii, vector<pii>, greater<pii>> q;
	q.push(make_pair(0, S)); 

	cost[S] = 0;
	while (!q.empty()) {
		pii now = q.top(); q.pop();
		visit[now.second] = 1;

		for (int i = 1; i <= N; i++) {
			
			if (map[now.second][i] > -1 && visit[i] == 0) {
				int next_cost = now.first + map[now.second][i];
				
				if (next_cost < cost[i]) {
					cost[i] = next_cost;
					prevv[i] = now.second;
					q.push(pii(next_cost, i));
				}
			}
		}
	}

	vector<int> route;
	int vertexx = E;

	while (vertexx != -1) {
		route.push_back(vertexx);
		vertexx = prevv[vertexx];
	}

	cout << cost[E] << '\n';
	cout << route.size() << '\n';
	for (auto i = route.rbegin(); i != route.rend(); i++) {
		cout << *i << ' ';
	}
	cout << '\n';

	return 0;
}