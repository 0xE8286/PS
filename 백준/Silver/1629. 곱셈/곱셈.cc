#include <iostream>

using namespace std;
using ll = long long;

ll A, B, C;

int pow(ll num, ll n, ll m) {
	if (n == 1) {
		return num % m;
	}
	ll num2 = pow(num, n / 2, m);
    ll ans = (num2 * num2) % m;
    
	if (n % 2 == 0) {
		return ans;
	}
	return (ans * num) % m;
}

int main() {
	cin >> A >> B >> C;
	cout << pow(A, B, C);
	return 0;
}