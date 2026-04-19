#include <iostream>
#include <vector>
#include <queue>

#define MAX_N 505 
#define MAX_E 10005
#define INF 1e9

using namespace std;

int N, M;
int S, E;
int U, V, P;

typedef pair<int, int> pii;

struct edge {
	int start;
	int end;
	int weight;
	bool isShortest;
};

edge edges[MAX_E];
vector<int> graph[MAX_N];     
vector<int> rev_graph[MAX_N]; 

int dist[MAX_N];
bool visited[MAX_N];

void clear_graph() {
	for (int i = 0; i < N; i++) {
		graph[i].clear();
		rev_graph[i].clear(); 
	}
}

void dijkstra() {
	fill(dist, dist + N, INF);

	priority_queue<pii, vector<pii>, greater<>> pq;

	dist[S] = 0;
	pq.push({ 0, S });

	while (!pq.empty()) {
		int curr_cost = pq.top().first;
		int curr_node = pq.top().second;
		pq.pop();

		if (dist[curr_node] < curr_cost) continue;

		for (int eid : graph[curr_node]) {
			if (edges[eid].isShortest) continue;

			int next_cost = curr_cost + edges[eid].weight;
			int next_node = edges[eid].end;

			if (next_cost < dist[next_node]) {
				dist[next_node] = next_cost;
				pq.push({ next_cost, next_node });
			}
		}
	}
}

void mark_shortest_by_bfs() {
	queue<int> q;
	q.push(E);

	fill(visited, visited + N, false);
	visited[E] = true;

	while (!q.empty()) {
		int curr_node = q.front();
		q.pop();

		for (int eid : rev_graph[curr_node]) {
			int prev_node = edges[eid].start;
			int weight = edges[eid].weight;

			if (dist[prev_node] + weight == dist[curr_node]) {
				
				edges[eid].isShortest = true; 
				
				if (!visited[prev_node]) {
					visited[prev_node] = true;
					q.push(prev_node);
				}
			}
		}
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	while (true) {
		cin >> N >> M;
		if (N == 0 && M == 0) {
			break;
		}

		cin >> S >> E;

		clear_graph();

		for (int i = 0; i < M; i++) {
			cin >> U >> V >> P;
			edges[i] = { U, V, P, false };

			graph[U].push_back(i);
			rev_graph[V].push_back(i); 
		}

		dijkstra();

		if (dist[E] == INF) {
			cout << -1 << '\n';
			continue;
		}

		mark_shortest_by_bfs();

		dijkstra();

		if (dist[E] == INF) {
			cout << -1 << '\n';
		}
		else {
			cout << dist[E] << '\n';
		}
	}
	return 0;
}