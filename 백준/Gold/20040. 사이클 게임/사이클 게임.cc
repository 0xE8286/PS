#include <iostream>
using namespace std;

int N, M;
int p[500000];

int Find(int n) {
	if (p[n] == -1) return n;
	return p[n] = Find(p[n]);
}
bool Union(int n1, int n2) {
	n1 = Find(n1);
	n2 = Find(n2);
	if (n1 == n2) return 0;
	p[n2] = n1;
	return 1;
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> N >> M;
	for (int i = 0; i < N; i++) p[i] = -1;
	int n1, n2;
	int cnt = 0;
	for (int i = 0; i < M; i++) {
		cin >> n1 >> n2;
		if (!Union(n1, n2)) {
			cout << ++cnt;
			return 0;
		}
		else {
			++cnt;
		}
	}
	cout << 0;
	return 0;
}