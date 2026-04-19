#include <iostream>
#include <bitset>
using namespace std;

bitset<2 << 24> bits;
int num;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	while (cin >> num) {
		if (!bits[num]) {
			bits[num] = 1;
			cout << num << ' ';
		}
	}
	return 0;
}