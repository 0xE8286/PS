#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int K, D, A;
	char slash;
	cin >> K >> slash >> D >> slash >> A;

	if (K + A < D || D == 0) {
		cout << "hasu";
	}
	else {
		cout << "gosu";
	}
	return 0;
}