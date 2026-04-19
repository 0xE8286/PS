#include <iostream>
using namespace std;

int main(void) {

	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int num;
	cin >> num;

	int sum = 1;
	int stack = 0;
	
	while(num > sum) {
		sum += (stack * 6);
		stack++;
	}

	if (stack == 0) {
		cout << 1 << endl;
		return 0;
	}
	cout << stack << endl;
	
	return 0;
}