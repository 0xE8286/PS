#include <iostream>
using namespace std;

int T;
string str;
int callCnt;


int recursion(string& s, int l, int r) {
	callCnt++;
	
	if (l >= r) return 1;
	else if (s[l] != s[r]) return 0;
	else return recursion(s, l + 1, r - 1);
}

int isPalindrome(string& s) {
	return recursion(s, 0, str.size()-1);
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		
		callCnt = 0;

		cin >> str;
		cout << isPalindrome(str) << ' ';
		cout << callCnt << '\n';
	}
	return 0;
}