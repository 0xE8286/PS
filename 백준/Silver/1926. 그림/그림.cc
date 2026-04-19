#include <iostream>
using namespace std;

int N, M;
int map[500][500];
int visit[500][500];
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, -1, 0, 1};
int cnt;
int ans;

bool isValid(int y, int x) {
	if (y < 0 || x < 0 || y >= N || x >= M) {
		return false;
	}
	if (map[y][x] == 0) {
		return false;
	}
	if (visit[y][x] > 0) {
		return false;
	}
	return true;
}

int dfs(int y, int x) {
	int size = 1;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (isValid(ny, nx)) {
			visit[ny][nx] = 1;
			size += dfs(ny, nx);
		}
	}
	return size;
}
int main() {
	cin >> N >> M;
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			
			if (isValid(i, j)) {
				visit[i][j] = 1;
				cnt++;
				ans = max(ans, dfs(i, j));
			}
		}
	}

	cout << cnt << '\n' << ans;

	return 0;
}