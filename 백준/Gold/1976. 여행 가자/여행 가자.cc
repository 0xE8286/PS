#include <iostream>
using namespace std;

int graph[201][201];
int p[201];

int N, M;

void init() {
	for (int i = 0; i <= N; i++) {
		p[i] = -1;
	}
}

int find(int x) {
	if (p[x] == -1) {
		return x;
	}
	p[x] = find(p[x]);
	return p[x];
}

void uni0n(int a, int b) {
	int pa = find(a);
	int pb = find(b);
	if (pa == pb) return;
	
	p[pb] = pa;
}

int main() {
	cin >> N >> M;
	
	init();
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> graph[i][j];
			if (graph[i][j] == 1) {
				uni0n(i, j);
			}
		}
	}
	
	bool isAble = true;
	int city;
	cin >> city;

	int root = find(city);
	
	for (int i = 2; i <= M; i++) {
		cin >> city;
		if (root != find(city)) {
			isAble = false;
			break;
		}
	}

	if (isAble) {
		cout << "YES\n";
	}
	else {
		cout << "NO\n";
	}

	return 0;
}