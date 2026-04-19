#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

#define MAX 101

int box[MAX][MAX][MAX];
int N, M, H;
int max_depth;
int dx[6] = { 0, 0, 0, 0, -1, 1};
int dy[6] = { 0, 0, -1, 1, 0, 0};
int dz[6] = { -1, 1, 0, 0, 0, 0 };

queue<tuple<int, int, int>> q;

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> M >> N >> H;

	for (int k = 0; k < H; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cin >> box[k][i][j];
				if (box[k][i][j] == 1) {
					q.push(make_tuple(k, i, j));
				}
			}
		}
	}

	tuple<int, int, int> v;

	while (!q.empty()) {
		v = q.front();
		q.pop();

		for (int i = 0; i < 6; i++) {

			int nz = get<0>(v) + dz[i];
			int ny = get<1>(v) + dy[i];
			int nx = get<2>(v) + dx[i];

			if (ny < 0 || nx < 0 || nz < 0 || ny >= N|| nx >= M || nz >= H) continue;

			if (box[nz][ny][nx] == 0) {
				box[nz][ny][nx] = box[get<0>(v)][get<1>(v)][get<2>(v)] + 1;
				q.push(make_tuple(nz, ny, nx));
			}
		}	
	}

	for (int k = 0; k < H; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (box[k][i][j] == 0) {
					cout << -1;
					return 0;
				}
				if (box[k][i][j] > max_depth) {
					max_depth = box[k][i][j];
				}
			}
		}
	}

	cout << max_depth-1;
	return 0;
}