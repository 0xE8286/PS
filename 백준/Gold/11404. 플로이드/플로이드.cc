#include <iostream>
#include <cmath>
#define LARGE 987654321
#define NA -1

using namespace std;

int N, M;
int from, to, weight;
int graph[101][101];

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
		if (weight < graph[from][to])
			graph[from][to] = weight;
	}

	for (int k = 1; k <= N; k++) { // k 정점을 거쳐서.. 거쳐가는 점을 가장 바깥에 !!
		for (int i = 1; i <= N; i++) { //i에서부터
			for (int j = 1; j <= N; j++) { // j로 가는 경로
				if (graph[i][k] + graph[k][j] < graph[i][j]) {
					graph[i][j] = graph[i][k] + graph[k][j];
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
	return 0;
}