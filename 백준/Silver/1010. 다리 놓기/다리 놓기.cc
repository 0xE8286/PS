#include <iostream>
using namespace std;


typedef long long ll;

int T;
ll W, E;

ll factorial(ll x, ll cnt) {
	if (x <= 1 || cnt == 0) return 1;
	return x * factorial(x - 1, cnt - 1);
}

int main() {
	cin >> T;
	for (int tc = 0; tc < T; tc++) {
		cin >> W >> E;
		W = min(W, E - W);
		cout << factorial(E, W) / factorial(W, W) << '\n';
	}
	return 0;
}