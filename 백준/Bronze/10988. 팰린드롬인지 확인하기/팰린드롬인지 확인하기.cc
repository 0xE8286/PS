#include <iostream>
using namespace std;

int main() {
	
	string word;
	cin >> word;

	int n = word.size();
	int ans = 1;
	
	for (int i = 0; i < n / 2; i++) {
		if (word[i] != word[n - i - 1]) {
			ans = 0;
		}
	}
	cout << ans;

	return 0;
}