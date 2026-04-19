#include <iostream>
using namespace std;

int v, max_v, r, c;
int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			cin >> v;
			if (v >= max_v) {
				max_v = v;
				r = i;
				c = j;
			}
		}
	}
	cout << max_v << '\n';
	cout << r << ' ' << c;

	return 0; 
}