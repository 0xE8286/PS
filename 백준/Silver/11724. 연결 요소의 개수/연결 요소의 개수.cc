#include <iostream>
using namespace std;

#define MAX_N 1001

int N, M;
int ans;
int visit[MAX_N];
int map[MAX_N][MAX_N];

void dfs(int v) {
	visit[v] = 1;
	for (int i = 1; i <= N; i++) {
		if (map[v][i] == 1 && visit[i] == 0) {
			dfs(i);
		}
	}
}

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		map[a][b] = 1;
		map[b][a] = 1;
	}


	for (int i = 1; i <= N; i++) {
		if (visit[i] == 0) {
			dfs(i);
			ans++;
		}
	}

	cout << ans;

	return 0;
}