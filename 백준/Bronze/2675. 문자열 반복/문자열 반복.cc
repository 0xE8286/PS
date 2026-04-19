#include <iostream>
using namespace std;

int main(void) {
	int T;
	cin >> T;
	for (int tc = 0; tc < T; tc++) {
		int n;
		char s[21];

		cin >> n >> s;
		
		int i = 0;
		while (s[i] != '\0') {
			for (int j = 0; j < n; j++) {
				cout << s[i];
			}
			i++;
		}
		cout << "\n";
	}
	
	return 0;
}