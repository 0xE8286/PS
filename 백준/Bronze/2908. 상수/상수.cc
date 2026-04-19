#include <iostream>
using namespace std;

int main(void) {
	
	char a[4];
	char b[4];

	int a_num = 0;
	int b_num = 0;

	cin >> a >> b;

	a_num = (a[2] - 48) * 100 + (a[1] - 48) * 10 + (a[0]-48);
	b_num = (b[2] - 48) * 100 + (b[1] - 48) * 10 + (b[0]-48);

	if (a_num > b_num)
		cout << a_num << endl;
	else
		cout << b_num << endl;

	return 0;
}