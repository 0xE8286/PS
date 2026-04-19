#include <iostream>
using namespace std;

int main() {
	
	int T;
	cin >> T;
	for (int tc = 0; tc < T; tc++) {
		long long a, b;
		cin >> a >> b;
		cout << a + b << '\n';
	}

	return 0;
}