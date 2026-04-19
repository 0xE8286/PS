#include <iostream>
#include <algorithm>
using namespace std;

int X, Y, N;
int main() {
	cin >> X >> Y;
	for (int i = 1; i <= X * Y; i++) {
		if (i % X == 0 && i % Y == 0) {
			cout << 3;
		}
		else if (i % X == 0) {
			cout << 2;
		}
		else if (i % Y == 0) {
			cout << 1;
		}
	}
	return 0;
}