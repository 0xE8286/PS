#include <iostream>
#include <queue>
using namespace std;

int N, L, R;
int map[100][100];

int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 1, 0, -1, 0 };

typedef pair<int, int> pos;

bool isValid(int y, int x) {
	if (y < 0 || y >= N || x < 0 || x >= N) return false;
	return true;
}

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> L >> R;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}

	int ans = 0;

	while (1) {

		bool update = false;
		bool visit[100][100] = { false, };

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {

				if (visit[i][j]) continue;

				vector<pos> u;
				queue<pos> q;
				
				int cnt = 0;
				int sum = 0;

				q.push({ i, j });
				u.push_back({ i, j });

				visit[i][j] = true;

				while (!q.empty()) {
					int y = q.front().first;
					int x = q.front().second;
					q.pop();
					
					cnt += 1 ;
					sum += map[y][x];

					for (int k = 0; k < 4; k++) {
						int ny = y + dy[k];
						int nx = x + dx[k];

						if (!isValid(ny, nx)) continue;
						if (visit[ny][nx]) continue;
						
						int diff = abs(map[y][x] - map[ny][nx]);
						
						if (diff >= L && diff <= R) {
							q.push({ ny, nx });
							u.push_back({ ny, nx });

							visit[ny][nx] = true;
						}
					}
				}

				if (cnt == 1) {
					continue;
				}

				int people = sum / cnt;
				for (pos v : u) {
					map[v.first][v.second] = people;
				}
				update = true;
			}
		}
		
		if (!update) {
			break;
		}
		else {
			ans++;
		}
	}
	cout << ans;

	return 0;
}