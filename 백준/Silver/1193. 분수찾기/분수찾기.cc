#include <iostream>
using namespace std;

int main(void) {

	int x;
	int sum = 0;
	int n = 0;
	int diff=0;
	
	cin >> x;

	while (sum < x) {
		n++;
		sum = n * (n - 1) / 2;
	}
	
	diff = sum - x;
	if (n % 2 == 0) {
		int mo = n - 1;
		int ja = 1;

		cout << ja+diff << "/" << mo - diff<< endl;
	}
	else {
		int mo = 1;
		int ja = n - 1;
		
		cout << ja - diff << "/" << mo + diff << endl;
	}

	
	return 0;
}