#include <iostream>	
#include <algorithm>
using namespace std;

typedef long long ll;
int N;
ll tree[20000];

bool isTriangle(ll a, ll b, ll c) {
	if (a == 0 || b == 0 || c == 0) {
		return false;
	}
	if (a + b > c) {
		return true;
	}
	return false;
}

int main() {

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> tree[i];
	}
	sort(tree, tree + N);
	for (int i = 0; i < N - 2; i++) {
		if (isTriangle(tree[i], tree[i + 1], tree[i + 2])) {
			cout << "possible";
			return 0;
		}
	}
	cout << "impossible";
	return 0;
}