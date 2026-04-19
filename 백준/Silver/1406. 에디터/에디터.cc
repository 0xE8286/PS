#include <iostream>
#include <list>
using namespace std;

string str;
list<char> editor;
int N;

void print() {
	for (auto i = editor.begin(); i != editor.end(); i++) {
		cout << *i;
	}
	cout << '\n';
}

int main() {
	cin >> str;
	
	for (int i = 0; i < str.size(); i++) {
		editor.push_back(str[i]);
	}
	
	auto cursor = editor.end();
	
	cin >> N;

	char cmd, param;

	for (int i = 0; i < N; i++) {
		cin >> cmd;
		if (cmd == 'L') {
			if (cursor == editor.begin()) continue;
			cursor--;
		}
		else if (cmd == 'D') {
			if (cursor == editor.end()) continue;
			cursor++;
		}
		else if (cmd == 'B') {
			if (cursor == editor.begin()) continue;
			cursor--;
			cursor = editor.erase(cursor);
		}
		else if (cmd == 'P') {
			cin >> param;
			editor.insert(cursor, param);
		}
	}

	print();

	return 0;
}