#include <iostream>
using namespace std;

int fibo(int n) {
	if (n == 0 || n ==1) {
		return n;
	}
	else if (n == 2) {
		return 1;
	}
	return fibo(n-1) + fibo(n-2);
}

int main(void) {

	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int num;
	cin >> num;

	cout << fibo(num);
	
	return 0;
}