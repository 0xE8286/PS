#include <iostream>
using namespace std;
int N;

int main() {
	cin >> N;
	string str;

	while (N--) {
		cin >> str;
		cout << str[0] << str[str.size() - 1] << '\n';
	}
	return 0;
}