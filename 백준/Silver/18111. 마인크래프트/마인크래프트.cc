#include <iostream>
using namespace std;

int N, M, B;
int map[500][500];


int get_time(int rm, int add) {
	return (rm * 2) + add;
}

int main(void) {

	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin >> N >> M >> B;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}

	int ans = 2147483647;
	int ans_H = -1;

	for (int H = 256; H >= 0; H--) {

		int rm = 0;
		int add = 0;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {

				int v = map[i][j];

				while (v > H) {
					v--;
					rm++;
				}

				while (v < H) {
					v++;
					add++;
				}
			}
		}

		if (add > B+rm) continue;

		if (get_time(rm, add) < ans) {
			ans = get_time(rm, add);
			ans_H = H;
		}
	}

	cout << ans << " " << ans_H;

	return 0;
}