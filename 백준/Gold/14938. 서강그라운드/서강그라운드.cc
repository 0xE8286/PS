#include <iostream>
#define LARGE 987654321
using namespace std;

int N, M, R;
int stuff[101];
int floyd[101][101];

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M >> R;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i == j) continue;
			floyd[i][j] = LARGE;
		}
	}
	for (int i = 1; i <= N; i++) {
		cin >> stuff[i];
	}

	int from, to, dist;
	for (int i = 1; i <= R; i++) {
		cin >> from >> to >> dist;
		floyd[from][to] = dist;
		floyd[to][from] = dist;
	}

	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				floyd[i][j] = min(floyd[i][j], floyd[i][k] + floyd[k][j]);
			}
		}
	}
	
	int max = 0;
	for (int i = 1; i <= N; i++) {
		int sum = 0;
		for (int j = 1; j <= N; j++) {
			if (floyd[i][j] <= M) {
				sum += stuff[j];
			}
		}
		if (sum > max) {
			max = sum;
		}
	}
	cout << max;

	return 0;
}