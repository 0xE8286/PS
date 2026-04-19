#include <iostream>
using namespace std;

char trans[36] = {
	'0','1','2','3','4','5','6','7','8','9',
	'A','B','C','D','E','F','G','H','I','J',
	'K','L','M','N','O','P','Q','R','S','T',
	'U','V','W','X','Y','Z'
};

long long int pow(int a, int b) {
	if (b == 0) return 1;
	if (b == 1) return a;
	return a * pow(a, b - 1);
}

int main() {

	int num, a;
	cin >> num >> a;
	
	string answer;
	
	int digit = 0;
	while (pow(a, digit) <= num) {
		digit++;
	}
	digit--;
	
	if (digit < 0) {
		cout << 0;
		return 0;
	}

	while (digit >= 0) {
		int c = trans[num / pow(a, digit)];
		answer.push_back(c);
		num = num % pow(a, digit);
		digit--;
	}
	cout << answer;

	return 0;
}