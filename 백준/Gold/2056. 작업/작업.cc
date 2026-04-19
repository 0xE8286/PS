#include <iostream>
#include <queue>
using namespace std;

int N, M;
int task[10001];

int indegree[10001];
vector<int> edge[10001];
int sub_time[10001];
queue<pair<int, int>> q;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> task[i];
		cin >> M;

		if (M == 0) {
			q.push({ 0, i });
			sub_time[i] = task[i];
			continue;
		}

		int prv;
		for (int j = 0; j < M; j++) {
			cin >> prv;
			edge[prv].push_back(i);
			indegree[i]++;
		}
	}
	
	while (!q.empty()) {
		int prv = q.front().first;
		int curr = q.front().second;
		q.pop();

		for (int nxt : edge[curr]) {
			sub_time[nxt] = max(sub_time[nxt], sub_time[curr] + task[nxt]);
			if (--indegree[nxt] == 0) {
				q.push({ curr, nxt });
			}
		}
	}

	int ans = 0;
	for (int i = 1; i <= N; i++) {
		ans = max(ans, sub_time[i]);
	}
	cout << ans;

	return 0;
}