#include <iostream>
using namespace std;

int N;
int num[13];
int ans[13];

void dfs(int start, int depth) {

	if (depth == 6) {
		for (int i = 0; i < 6; i++) {
			cout << ans[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = start; i < N; i++) {
		ans[depth] = num[i];
		dfs(i + 1, depth + 1);
	}
}

int main() {

	while (true) {
		cin >> N;
		if (N == 0) break;

		for (int i = 0; i < N; i++) {
			cin >> num[i];
		}
		dfs(0, 0);
		cout << '\n';
	}

	return 0;
}