#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int p[1001];
int N, M;
typedef pair<int, int> line;
typedef pair<int, line> edge;

int Find(int v) {
	if (p[v] == -1) {
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
	p[r2] = r1;
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

	int cost, start, end;
	vector<edge> edges;
	for (int i = 0; i < M; i++) {
		cin >> start >> end >> cost;
		edges.push_back({ cost, {start, end} });
	}
	sort(edges.begin(), edges.end());
	
	int sum = 0;
	int cnt = 0;
	
	for (auto i = edges.begin(); i != edges.end(); i++) {
		int s = i->second.first;
		int e = i->second.second;
		if (Union(s, e)) {
			sum += i->first;
			if (++cnt == N - 1) {
				break;
			}
		}
	}
	cout << sum;

	return 0;
}