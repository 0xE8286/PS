#include <iostream>
using namespace std;

int save[51][51][51];
int a, b, c;

int w(int a, int b, int c) {
	if (a <= 0 or b <= 0 or c <= 0)
		return 1;

	if (a > 20 or b > 20 or c > 20)
		return w(20, 20, 20);

	if (save[a][b][c] != 0)
		return save[a][b][c];

	if (a < b && b < c) {
		save[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
		return save[a][b][c];
	}

	save[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
	return save[a][b][c];

}

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	while (true) {
		cin >> a >> b >> c;
		if (a == -1 && b == -1 && c == -1)
			break;

		cout << "w(" << a << ", " << b << ", " << c << ") = " << w(a, b, c) << "\n";
	}
		return 0;
}