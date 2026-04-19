#include <iostream>

using namespace std;

int main() {
	int a, b;
	int c[3];
	
	cin >> a >> b;
	c[0] = b / 100;
	c[1] = (b / 10) % 10;
	c[2] = b % 10;

	for (int i = 2; i >= 0; i--)
		cout << a* c[i] << endl;
	cout << a * b;
 
	return 0;
}