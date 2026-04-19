#include <iostream>
#include <queue>

using namespace std;

int N, M;
int map[100][100];
int visit[100][100];

int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 1, 0, -1, 0 };

typedef pair<int, int> pos;

bool isValid(int y, int x) {
	if (y < 0 || y >= N || x < 0 || x >= M) {
		return false;
	}
	return true;
}

bool isFinish() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] != 0)
				return false;
		}
	}
	return true;
}

void clear() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			visit[i][j] = 0;
		}
	}
}


void melt() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (visit[i][j] >= 2) {
				map[i][j] = 0;
			}
		}
	}
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

	int time = 0;
	while (!isFinish()) {
		queue<pos> q;
		
		q.push(pos(0, 0));
		visit[0][0] = 1;

		while (!q.empty()) {
			pos now = q.front(); q.pop();
			for (int i = 0; i < 4; i++) {
				int y = now.first + dy[i];
				int x = now.second + dx[i];
				if (isValid(y, x)) {
					if (map[y][x] == 0 && visit[y][x] == 0) {
						visit[y][x] = 1;
						q.push(pos(y, x));
					}
					else if (map[y][x] == 1) {
						visit[y][x]++;
					}
				}
			}
		}
		time++;
		melt();
		clear();
	}

	cout << time;

	return 0;
}