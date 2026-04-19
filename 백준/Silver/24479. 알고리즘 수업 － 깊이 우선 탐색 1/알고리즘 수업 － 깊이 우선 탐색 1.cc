#include <iostream>
#include <set>

using namespace std;

int N, M, S;
set<int> graph[100001];
int visit[100001];
int cnt;

void dfs(int curr) {
	for (int next : graph[curr]) {
		if (visit[next] == 0) {
			visit[next] = ++cnt;
			dfs(next);
		}
	}
}

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M >> S;

	int from, to;

	for (int i = 0; i < M; i++) {
		cin >> from >> to;
		graph[from].insert(to);
		graph[to].insert(from);
	}
	
	visit[S] = ++cnt;
	dfs(S);

	for (int i = 1; i <= N; i++) {
		cout << visit[i] << '\n';
	}

	return 0;
}