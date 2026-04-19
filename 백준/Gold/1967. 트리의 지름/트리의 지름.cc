#include <iostream>
#include <vector>

using namespace std;
typedef pair<int, int> pii;

vector<pii> tree[10001];
int visit[10001];

int N;
int from, to, weight;


void dfs(int vertex, int dist, pii* max) {
	if (dist > max->second) {
		max->second = dist;
		max->first = vertex;
	}
	for (auto e : tree[vertex]) {
		if (visit[e.first] == 0) {
			visit[e.first] = 1;
			dfs(e.first, dist + e.second, max);
		}
	}
}

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	
	for (int i = 1; i < N; i++) {
		cin >> from >> to >> weight;
		tree[from].push_back(pii(to, weight));
		tree[to].push_back(pii(from, weight));
	}

	pii maxfromroot;
	pii maxfromv;

	visit[1] = 1;
	dfs(1, 0, &maxfromroot);

	fill(visit, visit + N + 1, 0);

	visit[maxfromroot.first] = 1;
	dfs(maxfromroot.first, 0, &maxfromv);

	cout << maxfromv.second;
	
	return 0;
}