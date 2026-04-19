#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define LARGE 987654321
typedef pair<int, int> pii;

int N, M;
long long int dist[501];
vector<pii> graph[501];
bool isCycle = false;

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;

	int from, to, time;
	for (int i = 0; i < M; i++) {
		cin >> from >> to >> time;
		graph[from].push_back(pii(to, time));
	}

	for (int i = 2; i <= N; i++) {
		dist[i] = LARGE;
	}
		
	for (int i = 1; i <= N; i++) { 
		for (int j = 1; j <= N; j++) {
			for (auto e : graph[j]) {
				if (dist[j] != LARGE && dist[j] + e.second < dist[e.first]) {
					dist[e.first] = dist[j] + e.second;
					if (i == N) {
						isCycle = true;
					}
				}
			}
		}
	}

	if (isCycle) {
		cout << -1 << '\n';
	}
	else {
		for (int i = 2; i <= N; i++) {
			if (dist[i] == LARGE) {
				cout << -1 << '\n';
			}
			else {
				cout << dist[i] << '\n';
			}
		}
	}

	return 0;
}