#include <iostream>
#define pi 3.141592
using namespace std;

int w, r;

int main() {

	cin >> w >> r;

	double c = (2 * w);
	double ab = 2 * pi * r;

	cout.fixed;
	cout.precision(8);

	cout << ab + c;

	return 0;
}