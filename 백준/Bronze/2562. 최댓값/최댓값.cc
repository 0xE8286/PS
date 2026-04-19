#include <iostream>

using namespace std;

int main() {
	int a, b;
	int i = 0;
	int max = 1;
	int max_i = -1;
	
	while (cin >> a) {
		i++;

		if (a > max) {
			max = a;
			max_i = i;
		}
	}
	cout << max << endl;
	cout << max_i << endl;
}