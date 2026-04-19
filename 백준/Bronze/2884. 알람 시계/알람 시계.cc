#include <iostream>

using namespace std;

int main() {

	int h, m;
	cin >> h >> m;

	if (m - 45 < 0) {
		h = h - 1;

		if (h < 0) {
			h = 23;
		}

		m = m + 60 - 45;
	}
	else {
		m = m - 45;
	}
	cout << h << " " << m;

	return 0;
}