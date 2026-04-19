#include <iostream>

using namespace std;

int R, C;
int dir_y[4] = { -1, 0, 1, 0 };
int dir_x[4] = { 0, 1, 0, -1 };
bool visit[26];
int max_cnt;
string map[20];
 
bool isValid(int y, int x) {
	if (y < 0 || x < 0 || y >= R || x >= C) {
		return false;
	}
	return true;
}
void dfs(int y, int x, int cnt) {
	max_cnt = max(cnt, max_cnt);
	for (int i = 0; i < 4; i++) {
		int dy = y + dir_y[i];
		int dx = x + dir_x[i];
		if (isValid(dy, dx) && visit[map[dy][dx] - 'A'] == false) {
			visit[map[dy][dx] - 'A'] = true;
			dfs(dy, dx, cnt + 1);
			visit[map[dy][dx] - 'A'] = false;
		}
	}
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		cin >> map[i];
	}
	visit[map[0][0] - 'A'] = true;
	dfs(0, 0, 1);
	cout << max_cnt;
	return 0;
}