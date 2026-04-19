#include <iostream>
#include <queue>
#include <tuple>

#define MAX_N 100
using namespace std;

int N, M, ans;
char map[MAX_N + 1][MAX_N + 1];
int visit[MAX_N + 1][MAX_N + 1];

int dir_x[4] = { 0, 0, -1, 1 };
int dir_y[4] = { -1, 1, 0, 0 };

bool isWall(int y, int x) {
	if (y < 0 || x < 0 || y >=N || x >= M) {
		return true;
	}
	return false;
}

int main(void) {
	cin >> M >> N;
	for (int i = 0; i < N; i++) {
		cin >> map[i];
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			visit[i][j] = 2147483647;
		}
	}
	
	queue<tuple<int, int, int>> q;
	q.push(make_tuple(0, 0, 0));

	visit[0][0] = 0;
	
	while (!q.empty()) {
		int y = get<0>(q.front());
		int x = get<1>(q.front());
		int aoj = get<2>(q.front());
		
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + dir_y[i];
			int nx = x + dir_x[i];
			int naoj = (map[ny][nx] == '1') ? aoj + 1 : aoj;

			if (!isWall(ny, nx) && naoj < visit[ny][nx]) {
				visit[ny][nx] = naoj;
				q.push(make_tuple(ny, nx, naoj));
			}
		}
	}
	cout << visit[N-1][M-1];
	return 0;
}