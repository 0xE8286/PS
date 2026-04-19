#include <iostream>
#define MAX_N 101

using namespace std;

int N, M;
int pc[MAX_N][MAX_N];
int visited[MAX_N];
int a, b;
int cnt;

void dfs(int curr) {
	visited[curr] = 1;

	for (int i = 1; i <= N; i++) {
		if (pc[curr][i] == 1 && visited[i] == 0) {
			dfs(i);
		}
	}
}

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin >> N >> M;
	
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		pc[a][b] = 1;
		pc[b][a] = 1;
	}

	dfs(1);

	for (int i = 2; i <= N; i++) {
		if (visited[i] == 1) {
			cnt++;
		}
	}
	cout << cnt;

	return 0;
}