#include <iostream>
using namespace std;

int N;
string passwd;

void tolower(string& str) {
	int diff = ('A' - 'a');
	for (int i = 0; i < str.size(); i++) {
		if (str[i] >= 'A' && str[i] <= 'Z') {
			str[i] = str[i] - diff;
		}
	}
	return;
}

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> passwd;
		tolower(passwd);
		cout << passwd << '\n';
	}
	return 0;
}