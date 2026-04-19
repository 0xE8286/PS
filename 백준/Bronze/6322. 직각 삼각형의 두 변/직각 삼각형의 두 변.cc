#include <iostream>
#include <cmath>
using namespace std;

int A, B, C;
int tc;

int main() {

	cout.fixed;
	cout.precision(3);
	cout.setf(ios::fixed);

	cin >> A >> B >> C;

	while (A || B || C) {
		cout << "Triangle #" << ++tc << '\n';

		pair<char, double> ans;

		if (A == -1) {
			int temp = (C * C) - (B * B);
			ans.first = 'a';
			ans.second = temp > 0 ? sqrt(temp) : -1;
		}
		else if (B == -1) {
			int temp = (C * C) - (A * A);
			ans.first = 'b';
			ans.second = temp > 0 ? sqrt(temp) : -1;
		}
		else {
			int temp = (A * A) + (B * B);
			ans.first = 'c';
			ans.second = temp > 0 ? sqrt(temp) : -1;
		}
		if (ans.second <= 0) {
			cout << "Impossible.\n";
		}
		else {
			cout << ans.first << " = " << (double)ans.second << '\n';
		}
		cout << '\n';

		cin >> A >> B >> C;
	}
	return 0;
}