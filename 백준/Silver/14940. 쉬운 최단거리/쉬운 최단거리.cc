#include <iostream>
#include <queue>
using namespace std;

int N, M;
int map[1001][1001];
int dist[1001][1001];
pair<int, int> fin;

//좌상우하
int dir_y[4] = {0, -1, 0, 1};
int dir_x[4] = { -1, 0, 1, 0 };

int main() {
	cin >> N >> M;
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {

			dist[i][j] = -1;

			cin >> map[i][j];

			if (map[i][j] == 2) {
				fin.first = i;
				fin.second = j;
				dist[i][j] = 0;
			}

			if (map[i][j] == 0) {
				dist[i][j] = 0;
			}
		}
	}

	queue<pair<int, int>> q;
	q.push(fin);
	
	while (!q.empty()) {
		pair<int, int> now = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {

			pair<int, int> next = make_pair(now.first + dir_y[i], now.second + dir_x[i]);

			if (map[next.first][next.second] == 1
				&& dist[next.first][next.second] == -1) {
				dist[next.first][next.second] = dist[now.first][now.second] + 1;
				q.push(next);
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << dist[i][j] << " ";
		}
		cout << endl;
	}
}