#include <iostream>
#include <string>
#include <queue>

using namespace std;

typedef pair<int, string> task;
priority_queue<task, vector<task>, greater<>> boj;
priority_queue<task, vector<task>, greater<>> other;

int N;
string memo;

bool isboj(string& str) {
	string startWith = "boj.kr/";
	for (int i = 0; i < 7; i++) {
		if (str[i] != startWith[i]) {
			return false;
		}
	}
	return true;
}

int getno(string& str) {
	string no = str.substr(7, str.size() - 7);
	return stoi(no);
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	cin.ignore();

	for (int i = 0; i < N; i++) {
		getline(cin, memo);

		if (isboj(memo)) {
			boj.push({ getno(memo), memo });
		}
		else {
			other.push({ memo.size(), memo });
		}
	}

	while (!other.empty()) {
		cout << other.top().second << '\n';
		other.pop();
	}
	while (!boj.empty()) {
		cout << boj.top().second << '\n';
		boj.pop();
	}

	return 0;
} 