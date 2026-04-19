#include <iostream>
using namespace std;

int N, X, Y;
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> X >> Y;
		if (X < Y) {
			cout << "NO BRAINS\n";
		}
		else {
			cout << "MMM BRAINS\n";
		}
	}
	return 0;
}