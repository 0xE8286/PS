#include <iostream>
#include <vector>
#define LARGE 987654321
using namespace std;

int N, M;
int from, to, weight;
int graph[101][101];
int nxt[101][101];

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i == j) continue;
			graph[i][j] = LARGE;
		}
	}

	for (int i = 0; i < M; i++) {
		cin >> from >> to >> weight;
		if (weight < graph[from][to]) {
			graph[from][to] = weight;
			nxt[from][to] = to;
		}
	}

	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (graph[i][k] + graph[k][j] < graph[i][j]) {
					graph[i][j] = graph[i][k] + graph[k][j];
					nxt[i][j] = nxt[i][k];
				}
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (graph[i][j] == LARGE) {
				cout << 0 << ' ';
			}
			else {
				cout << graph[i][j] << ' ';
			} 
		}
		cout << '\n';

	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (graph[i][j] == 0 || graph[i][j] == LARGE) {
				cout << 0 << '\n';
				continue;
			}
			int v = i;
			vector<int> route;
			
			while (v != 0) {
				route.push_back(v);
				v = nxt[v][j];
			}

			cout << route.size() << ' ';
			for (int i = 0; i < route.size(); i++) {
				cout << route[i] << ' ';
			}
			cout << '\n';
		}
	}
	return 0;
}