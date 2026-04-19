#include <iostream>
using namespace std;

int N, M;
int r, c, d;
int map[50][50];
int cleaned;

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };

bool isValid(int y, int x) {
	if (y < 0 || y >= N || x < 0 || x >= M) {
		return false;
	}
	return true;
}

bool search() {
	for (int i = 0; i < 4; i++) {
		int y = r + dy[i];
		int x = c + dx[i];
		if (map[y][x] == 0 && isValid(y, x)) {
			return true;
		}
	}
	return false;
}

int main() {

	cin >> N >> M;
	cin >> r >> c >> d;

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			cin >> map[y][x];
		}
	}
	while (true) {
		
		if (map[r][c] == 0) {
			map[r][c] = 2; 
			cleaned++;
			continue;
		}
		if (!search()) {
			int y = r + (dy[d] * -1);
			int x = c + (dx[d] * -1);
			if (map[y][x] != 1 && isValid(y, x)) {
				r = y;
				c = x;
				continue;
			}
			else {
				break;
			}
		}
		else {
			d--;
			if (d < 0) d = 3;

			int y = r + dy[d];
			int x = c + dx[d];
			if (map[y][x] == 0 && isValid(y, x)) {
				r = y;
				c = x;
				continue;
			}
		}
	}
	cout << cleaned;

	return 0;
}