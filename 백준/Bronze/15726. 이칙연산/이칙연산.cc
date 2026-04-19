#include <iostream>
using namespace std;

int main() {
	double a, b, c;
	cin >> a >> b >> c;
	double d = a * b / c;
	double e = a / b * c;
	
	long long ans = d > e ? d : e;
	cout << ans;

	return 0;
}