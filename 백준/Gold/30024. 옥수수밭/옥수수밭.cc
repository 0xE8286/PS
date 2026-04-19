#include <iostream>
#include <queue>
using namespace std;

int N, M, K;

int map[1000][1000];

int dy[4] = { 0, -1, 0, 1 };
int dx[4] = { -1, 0, 1, 0 };

typedef pair<int, int> pos;

bool isValid(int y, int x) {
	if (y < 0 || x < 0 || y >= N || x >= M) return false;
	if (map[y][x] == 0)return false;
	return true;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N >> M;
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}
	cin >> K;

	priority_queue<pair<int, pos>> pq;
	
	for (int x = 0; x < M; x++) {
		pq.push({ map[0][x], {0, x} });
		map[0][x] = 0;
	}
	for (int y = 1; y < N; y++) {
		pq.push({ map[y][M - 1], {y, M - 1} });
		map[y][M - 1] = 0;
	}
	for (int x = M - 2; x >= 0; x--) {
		pq.push({ map[N - 1][x], {N - 1, x} });
		map[N - 1][x] = 0;
	}
	for (int y = N - 2; y >= 1; y--) {
		pq.push({ map[y][0], {y, 0} });
		map[y][0] = 0;
	}

	while (K--) {
		
		int value = pq.top().first;
		pos curr = pq.top().second;

		pq.pop();

		cout << curr.first + 1 << ' ' << curr.second + 1 << '\n';


		for (int i = 0; i < 4; i++) {
			
			int ny = curr.first + dy[i];
			int nx = curr.second + dx[i];

			if (isValid(ny, nx)) {
				pq.push({ map[ny][nx], {ny, nx} });
				map[ny][nx] = 0;
			}
		}
	}

	return 0;
}