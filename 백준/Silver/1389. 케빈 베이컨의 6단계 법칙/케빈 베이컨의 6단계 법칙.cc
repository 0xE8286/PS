#include <iostream>
#include <queue>
using namespace std;

int network[101][101];
int visit[101][101];
int result[101];
queue<int> q;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	int me, you;

	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		cin >> me >> you;
		network[me][you] = 1;
		network[you][me] = 1;
	}
	
	for (int u = 1; u <= 100; u++) {
		int depth = 0;
		q.push(u);

		while (!q.empty()) {
			int curr = q.front();
			q.pop();
			depth = visit[u][curr];

			for (int i = 1; i <= N; i++) {
				if (curr == i || u == i) continue;
				if (network[curr][i] == 1 && visit[u][i] == 0) {
					q.push(i);
					visit[u][i] = depth + 1;
				}
			}
		}
		for (int i = 1; i <= N; i++) {
			result[u] += visit[u][i];
		}
	}
	int min = 2147483647;
	int min_user = -1;
	
	for (int i = 1; i <= N; i++) {
		if (result[i] < min) {
			min = result[i];
			min_user = i;
		}
	}
	
	cout << min_user;

	return 0;
}