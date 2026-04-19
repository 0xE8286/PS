#include <iostream>
#include <vector>
#define LARGE 987654321

using namespace std;

typedef pair<int, int> pii;

int TC, N, M, W;
int S, E, T;

int main() {

	cin >> TC;
	for (int tc = 1; tc <= TC; tc++) {
		vector<pii> graph[501];
		
		cin >> N >> M >> W;
		
		for (int i = 0; i < M; i++) {
			cin >> S >> E >> T;
			graph[S].push_back(pii(E, T));
			graph[E].push_back(pii(S, T));
		}
		for (int i = 0; i < W; i++) {
			cin >> S >> E >> T;
			graph[S].push_back(pii(E, -1*T));
		}

		int dist[501];
		fill(dist, dist + N + 1, LARGE);

		bool isCycle = false;
		dist[1] = 0;

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				for (auto e : graph[j]) {
					int v = e.first;
					int t = e.second;

					if (dist[j] + t < dist[v]) {
						dist[v] = dist[j] + t;
						if (i == N) isCycle = true;
					}
				}
			}
		}

		if (isCycle) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}

	}
	return 0;
}