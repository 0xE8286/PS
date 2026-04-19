#include <iostream>
#define LARGE 987654321

using namespace std;

int N, K;
int dist[101][101];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> K;

	for (int i = 1; i <= N; i++) {
		fill(dist[i], dist[i] + N, LARGE);
	}

	int a, b;

	for (int i = 0; i < K; i++) {
		cin >> a >> b;
		dist[a][b] = 1;
		dist[b][a] = 1;
	}

	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);

			}
		}
	}	
	
	int max_dist = -1;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			max_dist = max(max_dist, dist[i][j]);
		}
	}

	if (max_dist <= 6) {
		cout << "Small World!";
	}
	else {
		cout << "Big World!";
	}

	return 0;
}