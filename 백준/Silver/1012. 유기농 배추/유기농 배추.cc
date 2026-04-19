#include <iostream>
using namespace std;

int map[51][51];
int M, N, K;

int dir_x[4] = { 0, 0, -1, 1 };
int dir_y[4] = { -1, 1, 0, 0 };
int ans;

void dfs(int y, int x) {
	map[y][x] = 0;
	
	for (int i = 0; i < 4; i++) {
		int ny = y + dir_y[i];
		int nx = x + dir_x[i];

		if (ny >= 0 && ny < N && nx >= 0 && nx < M && map[ny][nx] == 1) {
			dfs(ny, nx);
		}
	}
}

int main(void) {

	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int T;
	cin >> T;
	
	for (int tc = 0; tc < T; tc++) {
	
		
		cin >> M >> N >> K;

		for (int i = 0; i < K; i++) {
			int x, y;
			cin >> x >> y;
			map[y][x] = 1;
		}

		ans = 0;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (map[i][j] == 1) {
					dfs(i, j);
					ans++;
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}