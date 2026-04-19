#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> pos;
typedef pair<double, pair<int, int>> edge;

int N, M;
int x, y;
int cnt;
double cost;
int p[1001];
pos god[1001];

int find(int x) {
	if (p[x] == 0) {
		return x;
	}
	p[x] = find(p[x]);
	return p[x];
}
int Union(int x1, int x2) {
	x1 = find(x1);
	x2 = find(x2);
	if (x1 == x2) {
		return 0;
	}
	p[x2] = x1;
	return 1;
}
double square(double x) {
	return x * x;
}
double distance(pos g1, pos g2) {
	return sqrt(square(g1.first-g2.first) + square(g1.second-g2.second));
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> x >> y;
		god[i] = { x, y };
	}

	for (int i = 1; i <= M; i++) {
		cin >> x >> y;
		if (Union(x, y)) cnt++;
	}
	
	vector<edge> v;
	
	for (int i = 1; i <= N; i++) {
		for (int j = i; j <= N; j++) {
			if (i == j) continue;
			v.push_back({ distance(god[i], god[j]), {i, j} });
		}
	}
	sort(v.begin(), v.end());



	for (edge e : v) {
		if (Union(e.second.first, e.second.second)) {
			cost += e.first;
			if (++cnt == N - 1) break;
		}
	}
	cout << fixed;
	cout.precision(2);

	cout << cost;

	return 0;
}