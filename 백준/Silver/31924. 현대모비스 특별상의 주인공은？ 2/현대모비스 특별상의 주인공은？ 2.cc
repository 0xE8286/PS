#include <iostream>
using namespace std;

int N;
int dir_y[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dir_x[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };
char spell[5] = { 'M', 'O', 'B', 'I', 'S' };
string map[100];
int ans;

bool isValid(int y, int x) {
	if (y < 0 || x < 0 || y >= N || x >= N) {
		return false;
	}
	return true;
}

int check(int y, int x, int dir) {
	for (int i = 1; i < 5; i++) {
		int dy = y + (dir_y[dir] * i);
		int dx = x + (dir_x[dir] * i);
		if (!isValid(dy, dx)) {
			return 0;
		}
		if (map[dy][dx] != spell[i]) {
			return 0;
		}
	}
	return 1;
}

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> map[i];
	}

	if (N < 5) {
		cout << 0;
		return 0;
	}

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			
			for (int dir = 0; dir < 8; dir++) {
				if (map[y][x] == spell[0]) {
					ans += check(y, x, dir);
				}
			}
		}
	}
	cout << ans;

	return 0;
}