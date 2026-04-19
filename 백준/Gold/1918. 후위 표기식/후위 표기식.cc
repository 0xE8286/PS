#include <iostream>
#include <map>
#include <stack>

using namespace std;
string expr;
stack<char> s;
map<char, int> order;


int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> expr;

	order['('] = 0;
	order[')'] = 0;
	order['+'] = 1;
	order['-'] = 1;
	order['*'] = 2;
	order['/'] = 2;
	

	for (auto x : expr) {
		if (x >= 'A' && x <= 'Z') {
			cout << x;
		}
		else if (x == '(') {
			s.push(x);
		}
		else if (x == ')') {
			while (!s.empty() && s.top() != '(') {
				cout << s.top(); 
				s.pop();
			}
			s.pop();
		}
		else if (x == '+' || x == '-' || x == '*' || x == '/') {
			while (!s.empty() && order[x] <= order[s.top()]) {
				cout << s.top();
				s.pop();
			}
			s.push(x);
		}
	}
	while (!s.empty()) {
		cout << s.top();  
		s.pop();
	}

	return 0;
}