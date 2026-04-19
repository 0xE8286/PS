#include <iostream>
using namespace std;

int N;
int r, c;
int cnt;
int result;

int pow(int x, int n) {
	if (n == 1) return x;
	return x * pow(x, n - 1);
}

void z(int y, int x, int n) {
	if (r == y && c == x) {
		result = cnt;
		return;
	}
	if (r < y || r >= y+n || c < x || c >= x+n) {
		cnt += n * n;
		return;
	}
	int piece = n / 2;
	z(y, x, piece);
	z(y, x + piece, piece);
	z(y + piece, x, piece);
	z(y + piece, x + piece, piece);
}

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> r >> c;
	z(0, 0, pow(2, N));
	cout << result;

	return 0;
}