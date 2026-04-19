#include <iostream>
using namespace std;

int gcd(int a, int b) {
	while (b != 0) {
		int mod = a % b;
		a = b;
		b = mod;
	}
	return a;
}

int lcm(int a, int b) {
	return a * b / gcd(a, b);
}


int main() {

	int T;
	int M, N, X, Y;
	cin >> T;
	for (int tc = 0; tc < T; tc++) {
		cin >> M >> N >> X >> Y;
		
		X = X - 1;
		Y = Y - 1;
		
		bool found = false;
		int i = 0;
	
		for (i = X; i <= (N * M); i += M) {
			if (i % N == Y) {
				found = true;
				break;
			}
		}

		if (found) {
			cout << i + 1 << '\n';
		}
		else {
			cout << -1 << '\n';
		}
	}

	return 0;
}