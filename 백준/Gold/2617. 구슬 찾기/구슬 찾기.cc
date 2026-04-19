#include <iostream>
#define LARGE 987654321
using namespace std;

int N, M;
int A, B;
int dist_heavy[100][100];
int dist_light[100][100];

int main() {

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i == j) {
				dist_heavy[i][j] = 0;
				dist_light[i][j] = 0;
				continue;
			}
			dist_heavy[i][j] = LARGE;
			dist_light[i][j] = LARGE;
		}
	}

	for (int i = 0; i < M; i++) {
		cin >> A >> B;
		dist_heavy[B][A] = 1;
		dist_light[A][B] = 1;
	}

	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				dist_heavy[i][j] = min(dist_heavy[i][j], dist_heavy[i][k] + dist_heavy[k][j]);
				dist_light[i][j] = min(dist_light[i][j], dist_light[i][k] + dist_light[k][j]);
			}
		}
	}

	int ans = 0;
	int middle = (N + 1) / 2;

	for (int i = 1; i <= N; i++) {
		int cnt_heavy = 0;
		int cnt_light = 0;
		
		for (int j = 1; j <= N; j++) {
			if (dist_heavy[i][j] > 0 && dist_heavy[i][j] < 100) {
				cnt_heavy++;
			}
			if (dist_light[i][j] > 0 && dist_light[i][j] < 100) {
				cnt_light++;
			}
		}

		if (cnt_heavy >= middle) ans++;
		if (cnt_light >= middle) ans++;
 	}

	cout << ans;

	return 0;
}