#include <iostream>
using namespace std;

int N;
int ans[16];
int result;

int abs(int a) {
	if (a >= 0)
		return a;
	if (a < 0) 
		return a * -1;
	return a;
}

bool isValid(int row) {
	for (int i = 1; i < row; i++) {
		if (ans[i] == ans[row] || abs(ans[i] - ans[row]) == row - i)
			return false;
	}
	return true;
}

void dfs(int cnt) {
	if (cnt == N+1) {
		result++;
		return;
	}
	for (int i = 1; i <= N; i++) {
		ans[cnt] = i;
		if (isValid(cnt)) {
			dfs(cnt + 1);
		}
	}
}

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin >> N ;

	ans[0] = -99;

	dfs(1);

	cout << result;

	return 0;
}