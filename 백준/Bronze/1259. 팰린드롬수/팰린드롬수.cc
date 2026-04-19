#include <iostream>
using namespace std;


int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	char num[6];
	bool isOK;
	cin >> num;

	while (num[0] != '0') {
		
		int len = 0; 
		isOK = true;

		while (num[len]) len++;

		for (int i = 0; i < (len / 2); i++) {
			if (num[i] != num[len - i - 1]) {
				isOK = false;
				break;
			}
		}
		if (isOK) cout << "yes\n";
		else cout << "no\n";

		cin >> num;
	}
	return 0;
}