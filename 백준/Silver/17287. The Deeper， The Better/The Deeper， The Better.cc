#include <iostream>
using namespace std;

int main() {

	string s;
	int score = 0;
	int ans = 0;

	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '[') score += 3;
		else if (s[i] == '{') score += 2;
		else if (s[i] == '(') score += 1;
		else if (s[i] >= '0' && s[i] <= '9') {
			ans = max(ans, score);
		}
		else if (s[i] == ')') score -= 1;
		else if (s[i] == '}') score -= 2;
		else if (s[i] == ']') score -= 3;
	}
	cout << ans;

	return 0;
}