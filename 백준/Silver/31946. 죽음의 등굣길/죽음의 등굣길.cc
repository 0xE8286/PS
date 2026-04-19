#include <iostream>
#include <queue>

using namespace std;

int N, M, X;

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, -1, 0, 1 };

int ddy[4] = { -1, -1, 1, 1 };
int ddx[4] = { -1, 1, -1, 1 };

int map[100][100];
bool visit[100][100];

int getDist(int y1, int x1, int y2, int x2) {
	return abs(x1 - x2) + abs(y1 - y2);
}
bool isValid(int y, int x) {
	if (y < 0 || x < 0 || y >= N || x >= M) {
		return false;
	}
	return true;
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}
	cin >> X;
	
	int C = map[0][0];
	if (map[N - 1][M - 1] != C) {
		cout << "DEAD";
		return 0;
	}
	
	queue<pair<int, int>> q;
	q.push({ 0, 0 });
	visit[0][0] = true;

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int ny = 0; ny < N; ny++) {
			for (int nx = 0; nx < M; nx++) {
				if (!isValid(ny, nx)) continue;
				if (visit[ny][nx]) continue;
				if (map[ny][nx] != C) continue;
				if (getDist(y, x, ny, nx) > X) continue;

				if (ny == N - 1 && nx == M - 1) {
					cout << "ALIVE";
					return 0;
				}
				q.push({ ny, nx });
				visit[ny][nx] = true;
			}
		}
	}

	cout << "DEAD";
	return 0;
}