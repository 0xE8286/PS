#include <iostream>
#include <queue>

using namespace std;
typedef pair<int, int> pos;

int N, M;
int map[100][100];
int visit[100][100];

int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 1, 0, -1, 0 };

int prev_answer;
int curr_answer;

int isValid(int y, int x) {
	if (y < 0 || y >= N || x < 0 || x >= M) {
		return false;
	}
	return true;
}

bool finish() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 1) {
				return false;
			}
		}
	}
	return true;
}

void melt() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 2) {
				map[i][j] = 0;
			}
		}
	}
}

int cnt() {
	int val = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 1) {
				val++;
			}
		}
	}
	return val;
}

void print() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << map[i][j] << ' ';
		}
		cout << '\n';
	}

	cout << '\n';
}

void clear() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			visit[i][j] = 0;
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
	curr_answer = cnt();
	int time = 0;
	while (!finish()) {
		queue<pos> q;
		q.push(pos(0, 0));
		visit[0][0] = 1;
		while (!q.empty()) {
			pos now = q.front();
			q.pop();
			for (int i = 0; i < 4; i++) {
				int y = now.first + dy[i];
				int x = now.second + dx[i];
				
				if (isValid(y, x)) {
					if (map[y][x] == 0 && visit[y][x] == 0) {
						visit[y][x] = 1;
						q.push(pos(y, x));
					}
					else if (map[y][x] == 1) {
						map[y][x] = 2;
					}
				}
			}
		}
		time++;
		melt();
		clear();
		prev_answer = curr_answer;
		curr_answer = cnt();
	}
	cout << time << '\n';
	cout << prev_answer << '\n';
	
	return 0;
}