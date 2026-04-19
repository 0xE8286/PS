#include <iostream>
using namespace std;

int hansu(int num) {
	if (num < 100) {
		return true;
	}
	int a = 0;
	int b = 0;
	int c = 0;

	a = num / 100;
	b = (num % 100) / 10;
	c = num % 10;

	if (a-b == b-c) {
		return true;
	}
	return false;
}

int main(void) {
	int n;
	cin >> n; 

	int cnt = 0;

	for (int i = 1; i <= n; i++) {
		if (hansu(i))
			cnt++;
	}
	cout << cnt;
	return 0;
}