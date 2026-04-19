#include<iostream>
using namespace std;

int N, M;
string map[50];
int ans;

bool isValid(int y, int x) {
	if (y < 0 || x < 0 || y >= N || x >= M) {
		return false;
	}
	return true;
}

bool checkRect(int y, int x, int size) {
	if (!isValid(y + size, x + size)) {
		return false;
	}
	int num = map[y][x];
	if (map[y + size][x] != num) return false;
	if (map[y][x + size] != num) return false;
	if (map[y + size][x + size] != num) return false;
	return true;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> map[i];
	}

	int small = (N < M) ? N : M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			
			for (int size = small - 1; size >= 0; size--) {
				if (checkRect(i, j, size)) {
					ans = max(ans, (size+1) * (size+1));
					break;
				}
			}

		}
	}
	cout << ans;

	return 0;
}