#include <iostream>
#include <queue>

using namespace std;

int p[100001];
int N, M;
int A, B, C;

typedef pair<int, pair<int, int>> edge;

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

	priority_queue<edge, vector<edge>, greater<edge>> pq;

	for (int i = 1; i <= M; i++) {
		cin >> A >> B >> C;
		pq.push({ C, { A, B }});
	}

	int sum = 0;
	int cnt = 0;

	while (!pq.empty()) {
		edge e = pq.top(); pq.pop();
		int a = e.second.first;
		int b = e.second.second;
		
		if (Union(a, b)) {
			if (++cnt == N - 1) {
				break;
			}
			sum += e.first;
		}
	}
	cout << sum;

	return 0;
}
