#include <iostream>
#include <queue>
#define LARGE 987654321

using namespace std;

struct status {
	int y;
	int x;
	int dist;
	bool used;
};

char map[1001][1001];
int visit_used[1001][1001];
int visit[1001][1001];
int N, M;
int ans = LARGE;
int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

bool isWall(int y, int x) {
	if (y < 0 || y >= N || x < 0 || x >= M) return true;
	return false;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	for (int y = 0; y < N; y++) {
		cin >> map[y];
	}

	queue<status> q;
	status start;
	start.y = 0; start.x = 0;
	start.dist = 0; start.used = false;

	visit[0][0] = 0;
	q.push(start);

	while (!q.empty()) {
		status now = q.front(); q.pop();
		if (now.y == N - 1 && now.x == M - 1) {
			if (now.dist < ans) ans = now.dist;
		}
		for (int i = 0; i < 4; i++) {
			int nexty = now.y + dy[i];
			int nextx = now.x + dx[i];
			if (!isWall(nexty, nextx)) {
				if (map[nexty][nextx] == '0') {
					status next;
					next.y = nexty;
					next.x = nextx;
					next.dist = now.dist + 1;
					next.used = now.used;
					if (next.used) {
						if (visit_used[nexty][nextx] == 0) {
							visit_used[nexty][nextx] = 1;
							q.push(next);
						}
					}
					else {
						if (visit[nexty][nextx] == 0) {
							visit[nexty][nextx] = 1;
							q.push(next);
						}
					}
				}
				else {
					if (now.used == false) {
						status next;
						next.y = nexty;
						next.x = nextx;
						next.dist = now.dist + 1;
						next.used = true;
						visit_used[nexty][nextx] = 1;
						q.push(next);
					}
				}
			}
		}
	}
	if (ans == LARGE) {
		cout << -1;
	}
	else {
		cout << ans + 1;
	}

	return 0;
}