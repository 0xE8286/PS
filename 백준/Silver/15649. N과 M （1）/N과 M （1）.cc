#include <iostream>
using namespace std;

int N, M;
int ans[9];
int visit[9];

void dfs(int cnt) {
	if (cnt == M) {
		for (int i = 0; i < M; i++) {
			cout << ans[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = 1; i <= N; i++) {
		if (visit[i] != 1) {
			visit[i] = 1;
			ans[cnt] = i;
			dfs(cnt + 1);
			visit[i] = 0;
		}
	}
}

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin >> N >> M;

	dfs(0);

	return 0;
}