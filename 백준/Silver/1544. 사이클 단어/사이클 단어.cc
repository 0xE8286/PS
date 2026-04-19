#include <iostream>
#include <unordered_map>

using namespace std;

int N;
string word;
unordered_map<string, bool> words;
int ans;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;

	while (N--) {
		cin >> word;

		if (words[word]) {
			continue;
		}

		ans++;
		for (int i = 0; i < word.size(); i++) {
			string cycle_word;
			for (int j = 0; j < word.size(); j++) {
				cycle_word.push_back(word[(i + j) % word.size()]);
			}
			words[cycle_word] = true;
		}
	}
	cout << ans;

	return 0;
}