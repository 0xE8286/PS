#include <iostream>
using namespace std;

int main(void) {
	
	char st[16];
	int sum = 0;
	int i = 0;

	cin >> st;
	
	while (st[i] != '\0') {
		if (st[i] == 'A' || st[i] == 'B' || st[i] == 'C')
			sum += 3;
		else if (st[i] == 'D' || st[i] == 'E' || st[i] == 'F')
			sum += 4;
		else if (st[i] == 'G' || st[i] == 'H' || st[i] == 'I')
			sum += 5;
		else if (st[i] == 'J' || st[i] == 'K' || st[i] == 'L')
			sum += 6;
		else if (st[i] == 'M' || st[i] == 'N' || st[i] == 'O')
			sum += 7;
		else if (st[i] == 'P' || st[i] == 'Q' || st[i] == 'R' || st[i] == 'S')
			sum += 8;
		else if (st[i] == 'T' || st[i] == 'U' || st[i] == 'V')
			sum += 9;
		else
			sum += 10;
		i++;
	}
	cout << sum << endl;

	return 0;
}