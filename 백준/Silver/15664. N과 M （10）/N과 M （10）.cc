#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int num[8];
int visit[8];

void dfs(int start, int depth) {
	if (depth == M) {
		for (int i = 0; i < N; i++) {
			if (visit[i] == 1) {
				cout << num[i] << ' ';
			}
		}
		cout << '\n';
		return;
	}
	int prev = -1;
	for (int i = start; i < N; i++) {
		if (visit[i] == 0 && prev != num[i]) {
			visit[i] = 1;
			prev = num[i];
			dfs(i, depth + 1);
			visit[i] = 0;
		}
	}
}

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}
	sort(num, &num[N]);
	dfs(0, 0);

	return 0;
}