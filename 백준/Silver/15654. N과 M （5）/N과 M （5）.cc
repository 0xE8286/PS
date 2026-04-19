#include <iostream>
#include <vector>
#include <map>

using namespace std;

int N, M, input;
map<int, int> number;
vector<int> per;

void dfs(int depth) {
	if (depth == M) {
		for (int i = 0; i < per.size(); i++) {
			cout << per[i] << ' ';
		}
		cout << '\n';
		return;
	}
	for (auto i = number.begin(); i != number.end(); i++) {
		if (i->second == 0) {
			i->second = 1;
			per.push_back(i->first);
			dfs(depth + 1);
			per.pop_back();
			i->second = 0;
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
		number[input] = 0;
	}
	dfs(0);
	return 0;
}