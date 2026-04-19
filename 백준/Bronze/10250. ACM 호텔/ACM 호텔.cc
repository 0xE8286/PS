#include <iostream>

using namespace std;

int T, H, W, N;

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> H >> W >> N;

		int floor = 0;
		int number = 0;

		if (N % H != 0) {
			floor = N % H;
			number = (N / H) + 1;
		}
		else {
			floor = H;
			number = N / H;
		}

		cout << floor;
		if (number < 10)
			cout << 0;
		cout << number << '\n';
	}

	return 0;
}