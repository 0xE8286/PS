#include <iostream>
using namespace std;

typedef long long ll;

ll factorial(ll n) {
	if (n <= 1) return 1;
	return n * factorial(n - 1);
}

int main() {
	ll N;
	cin >> N;
	cout << factorial(N);
	return 0;
}