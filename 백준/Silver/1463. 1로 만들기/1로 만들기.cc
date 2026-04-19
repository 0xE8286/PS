#include <iostream>

#define LARGE 987654321

using namespace std;

int N;
int p[1000001];

int main() {
	cin >> N;

	for (int i = 1; i <= N; i++) {
		p[i] = LARGE;
	}

	p[N] = 0;

	for (int i = N; i >= 1; i--) {
		if (i % 3 == 0) {
			p[i / 3] = min(p[i / 3], p[i] + 1);
		}
		if (i % 2 == 0) {
			p[i / 2] = min(p[i / 2], p[i] + 1);
		}
		p[i - 1] = min(p[i - 1], p[i] + 1);
	}

	cout << p[1];
	
	return 0;
}