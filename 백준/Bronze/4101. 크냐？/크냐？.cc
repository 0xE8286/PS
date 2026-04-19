#include <iostream>
using namespace std;

int main() {
	int A, B;
	cin >> A >> B;
	while (!(A == 0 && B == 0)) {
		if (A > B) cout << "Yes\n";
		else cout << "No\n";
		cin >> A >> B;
	}
	return 0;
}