#include <iostream>
using namespace std;

int N, M;
int dir_y[4] = { 0, 1, 0, -1 };
int dir_x[4] = { 1, 0, -1, 0 };
char map[602][602];
bool visit[602][602];
int ans;
typedef pair<int, int> pos;

bool isEnable(int y, int x) {
	if (y < 0 || y >= N || x < 0 || x >= M) return false;
	if (visit[y][x] == true) return false;
	if (map[y][x] == 'X') return false;
	return true;
}

void dfs(pos now) {
	if (map[now.first][now.second] == 'P') {
		ans++;
	}
	for (int i = 0; i < 4; i++) {
		int ny = now.first + dir_y[i];
		int nx = now.second + dir_x[i];
		if (isEnable(ny, nx)) {
			visit[ny][nx] = true;
			dfs(pos(ny, nx));
		}
	}
}

int main() {

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> map[i];
	}
	pos me = pos(0, 0);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 'I') {
				me = pos(i, j);
				visit[i][j] = true;
			}
		}
	}
	dfs(me);

	if (ans == 0) {
		cout << "TT";
	}
	else {
		cout << ans;
	}

	return 0;
}