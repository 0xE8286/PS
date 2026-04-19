#include <iostream>
using namespace std;
int main() {
	int a, b, c;
	cin >> a >> b >> c;
	
	if (a + b + c != 180) {
		cout << "Error";
		return 0;
	}
	if (a == b && b == c && c == a) {
		cout << "Equilateral";
		return 0;
	}
	if (a == b || b == c || c == a) {
		cout << "Isosceles";
		return 0;
	}
	cout << "Scalene";
	return 0;
}