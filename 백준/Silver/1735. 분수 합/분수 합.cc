#include <iostream>
using namespace std;

int A, B;
int C, D;

int gcd(int a, int b) {
	if (a % b == 0) return b;
	return gcd(b, a % b);
}

int main() {
	cin >> A >> B >> C >> D;

	int aa = (A * D) + (B * C);
	int bb = (B * D);

	int _gcd = gcd(aa, bb);
	cout << aa / _gcd << ' ';
	cout << bb / _gcd;
	
	return 0;
}