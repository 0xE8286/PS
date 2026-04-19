#include <iostream>
#include <list>

using namespace std;

int N;
string keylog;

int main() {

	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	
	while (N--) {
		cin >> keylog;

		list<char> passwd;
		auto cursor = passwd.end();

		for (char c : keylog) {
			
			if (c == '<') {
				if (cursor != passwd.begin()) {
					cursor--;
				}
			}
			else if (c == '>') {
				if (cursor != passwd.end()) {
					cursor++;
				}
			}
			else if (c == '-') {
				if (cursor != passwd.begin()) {
					cursor--;
					cursor = passwd.erase(cursor);
				}
			}
			else {
				passwd.insert(cursor, c);
			}	
		}

		for (char c : passwd) {
			cout << c;
		}
		cout << '\n';
	}

	return 0;
}