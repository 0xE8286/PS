#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

string str;
string bomb;
stack<char> mystr;


int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> str >> bomb;

	for (char c : str) {
		mystr.push(c);
		
		if (c == bomb.back() && mystr.size() >= bomb.size()) {
			stack<char> temp;
			for (auto i = bomb.rbegin(); i != bomb.rend(); i++) {
				if (mystr.top() == *i) {
					temp.push(mystr.top());
					mystr.pop();
					continue;
				}
				while (!temp.empty()) {
					mystr.push(temp.top());
					temp.pop();
				}
				break;
			}
		}
	}
	
	if (mystr.empty()) {
		cout << "FRULA";
		return 0;
	}
	
	stack<char> ans;
	
	while (!mystr.empty()) {
		ans.push(mystr.top());
		mystr.pop();
	}
	
	while (!ans.empty()) {
		cout << ans.top();
		ans.pop();
	}
	return 0;
}