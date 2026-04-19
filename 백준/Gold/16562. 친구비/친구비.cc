#include <iostream>
#include <map>

using namespace std;

int N, M, K;
int v, w;
int p[10001];
int cost[10001];
int min_cost[10001];

int find(int x) {
	if (p[x] < 0) {
		return x;
	} 
	p[x] = find(p[x]);
	return p[x];
}

void merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) {
		return;
	}
	p[b] = a;
	min_cost[a] = min(min_cost[a], min_cost[b]);
}

int main() {

	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++) {
		cin >> cost[i];
		min_cost[i] = cost[i];
		p[i] = -1;
	}
	for (int i = 1; i <= M; i++) {
		cin >> v >> w;
		merge(v, w);
	}

	int sum = 0;

	for (int i = 1; i <= N; i++) {
		if (p[i] == -1) {
			sum += min_cost[i];
		}
	}
	if (sum <= K) {
		cout << sum;
	}
	else {
		cout << "Oh no";
	}

	return 0;
}