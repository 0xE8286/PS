#include <iostream>
using namespace std;

typedef unsigned long long ull;

ull N, sum;

int main() {

	cin >> N;

	for (int i = 1; i < N; i++) {
		sum += N * i + i;
	}
	cout << sum;

	return 0;
}