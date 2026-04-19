#include <iostream>
using namespace std;

long long int n;

int main() {
	long long int sum = 0;

	cin >> n;
	n -= 2;
	for (int i = 1; i <= n; i++) {
		sum += i * (n - i + 1);
	}
	cout << sum << '\n';
	cout << 3;
	return 0;
}