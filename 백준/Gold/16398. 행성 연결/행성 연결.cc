#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

int N, cost;
int p[1001];

typedef tuple<long long, int, int>edge;
vector<edge> edge_list;

int find(int x) {
	if (p[x] == -1) {
		return x;
	}
	p[x] = find(p[x]);
	return p[x];
}

bool merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) {
		return false;
	}
	p[b] = a;
	return true;
}

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	
	fill(p, p + N + 1, -1);

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> cost;
			if (cost != 0) {
				edge_list.push_back({cost, i , j});
			}
		}
	}

	sort(edge_list.begin(), edge_list.end());

	int cnt = 0;
	long long sum = 0;

	for (auto e : edge_list) {
		bool result = merge(get<1>(e), get<2>(e));
		if (result) {
			sum += get<0>(e);
			if (++cnt == N - 1) {
				break;
			}
		}
	}
	cout << sum;

	return 0;
}