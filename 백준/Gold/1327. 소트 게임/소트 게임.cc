#include <iostream>
#include <queue>
#include <unordered_map>
#include <algorithm>

using namespace std;

int N, K;

unordered_map<string, bool> visit;

typedef pair<string, int> e;

int main() {	
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> K;
	
	char c;
	string str;
	string ans;
	
	for (int i = 1; i <= N; i++) {
		cin >> c;
		str.push_back(c);
	}
	
	for (int i = 1; i <= N; i++) {
		ans.push_back(i + '0');
	}

	queue<pair<string, int>> q;

	int ret = -1;
	q.push(e(str, 0));
	visit[str] = true;

	while (!q.empty()) {
		e now = q.front(); q.pop();

		if (now.first == ans) {
			ret = now.second;
			break;
		}

		for (int i = 0; i <= N - K; i++) {
			string next = now.first;
			reverse(&next[i], &next[i + K]);
			
			if (!visit[next]) {
				visit[next] = true;
				q.push(e(next, now.second + 1));
			}
		}
	}
	cout << ret;

	return 0;
}