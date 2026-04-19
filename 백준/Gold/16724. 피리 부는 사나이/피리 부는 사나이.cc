#include <iostream>

using namespace std;

int N, M;
char map[1000][1001];

int cellId[1000][1001];
int p[1000001]; //1000*1000cell
bool visit[1000][1000];

void init() {
	int id = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cellId[i][j] = ++id;
		}
	}
	for (int i = 1; i <= N * M; i++) {
		p[i] = -1;
	}
}
int find(int n) {
	if (p[n] == -1) {
		return n;
	}
	p[n] = find(p[n]);
	return p[n];
}
void merge(int u, int v) {
	u = find(u);
	v = find(v);
	if (u == v) {
		return;
	}
	p[v] = u;
	return;
}

void dfs(int y, int x) {
	char dir = map[y][x];
	int ny = y;
	int nx = x;

	if (dir == 'U') ny--;
	else if (dir == 'D') ny++;
	else if (dir == 'L') nx--;
	else nx++;

	merge(cellId[y][x], cellId[ny][nx]);
	
	if (!visit[ny][nx]) {
		visit[ny][nx] = true;
		dfs(ny, nx);
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> map[i];
	}
	init();
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (!visit[i][j]) {
				visit[i][j] = true;
				dfs(i, j);
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= M * N; i++) {
		if (p[i] == -1) ans++;
	}
	cout << ans;

	return 0;
}