#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

string str;
vector<string> suffix;

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> str;
	int len = str.size();

	for (int i = 0; i < len; i++) {
		suffix.push_back(str.substr(i));
	}
	
	sort(suffix.begin(), suffix.end());
	
	for (auto suf : suffix) {
		cout << suf << '\n';
	}

	return 0;
}