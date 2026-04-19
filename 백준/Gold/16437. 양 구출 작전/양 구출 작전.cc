#include <iostream>
#include <vector>

using namespace std;

struct v {
	int sheep;
	int wolf;
	int parent;
	vector<int> children;
};
v vertexx[123457];

int N;
long long ans;

long long dfs(v now) {
	long long survived = 0;
	for (int i = 0; i < now.children.size(); i++) {
		v next = vertexx[now.children[i]];
		survived += dfs(next);
	}
	long long result = (now.sheep + survived) - now.wolf;
	if (result < 0) {
		return 0;
	}
	return result;
}

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	
	char type[2];
	int cnt, edge;

	for (int i = 2; i <= N; i++) {
		cin >> type >> cnt >> edge;
		if (type[0] == 'S') vertexx[i].sheep = cnt;
		else vertexx[i].wolf = cnt;
		vertexx[i].parent = edge;
		vertexx[edge].children.push_back(i);
	}
	
	cout << dfs(vertexx[1]);

	return 0;
}