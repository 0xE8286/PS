#include <iostream>
#include <cmath>
using namespace std;

int R, C, T;
int map[50][50];

int dy[4] = { 0, 1, -1, 0 };
int dx[4] = { 1, 0 , 0 , -1 };

pair<int, int> c1;

void print() {
	cout << '\n';
	for (int y = 0; y < R; y++) {
		for (int x = 0; x < C; x++) {
			cout << map[y][x] << ' ';
		}
		cout << '\n';
	}
}

bool isValid(int y, int x) {
	if (y < 0 || x < 0 || y >= R || x >= C) {
		return false;
	}
	return true;
}

void diffuse() {
	int temp[50][50] = { 0, };

	for (int y = 0; y < R; y++) {
		for (int x = 0; x < C; x++) {
			
			int piece = floor(map[y][x] / 5);
			int diffuse_cnt = 0;

			for (int i = 0; i < 4; i++) {
				int yy = y + dy[i];
				int xx = x + dx[i];

				if (isValid(yy, xx) && map[yy][xx] != -1) {
					temp[yy][xx] += piece;
					diffuse_cnt++;
				}
			}
			temp[y][x] += map[y][x] - (piece * diffuse_cnt);
		}
	}

	for (int y = 0; y < R; y++) {
		for (int x = 0; x < C; x++) {
			map[y][x] = temp[y][x];
		}
	}
}

void clean() {
	int temp[50][50] = { 0, };
	
	int cy1 = c1.first;
	int cy2 = cy1 + 1;
	int cx = c1.second;

	for (int i = cx; i < C; i++) {
		if (isValid(cy1, i + 1) && map[cy1][i] != -1) {
			temp[cy1][i + 1] = map[cy1][i];
		}
		if (isValid(cy2, i + 1) && map[cy2][i] != -1) {
			temp[cy2][i + 1] = map[cy2][i];
		}
	}
	
	for (int i = cy1; i > 0; i--) {
		if (isValid(i - 1, C - 1)) {
			temp[i - 1][C - 1] = map[i][C - 1];
		}
	}

	for (int i = cy2; i < R; i++) {
		if (isValid(i + 1, C - 1)) {
			temp[i + 1][C - 1] = map[i][C - 1];
		}
	}

	for (int i = C - 1; i > cx; i--) {
		if (isValid(0, i - 1)) {
			temp[0][i - 1] = map[0][i];
		}
		if (isValid(R - 1, i - 1)) {
			temp[R - 1][i - 1] = map[R - 1][i];
		}
	}

	for (int i = 0; i < cy1; i++) {
		if (isValid(i + 1, 0)) {
			temp[i + 1][0] = map[i][0];
		}
	}

	for (int i = R - 1; i > cy2; i--) {
		if (isValid(i - 1, 0)) {
			temp[i - 1][0] = map[i][0];
		}
	}

	for (int y = 0; y < R; y++) {
		for (int x = 0; x < C; x++) {
			if (y == 0 || x == 0 || y == R - 1 || x == C-1 || y == cy1 || y == cy2) {
				map[y][x] = temp[y][x];
			}
		}
	}
	map[cy1][cx] = -1;
	map[cy2][cx] = -1;
}

int main() {

	cin >> R >> C >> T;
	bool found = false;
	int sum = 0;
	
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> map[i][j];
			
			if (!found && map[i][j] == -1) {
				c1.first = i;
				c1.second = j;
				found = true;
			}

		}
	}

	for (int i = 0; i < T; i++) {
		diffuse();
		clean();
	}

	for (int y = 0; y < R; y++) {
		for (int x = 0; x < C; x++) {
			if (map[y][x] != -1)
				sum += map[y][x];
		}
	}
	cout << sum;

	return 0;
}