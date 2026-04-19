#include <iostream>
#include <map>

using namespace std;

int N;
char p, c1, c2;
map<char, pair<char, char>> tree;

void pre(char v) {
	cout << v;
	if (tree[v].first != '.') pre(tree[v].first);
	if (tree[v].second != '.') pre(tree[v].second);
}

void in(char v) {
	if (tree[v].first != '.') in(tree[v].first);
	cout << v;
	if (tree[v].second != '.') in(tree[v].second);
}

void post(char v) {
	if (tree[v].first != '.') post(tree[v].first);
	if (tree[v].second != '.') post(tree[v].second);
	cout << v;
}

int main() {

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> p >> c1 >> c2;
		tree[p] = make_pair(c1, c2);
	}
	pre('A'); cout << endl;
	in('A'); cout << endl;
	post('A'); cout << endl;

	return 0;
}