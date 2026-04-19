#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

int N, cnt;
unordered_set<string> emoticon;

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> N;
	string user;
	
	for (int i = 0; i < N; i++) {
		cin >> user;
		if (user == "ENTER") {
			emoticon.erase(emoticon.begin(), emoticon.end());
		}
		else {
			if (emoticon.find(user) == emoticon.end()) {
				emoticon.insert(user);
				cnt++;
			}
		}
	}
	
	cout << cnt;

	return 0;
}