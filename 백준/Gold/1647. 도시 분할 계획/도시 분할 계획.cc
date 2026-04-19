#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int p[100001];
int N, M;
int A, B, C;

typedef pair<int, pair<int, int>> edge;

int Find(int v) {
	if (p[v] < 0) {
		return v;
	}
	p[v] = Find(p[v]);
	return p[v];
}

bool Union(int v1, int v2) {
	int r1 = Find(v1);
	int r2 = Find(v2);
	
	if (r1 == r2) {
		return 0;
	}

	if (p[r1] < p[r2]) {
		p[r1] += p[r2];
		p[r2] = r1;
	}
	else {
		p[r2] += p[r1];
		p[r1] = r2;
	}
	return 1;
}

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		p[i] = -1;
	}

	vector<edge> edges;

	for (int i = 1; i <= M; i++) {
		cin >> A >> B >> C;
		edges.push_back({ C, { A, B }});
	}

	int sum = 0;
	int cnt = 0;

	sort(edges.begin(), edges.end());

	for (auto i = edges.begin(); i != edges.end(); i++) {
		int a = i->second.first;
		int b = i->second.second;
		
		if (Union(a, b)) {
			if (++cnt == N - 1) {
				break;
			}
			sum += i->first;
		}
	}
	cout << sum;

	return 0;
}
