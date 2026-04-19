#include <iostream>

using namespace std;

int _abs(int a) {
	if (a < 0) {
		return a * -1;
	}
	return a;
}

int main(void) {

	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int flow;
	int curr;
	int prev = 0;

	for (int i = 0; i < 8; i++) {
		cin >> curr;
		if (i == 0) {
			if (curr == 1) {
				flow = 1;
			}
			else if (curr == 8) {
				flow = -1;
			}
			else {
				flow = 0; 
				break;
			}
		}
		else {
			if (_abs(prev - curr) > 1) {
				flow = 0;
				break;
			}
		}
		prev = curr;
	}

	if (flow == 1) cout << "ascending";
	else if (flow == -1) cout << "descending";
	else cout << "mixed";

	return 0;
}