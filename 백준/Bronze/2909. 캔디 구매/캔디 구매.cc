#include <iostream>
#include <cmath>
using namespace std;

double C;
int K;

int main() {
	cin >> C >> K;

	for (int i = 0; i < K; i++) {
		C /= 10;
	}
	C = round(C);
	for (int i = 0; i < K; i++) {
		C *= 10;
	}
	cout << (long long)C;
	return 0;
}