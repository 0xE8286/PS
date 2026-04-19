#include <iostream>

using namespace std;

int main() {

	int n;
	cin >> n;
	for (int tc = 0; tc < n; tc++) {
		
		char a[81];
		cin >> a;

		int sum = 0;
		int stack = 0;

		if (a[0] == 'O') {
			sum = 1;
			stack = 1;
		}

		int i = 1;
		
		while (a[i] != '\0') {
			if (a[i] == 'O') {
				stack++;
				sum += stack;
			}
			else {
				stack = 0;
			}
			i++;
		}
		cout << sum << endl;

	}
	return 0;
}