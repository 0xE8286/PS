#include <iostream>

using namespace std;

int A, B, C;

long long pow(int a, int b, int c) {
	if (b == 1) {
		return a;
	}
	else {
		long long temp = pow(a, b / 2, c);
		long long ans = (temp * temp) % c;
		
		if (b % 2 == 0)
			return ans;
		else
			return (ans * a) % c;
	}
}

int main(void) {

	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> A >> B >> C;

	cout << pow(A % C, B, C);

	return 0;
}