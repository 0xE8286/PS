#include <iostream>
using namespace std;

int N;
string file[50];

int main() {

	cin >> N;

	string base; int len;

	cin >> base;
	
	if (N == 1) {
		cout << base;
		return 0;
	}

	len = base.size();
	
	for (int i = 0; i < N-1; i++) {
		cin >> file[i];
	}
	
	for (int i = 0; i < len; i++) {
		bool same = true;
		char now;
		
		for (int j = 0; j < N - 1; j++) {
			now = file[j][i];
			if (now != base[i]) {
				same = false;
				break;
			}
		}
		char ans = same ? now : '?';
		cout << ans;
	}

	return 0;
}