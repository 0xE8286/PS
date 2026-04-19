#include <iostream>
#define MAX_N 26

using namespace std;

int N;
char map[MAX_N][MAX_N];
int town;
int cnt;
int rec[MAX_N*MAX_N];

int dir_y[4] = { 1, -1, 0, 0 };
int dir_x[4] = { 0, 0, -1, 1 };

void dfs(int y, int x) {
	map[y][x] = '0';
	cnt++;
	
	for (int i = 0; i < 4; i++) {
		if (map[y + dir_y[i]][x + dir_x[i]] == '1') {
			dfs(y + dir_y[i], x + dir_x[i]);
		}
	}
}

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> map[i];
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == '1') {
				cnt = 0;
				dfs(i, j);
				town++;
				rec[cnt]++;
			}
		}
	}

	cout << town << '\n';

	for (int i = 0; i <= N * N; i++) {
		for (int j = 0; j < rec[i]; j++) {
			cout << i << '\n';
		}
	}
	return 0;
}