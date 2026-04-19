#include <iostream>
using namespace std;

int gcd(int a, int b) {
	int r = a % b;
	if (r == 0) {
		return b;
	}
	return gcd(b, r);
}
int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int a, b;
	int gcd_num; 

	cin >> a >> b;
	
	if (a > b) {
		gcd_num = gcd(a, b);
	}
	else {
		gcd_num = gcd(b, a);
	}

	cout << gcd_num << "\n" << a * b / gcd_num;

	return 0;
}