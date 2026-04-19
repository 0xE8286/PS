#include <iostream>
using namespace std;

int main() {
	int xx, yy;
	int a, b, c, d, e, f;
	bool find = false;
	cin >> a >> b >> c >> d >> e >> f;
	for (int x = -999; x <= 999; x++) {
		for (int y = -999; y <= 999; y++) {
			if (a* x + b * y == c &&
				d * x + e * y == f) {
				xx = x;
				yy = y;
				find = true;
				break;
			}
		}
		if (find == true) {
			break;
		}
	}

	cout << xx << ' ' << yy;

	return 0;
}