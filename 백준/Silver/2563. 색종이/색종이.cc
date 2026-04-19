#include <iostream>
using namespace std;

int N;
int x, y;
int w[101][101];
int ans;

void fill(int x, int y) {
	for (int i = y; i < y + 10; i++) {
		for (int j = x; j < x + 10; j++) {
			w[i][j] = 1;
		}
	}
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> x >> y;
		fill(x, y);
	}
	for (int i = 1; i <= 100; i++) {
		for (int j = 1; j <= 100; j++) {
			if (w[i][j] == 1) ans++;
		}
	}
	
	cout << ans;
	return 0;
}