#include <iostream>
#include <queue>
using namespace std;

int N, M;

char map[1001][1001];
int f[1001][1001];

int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 1, 0, -1, 0 };

typedef pair<int, int> pos;
typedef pair<pos, int> pos_time;

bool isValid(int y, int x) {
	if (y < 0 || x < 0 || y >= N || x >= M) {
		return false;
	}
	if (map[y][x] == '#') {
		return false;
	}
	return true;
}

bool isExit(int y, int x) {
	if (y == 0 || x == 0 || y == N - 1 || x == M - 1) {
		return true;
	}
	return false;
}

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;

	queue<pos> fire;
	queue<pos_time> jihun;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'J') {
				jihun.push({ {i, j}, 1 });
			}
			else if (map[i][j] == 'F') {
				fire.push({ i, j });
				f[i][j] = 1;
			}
		}
	}

	while (!fire.empty()) {

		int y = fire.front().first;
		int x = fire.front().second;
		fire.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (isValid(ny, nx) && f[ny][nx] == 0) {
				fire.push({ ny, nx });
				f[ny][nx] = f[y][x] + 1;
			}
		}
	}

	while (!jihun.empty()) {

		int y = jihun.front().first.first;
		int x = jihun.front().first.second;
		int time = jihun.front().second;
		jihun.pop();

		if (isExit(y, x)) {
			cout << time;
			return 0;
		}

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			int nt = time + 1;

			if (isValid(ny, nx) && (f[ny][nx] == 0 || nt < f[ny][nx])) {
				jihun.push({ { ny, nx }, nt });
				map[ny][nx] = '#';
			}
		}
	}

	cout << "IMPOSSIBLE";

	return 0;
}