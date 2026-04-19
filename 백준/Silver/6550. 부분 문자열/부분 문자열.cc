#include <iostream>
using namespace std;

bool comp(string s1, string s2) {
	int i = 0; int j = 0;
	while (i < s1.size() && j < s2.size()) {
		if (s1[i] == s2[j]) i++;
		j++;
	}
	if (i == s1.size()) return true;
	return false;
}

int main() {
	string s, t;

	while (true) {
		cin >> s >> t;
		if (cin.eof() == true) { 
			break; 
		}

		bool ans = comp(s, t);
		if (ans) {
			cout << "Yes\n";
		}
		else {
			cout << "No\n";
		}
	}
	return 0;
}