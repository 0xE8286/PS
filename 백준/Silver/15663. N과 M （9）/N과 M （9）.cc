#include <iostream>
#include <vector>
#include <set>

using namespace std;

int N, M, input;
int number[10001];
vector<int> per;

void dfs(int depth) {
	if (depth == M) {
		for (int i = 0; i < per.size(); i++) {
			cout << per[i] << ' ';
		}
		cout << '\n';
		return;
	}
	for (int i = 0; i <= 10000; i++) {
		if (number[i] > 0) {
			per.push_back(i);
			number[i]--;
			dfs(depth + 1);
			number[i]++;
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
		number[input]++;
	}
	dfs(0);
	return 0;
}