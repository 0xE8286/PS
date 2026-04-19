#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
int num[7];
vector<int> v;

void dfs(int d) {
	if (d == M) {
		for (auto i = v.begin(); i != v.end(); i++) {
			cout << *i << ' ';
		}
		cout << '\n';
		return;
	}
	for (int i = 0; i < N; i++) {
		v.push_back(num[i]);
		dfs(d + 1);
		v.pop_back();
	}
}

int main() {
	cin >> N >> M;
	
	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}
	sort(num, &num[N]);
	dfs(0);
	
	return 0;
}