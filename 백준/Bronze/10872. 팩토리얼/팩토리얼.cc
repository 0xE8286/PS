#include <iostream>
using namespace std;

int factorial(int n) {
	if (n <= 1) {
		return 1;
	}
	return factorial(n-1) * n;
}

int main(void) {

	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int num;
	cin >> num;

	cout << factorial(num);
	
	return 0;
}