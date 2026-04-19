#include<iostream>
using namespace std;

int a, b;
int main() {
	cin >> a >> b;
	double musi = a * (b*0.01);
	if (a - musi >= 100) {
		cout << 0;
	}
	else {
		cout << 1;
	}
	return 0;
}