#include <iostream>
#include <stack>
using namespace std;

int N;
int cnt;
string word;

int main() {

	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> word;
		stack<char> spell;

		for (int c = 0; c < word.size(); c++) {
			if (spell.empty()) {
				spell.push(word[c]);
				continue;
			}
			if (spell.top() == word[c]) {
				spell.pop();
			}
			else {
				spell.push(word[c]);
			}
		}
		if (spell.empty()) {
			cnt += 1;
			continue;
		}
	}
	cout << cnt;
	return 0;
}