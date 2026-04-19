#include <iostream>
#include <queue>
using namespace std;

#define MAX 1001

int box[MAX][MAX];
int N, M;
int max_depth;
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

queue<pair<int, int>> q;

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> M >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> box[i][j];
			if (box[i][j] == 1) {
				q.push(make_pair(i, j));
			}
		}
	}

	pair<int, int> v;

	while (!q.empty()) {
		v = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = v.first + dy[i];
			int nx = v.second + dx[i];
			if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
			if (box[ny][nx] == 0) {
				box[ny][nx] = box[v.first][v.second] + 1;
				q.push(make_pair(ny, nx));
			}
		}	
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (box[i][j] == 0) {
				cout << -1;
				return 0;
			}
			if (box[i][j] > max_depth) {
				max_depth = box[i][j];
			}
		}
	}
	cout << max_depth-1;
	return 0;
}