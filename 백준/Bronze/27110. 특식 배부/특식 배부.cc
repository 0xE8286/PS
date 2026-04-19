#include <iostream>
using namespace std;

int N, A, B, C;

int main() {

	cin >> N >> A >> B >> C;

	A = N > A ? A : N;
	B = N > B ? B : N;
	C = N > C ? C : N;

	cout << A + B + C;

	return 0;
}