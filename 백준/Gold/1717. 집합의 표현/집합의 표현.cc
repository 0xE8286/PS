#include<iostream>
using namespace std;

int p[1000001];
int N, M;
int oper, a, b;

int find(int x) {
	if (p[x] == -1) {
		return x;
	}
	p[x] = find(p[x]);
	return p[x];
}


void merge(int a, int b) {
	int parent_a = find(a);
	int parent_b = find(b);
	if (parent_a == parent_b) {
		return;
	}
	p[parent_b] = parent_a;
}


int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	for (int i = 0; i <= N; i++) {
		p[i] = -1;
	}
	for (int i = 0; i < M; i++) {
		cin >> oper >> a >> b;

		if (oper == 0) {
			merge(a, b);
		}
		else if (oper == 1) {
			if (find(a) == find(b)) {
				cout << "YES\n";
			}
			else {
				cout << "NO\n";
			}
		}
	}
	
	return 0;
}