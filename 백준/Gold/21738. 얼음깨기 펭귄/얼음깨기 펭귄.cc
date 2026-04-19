#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int N, S, P;
int from, to;
vector<int> graph[328001];
int dist[328001];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> S >> P;
	
	for (int i = 0; i < N - 1; i++) {
		cin >> from >> to;
		graph[from].push_back(to);
		graph[to].push_back(from);
	}

	queue<int> q;
	q.push(P);

	while(!q.empty()) {
		int curr = q.front();
		q.pop();
		
		for (int next : graph[curr]) {
			if (dist[next] == 0 && next != P) {
				q.push(next);
				dist[next] = dist[curr] + 1;
			}
		}
	}
	
	vector<int> dist_red;
	for (int i = 1; i <= S; i++) {
		if (i == P) continue;
		dist_red.push_back(dist[i]);
	}
	sort(dist_red.begin(), dist_red.end());

	cout << N - (dist_red[0] + dist_red[1] + 1);

	return 0;
}