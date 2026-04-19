#include <iostream>

using namespace std;

int main() {

	int h, m, add_m;
	int hh, mm;

	cin >> h >> m >> add_m;

	hh = h;
	mm = m + add_m;

	if (mm >= 60) {
		hh += mm / 60;
		mm = mm % 60;
	}

	if (hh >= 24) {
		hh %= 24;
	}

	cout << hh << " " << mm;

	return 0;
}