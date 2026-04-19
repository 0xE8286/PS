#include <iostream>
#include <cmath>
using namespace std;

int N;
int x, y;
int min_x = 10001;
int min_y = 10001;
int max_x = -10001;
int max_y = -10001;

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> x >> y;
		min_x = min(min_x, x);
		max_x = max(max_x, x);

		min_y = min(min_y, y);
		max_y = max(max_y, y);
	}
	cout << abs(min_x - max_x) * abs(min_y - max_y);
	return 0;
}