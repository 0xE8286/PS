#include <iostream>
#include <cmath>
using namespace std;

int T;
int x, y;

int square(int x) {
	return x * x;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> x >> y;
		int diff = y - x;
		int root = sqrt(diff);
		int ans = 2 * root - 1;

		if (diff == square(root)) {
			cout << ans;
		}
		else if (diff <= square(root) + root) {
			cout << ans + 1;
		}
		else {
			cout << ans + 2;
		}
		cout << '\n';
	}
	return 0;
}