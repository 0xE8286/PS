#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int N;
double x, y;
typedef pair<double, double> star;
typedef pair<int, int> line;
typedef pair<double, line> edge;

star stars[100];
vector<edge> edges;

int p[100];

int find(int x) {
	if (p[x] == -1) {
		return x;
	}
	p[x] = find(p[x]);
	return p[x];
}
bool Union(int x1, int x2) {
	int r1 = find(x1);
	int r2 = find(x2);
	if (r1 == r2) {
		return 0;
	}
	p[r2] = r1;
	return 1;
}

double square(double x) {
	return x * x;
}

double distance(star s1, star s2) {
	return sqrt(square(s1.first - s2.first) + square(s1.second - s2.second));
}

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> x >> y;
		stars[i] = { x, y };
	}

	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			edges.push_back({ distance(stars[i], stars[j]), {i, j} });
		}
	}
	sort(edges.begin(), edges.end());
	
	int cnt = 0;
	double cost = 0;

	for (int i = 0; i < N; i++) {
		p[i] = -1;
	}

	for (edge e : edges) {
		int x1 = e.second.first;
		int x2 = e.second.second;
		if (Union(x1, x2)) {
			cost += e.first;
			if (++cnt == N - 1) {
				break;
			}
		}
	}
	cout << fixed;
	cout.precision(2);
	cout << cost;

	return 0;
}