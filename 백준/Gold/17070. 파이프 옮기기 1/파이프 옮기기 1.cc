#include <iostream>
using namespace std;

int N;
int map[16][16];
int cnt;

bool isValid(int y, int x, int dir) {
	if (y < 0 || x < 0 || y >= N || x >= N) return false;
	if (map[y][x] == 1) return false;
	if (dir == 2) {
		if (map[y - 1][x] || map[y][x - 1]) return false;
	}
	return true;
}

void dfs(int y, int x, int dir) {
	if (!isValid(y, x, dir)) {
		return;
	}
	if (y == N - 1 && x == N - 1) {
		cnt++;
		return;
	}

	if (dir == 0) {
		dfs(y, x + 1, 0);
		dfs(y + 1, x + 1, 2);
	}
	else if (dir == 1) {
		dfs(y + 1, x, 1);
		dfs(y + 1, x + 1, 2);
	}
	else {
		dfs(y, x + 1, 0);
		dfs(y + 1, x, 1);
		dfs(y + 1, x + 1, 2);
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
	dfs(0, 1, 0);
	cout << cnt;

	return 0;
}