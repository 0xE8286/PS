#include <iostream>
#include <vector>

using namespace std;

int N, M;
int ans, root;
int parents[51];

vector<int> children[51];

void erase(int v) {
	for (auto i = children[v].begin(); i != children[v].end(); i++) {
		erase(*i);
		children[*i].clear();
	}
	children[v].clear();
}

void find_leaf(int v) {
	if (children[v].size() == 0) {
		ans++;
		return;
	}
	for (auto i = children[v].begin(); i != children[v].end(); i++) {
		find_leaf(*i);
	}
}

int main() {

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> parents[i];
		children[parents[i]].push_back(i);
		if (parents[i] == -1) root = i;
	}
	cin >> M;
	
	erase(M);
	
	if (M == root) {
		cout << ans;
		return 0;
	}
	
	int parent_v = parents[M];
	for (int i = 0; i < children[parent_v].size(); i++) {
		if (children[parent_v][i] == M) {
			children[parent_v].erase(children[parent_v].begin() + i);
		}
	}
	find_leaf(root);

	cout << ans;
	return 0;
}