#include <iostream>
#include <set>
using namespace std;

int N, M;
int cnt;
set<int> a;
set<int> b;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> N >> M;
	
	int x;
	for (int i = 0; i < N; i++) {
		cin >> x;
		a.insert(x);
	}

	for (int i = 0; i < M; i++) {
		cin >> x;
		b.insert(x);
	}

	for (auto i = a.begin(); i != a.end(); i++) {
		if (b.find(*i) == b.end()) cnt++;
	}
	for (auto i = b.begin(); i != b.end(); i++) {
		if (a.find(*i) == a.end()) cnt++;
	}

	cout << cnt;
	
	return 0;
}