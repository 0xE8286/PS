#include <iostream>
#include <string>
#include <stack>
using namespace std;

string text;
stack<char> notags;
bool taging = false;

void pop_print() {
	while (!notags.empty()) {
		cout << notags.top();
		notags.pop();
	}
}

int main() {
	
	getline(cin, text);

	for (char c : text) {
		if (c == '<') {
			pop_print();
			taging = true;
			cout << c;
			continue;
		}
		else if (c == '>') {
			taging = false;
			cout << c;
			continue;
		}
		else if (c == ' ') {
			pop_print();
			cout << c;
			continue;
		}

		if (taging) {
			cout << c;
		}
		else {
			notags.push(c);
		}
	}
	pop_print();

	return 0;
}