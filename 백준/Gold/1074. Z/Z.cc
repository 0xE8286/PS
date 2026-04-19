#include <iostream>
#include <cmath>
using namespace std;

int N;
int R, C;
int cnt;
int result;

void z(int y, int x, int n) {
	if (y == R && x == C) {
		result = cnt;
		return;
	}
	if (y > R || y + n <= R || x > C || x + n <= C) {
		cnt += n * n;
		return;
	}
	int half = n / 2;
	z(y, x, half);
	z(y, x + half, half);
	z(y + half, x, half);
	z(y + half, x + half, half);
}

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> R >> C;
	z(0, 0, pow(2, N));
	cout << result;

	return 0;
}