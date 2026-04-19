#include <iostream>
#include <unordered_map>
#include <queue>

using namespace std;

int to, wating;
string no;
unordered_map<string, int> wating_list;
priority_queue<pair<int, string>, vector<pair<int, string>>, greater<>> pq;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> to >> wating;

	for (int i = 1; i <= wating; i++) {
		cin >> no;
		wating_list[no] = i;
	}

	for (auto i = wating_list.begin(); i != wating_list.end(); i++) {
		pq.push({ i->second, i->first });
	}

	int cnt = 0;

	while (cnt < to && !pq.empty()) {
		cout << pq.top().second << '\n';
		pq.pop();
		cnt++;
	}

	return 0;
}