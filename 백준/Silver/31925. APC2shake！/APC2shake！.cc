#include <iostream>
#include <map>
#include <queue>

using namespace std;

int N;
map<int, string> participants;
priority_queue<string, vector<string>, greater<string>> candidates;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;

	string name;
	string isJaehak;
	string isWinner;
	int shakeRank;
	int	apcRank;

	for (int i = 0; i < N; i++) {
		cin >> name >> isJaehak >> isWinner >> shakeRank >> apcRank;
		if (isJaehak == "hewhak") continue;
		if (isWinner == "winner") continue;
		if (shakeRank >= 1 && shakeRank <= 3) continue;
		participants[apcRank] = name;
	}

	for (auto parti : participants) {
		candidates.push(parti.second);
		if (candidates.size() == 10) {
			break;
		}
	}

	cout << candidates.size() << '\n';
	while (!candidates.empty()) {
		cout << candidates.top() << '\n';
		candidates.pop();
	}

	return 0;
}