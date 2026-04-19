#include <iostream>
#include <vector>

using namespace std;

int N;
int from, to, weight;

typedef pair<int, int> pii;
vector<pii> tree[100001];
int visit[100001];



void dfs(int vertex, int dist_sum, pii* max) {
	if (max->second < dist_sum) {
		max->first = vertex;
		max->second = dist_sum;
	}
	for (auto e : tree[vertex]) {
		if (visit[e.first] == 0) {
			visit[e.first] = 1;
			dfs(e.first, dist_sum + e.second, max);
		}
	}
}

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> from;
		while (true) {
			cin >> to;
			if (to == -1) {
				break;
			}
			cin >> weight;
			tree[from].push_back(pii(to, weight));
		}
	}

	pii max_dist;
	pii max_dist2;

	visit[1] = 1;
	dfs(1, 0, &max_dist);
	fill(visit, visit + N + 1, 0);
	visit[max_dist.first] = 1;
	dfs(max_dist.first, 0, &max_dist2);
	
	cout << max_dist2.second;

	return 0;
}