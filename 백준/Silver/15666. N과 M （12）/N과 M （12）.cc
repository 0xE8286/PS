#include <iostream>
#include <vector>

using namespace std;

int N, M, input;
int number[10001];
vector<int> per;

void dfs(int start, int depth) {
	if (depth == M) {
		for (int i = 0; i < per.size(); i++) {
			cout << per[i] << ' ';
		}
		cout << '\n';
		return;
	}
	for (int i = start; i <= 10000; i++) {
		if (number[i] == 1) {
			per.push_back(i);
			dfs(i, depth + 1);
			per.pop_back();
		}
	}
}

int main() {
	cin >> N >> M;

	cin.tie(NULL);
	cout.tie(NULL);

	ios::sync_with_stdio(false);

	for (int i = 0; i < N; i++) {
		cin >> input;
		number[input] = 1;
	}
	dfs(0, 0);
	return 0;
}