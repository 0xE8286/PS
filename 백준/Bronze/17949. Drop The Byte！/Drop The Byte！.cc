#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

string pw, type;
int N, start, len;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> pw >> N;

	while (N--) {
		cin >> type;
		if (type == "char") {
			len = 2;
		}
		else if (type == "int") {
			len = 8;
		}
		else {
			len = 16;
		}
		string sub = pw.substr(start, len);
		cout << strtol(sub.c_str(), NULL, 16) << '\n';
		start += len;
	}
	return 0;
}