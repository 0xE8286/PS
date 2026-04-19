#include <iostream>
#include <set>

using namespace std;
string input;
set<string> str;

int main() {
	
	cin >> input;
	
	for (int i = 0; i < input.size(); i++) {
		string s;
		for (int j = 0; j < input.size() - i; j++) {
			s.push_back(input[i + j]);
			str.insert(s);
		}
	}

	cout << str.size();

	return 0;
}