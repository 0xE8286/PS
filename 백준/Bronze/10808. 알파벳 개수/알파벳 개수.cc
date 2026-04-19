#include <iostream>
using namespace std;

int arr[26];

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	string str;
	cin >> str;
	for (int i = 0; i < str.size(); i++) {
		arr[str[i] - 'a']++;
	}
	for (int i = 0; i < 26; i++) {
		cout << arr[i];
		if (i != 25) {
			cout << ' ';
		}
	}

	return 0;
}