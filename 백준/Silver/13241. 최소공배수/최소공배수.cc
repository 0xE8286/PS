#include <iostream>
using namespace std;

typedef long long ll;

ll gcd(ll a, ll b) {
	if (a % b == 0) {
		return b;
	}
	return gcd(b, a % b);
}

int main() {

	ll a;
	ll b;

	cin >> a >> b;
	cout << a*b / gcd(a, b);

	return 0;
}