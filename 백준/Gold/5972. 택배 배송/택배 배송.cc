#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> edge;

#define LARGE 987654321


int N, M;
int from, to, cost;
int c[50001];
int v[50001];
vector<edge> edges[50001];

int main() {
	
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	for (int i = 2; i <= N; i++) {
		c[i] = LARGE;
	}

	for (int i = 0; i < M; i++) {
		cin >> from >> to >> cost;
		edges[from].push_back(edge(cost, to));
		edges[to].push_back(edge(cost, from));
	}

	priority_queue<edge, vector<edge>, greater<>> pq;
	pq.push({ 0, 1 });

	while (!pq.empty()) {
		int cc = pq.top().first;
		int cv = pq.top().second;
		pq.pop();
		
		v[cv] = true;
		
		if (cv == N) {
			break;
		}
		for (edge next : edges[cv]) {
			int nc = cc + next.first;
			int nv = next.second;
			if (!v[nv] && nc < c[nv]) {
				c[nv] = nc;
				pq.push(edge(nc, nv));
			} 
		}
	}
	cout << c[N];

	return 0;
}