#include <iostream>
using namespace std;

int main(void) {
	int n;
	int sum=0;
	char a[1000] = { 0, };
	
	cin >> n;
	cin >> a;

	for (int i = 0; i < n; i++) {
		sum += a[i] - 48;
	}
	cout << sum << endl;
}