#include <iostream>
using namespace std;

int square(int n, int x) {
	if (x == 1) {
		return n;
	}
	return n*square(n, x - 1);
}

int main() {
	int N;
	cin >> N; 

	cout << square(2, N);

	return 0;
}