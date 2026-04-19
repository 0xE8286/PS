#include <iostream>
#define MAX_N 11

using namespace std;

int N;
int map[MAX_N][MAX_N];
int visit[MAX_N];
int ans;

void dfs(int start, int step, int now, int cost) {
	if (step == N) {
		if (map[now][start] <= 0) {
			return;
		}
		if (cost + map[now][start] < ans) {
			ans = cost + map[now][start];
		}
		return;
	}
	for (int i = 0; i < N; i++) {
		if (visit[i] == 0 && map[now][i] > 0) {
			visit[i] = 1;
			dfs(start, step + 1, i, cost + map[now][i]);
			visit[i] = 0;
		}
	}
}

void clear_visit() {
	for (int i = 0; i < N; i++) {
		visit[i] = 0;
	}
}

int main(void) {

	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}

	ans = 2147483647;

	for (int i = 0; i < N; i++) {
		visit[i] = 1;
		dfs(i, 1, i, 0);
		clear_visit();
	}

	cout << ans;

	return 0;
}