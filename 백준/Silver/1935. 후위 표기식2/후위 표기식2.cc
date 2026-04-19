#include <iostream>
#include <stack>
using namespace std;

string expr;
stack<double> s;
int key[26];
int N, num;

int main() {
	cin >> N;
	cin >> expr;
	for (int i = 0; i < N; i++) {
		cin >> key[i];
	}
	for (int i = 0; i < expr.size(); i++) {
		char c = expr[i];
		if (c == '+') {
			double b = s.top(); s.pop();
			double a = s.top(); s.pop();
			s.push(a + b);
		}
		else if (c == '-') {
			double b = s.top(); s.pop();
			double a = s.top(); s.pop();
			s.push(a - b);
		}
		else if (c == '*') {
			double b = s.top(); s.pop();
			double a = s.top(); s.pop();
			s.push(a * b);
		}
		else if (c == '/') {
			double b = s.top(); s.pop();
			double a = s.top(); s.pop();
			s.push(a / b);
		}
		else {
			double d = key[c - 'A'];
			s.push(d);
		}
	}
	cout << fixed;
	cout.precision(2);
	cout << s.top();
	return 0;
}