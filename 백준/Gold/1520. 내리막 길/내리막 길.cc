#include <iostream>
using namespace std;

int N, M;
int map[500][500];
int dp[500][500];

int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 1, 0, -1, 0 };

bool isValid(int y, int x) {
	if (y < 0 || y >= N || x < 0 || x >= M) return false;
	return true;
}

int dfs(int y, int x) {
	
	if (y == N - 1 && x == M - 1) {
		return 1;
	}
	if (dp[y][x] > -1) {
		return dp[y][x];
	}
	
	dp[y][x] = 0;
	
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		
		if (!isValid(ny, nx)) continue;
		if (map[ny][nx] >= map[y][x]) continue;

		dp[y][x] += dfs(ny, nx);
	}
	return dp[y][x];
}

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			dp[i][j] = -1;
		}
	}

	cout << dfs(0, 0);
	
	return 0;
}