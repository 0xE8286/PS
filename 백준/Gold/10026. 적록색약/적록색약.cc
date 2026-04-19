#include <iostream>
using namespace std;

char img[101][100];
int visit[100][100];

int N;
int dir_y[4] = { -1, 0, 1, 0 };
int dir_x[4] = { 0, -1, 0, 1 };

int ans_normal;
int ans_visible;

bool isWall(int y, int x) {
	if (y < 0 || x < 0 || y >= N || x >= N) {
		return true;
	}
	return false;
}

void dfs(int y, int x, char color) {
	for (int i = 0; i < 4; i++) {

		int next_y = y + dir_y[i];
		int next_x = x + dir_x[i];

		if (img[next_y][next_x] == color
			&& visit[next_y][next_x] == 0
			&& !isWall(next_y, next_x)) {

			visit[next_y][next_x] = 1;
			dfs(next_y, next_x, color);

		}
	}
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> img[i];
	}

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {

			if (visit[y][x] == 0) {
				ans_normal++;
				dfs(y, x, img[y][x]);
			}
		}
	}

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {

			visit[y][x] = 0;

			if (img[y][x] == 'G') {
				img[y][x] = 'R';
			}
		}
	}


	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {

			if (visit[y][x] == 0) {
				ans_visible++;
				dfs(y, x, img[y][x]);
			}
		}
	}

	cout << ans_normal << " " << ans_visible << endl;


	return 0;
}
