#include <iostream>
#include <queue>

#define MAX 101

using namespace std;

int N, M;
int ans;
char map[MAX][MAX];
int visit[MAX][MAX];
int dy[4] = { 0, 0, -1, 1 };
int dx[4] = { -1, 1, 0, 0 };

queue<pair<int, int>> q;

bool isWall(int y, int x) {
	if (y < 0 || y >= N || x < 0 || x >= M)
		return true;
	return false;
}

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> map[i];
	}

	q.push({ 0, 0 });
	visit[0][0] = 1;

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;

		q.pop();

		if (y == N - 1 && x == M - 1) {
			break;
		}

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (!isWall(y, x) && visit[ny][nx] == 0 && map[ny][nx] == '1') {
				q.push({ ny, nx });
				visit[ny][nx] = visit[y][x] + 1;
			}
		}
	}
	cout << visit[N - 1][M - 1];

	return 0;
}