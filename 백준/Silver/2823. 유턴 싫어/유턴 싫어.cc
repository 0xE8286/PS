#include <iostream>
using namespace std;

int R, C;
char map[11][11];

int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 1, 0, -1, 0 };

bool hasUtern;

bool isValid(int y, int x) {
	if (y < 0 || y >= R || x < 0 || x >= C) return false;
	return true;
}

int main() {

	cin >> R >> C;

	for (int i = 0; i < R; i++) {
		cin >> map[i];
	}

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (map[i][j] == 'X') continue;

			int cnt = 0;

			for (int k = 0; k < 4; k++) {
				int y = i + dy[k];
				int x = j + dx[k];
				
				if (!isValid(y, x)) cnt++;
				if (map[y][x] == 'X') cnt++;
			}

			if (cnt >= 3) hasUtern = true;
			if (hasUtern) break;
		}
		if (hasUtern) break;
	}

	cout << hasUtern;

	return 0;
}