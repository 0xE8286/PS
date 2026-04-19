#include <iostream>
using namespace std;

int N, M;
string map[100];
int cnt[100][100];
int dy[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dx[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };

bool isValid(int y, int x) {
	if (y < 0 || y >= N || x < 0 || x >= M) return false;
	return true;
}

void clear() {
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			cnt[y][x] = 0;
		}
	}
}

int main() {

	while (1) {
		cin >> N >> M;
		
		if (N == 0 && M == 0) {
			break;
		}

		for (int i = 0; i < N; i++) {
			cin >> map[i];
		}

		for (int y = 0; y < N; y++) {
			for (int x = 0; x < M; x++) {
				
				if (map[y][x] == '*') {
					for (int i = 0; i < 8; i++) {
						int ny = y + dy[i];
						int nx = x + dx[i];
						if (isValid(ny, nx)) {
							cnt[y + dy[i]][x + dx[i]]++;
						}
					}
				}

			}
		}

		for (int y = 0; y < N; y++) {
			for (int x = 0; x < M; x++) {

				if (map[y][x] == '*') {
					cout << '*';
				}
				else {
					cout << cnt[y][x];
				}
			}
			cout << '\n';
		}

		clear();
	}

	return 0;
}