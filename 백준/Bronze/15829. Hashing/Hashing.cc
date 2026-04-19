#include <iostream>
using namespace std;

unsigned long long hash_function(const char* str) {
	
	int M = 1234567891;
	unsigned long long R = 1;
	unsigned long long V = 0;

	while (*str) {
		V = (V + (*str - 'a' + 1) * R) % M;
		R = (R * 31) % M;
		str++;
	}
	return V;
}
int main(void) {

	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int len;
	char str[51];

	cin >> len >> str;
	cout << hash_function(str);

	return 0;
}