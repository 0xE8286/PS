#include <iostream>
#include <set>
using namespace std;

typedef pair<int, string> strick;

int N, M;
strick person[200];
set<int> scores;

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		char check; int lrs = 0;
		for (int j = 0; j < M; j++) {
			cin >> check;
			if (check == '.') {
				lrs++;
			} 
			else {
				person[i].first = max(person[i].first, lrs);
				lrs = 0;
			}
		}
		person[i].first = max(person[i].first, lrs);
		scores.insert(person[i].first);
		cin >> person[i].second;
	}

	cout << scores.size() << '\n';
	for (int i = 0; i < N; i++) {
		cout << person[i].first << ' ';
		cout << person[i].second << '\n';
	}

	return 0;
}