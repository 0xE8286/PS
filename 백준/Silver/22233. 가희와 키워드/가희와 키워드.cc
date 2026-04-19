#include <iostream>
#include <unordered_set>
#include <cstring>
using namespace std;

int N, M;
unordered_set<string> notepad;

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;

	string keyword;
	string posting;
	
	for (int i = 0; i < N; i++) {
		cin >> keyword;
		notepad.insert(keyword);
	}

	for (int i = 0; i < M; i++) {
		cin >> posting;
		
		int start = 0;
		for (int now = 0; now < posting.size(); now++) {
			if (posting[now] == ',') {
				string tag = posting.substr(start, now-start);
				notepad.erase(tag);
				start = now + 1;
			}
		}
		string tag = posting.substr(start, posting.size());
		notepad.erase(tag);

		cout << notepad.size() << '\n';
	}
	

	return 0;
}