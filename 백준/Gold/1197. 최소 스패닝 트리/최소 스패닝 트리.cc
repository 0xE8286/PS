#include <iostream>
#include <tuple>
#include <queue>

using namespace std;

typedef tuple<int, int, int> edge;
int p[10000];
int V, E;
int A, B, C;

int find(int v) {
	if (p[v] == -1) {
		return v;
	}
	p[v] = find(p[v]);
	return p[v];
}

bool merge(int v1, int v2) {
	int s1 = find(v1);
	int s2 = find(v2);
	if (s1 == s2) {
		return false;
	}
	p[s2] = s1;
	return true;
}

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> V >> E;
	for (int i = 1; i <= V; i++) {
		p[i] = -1;
	}
	priority_queue<edge, vector<edge>, greater<edge>> pq;
	
	long long int sum = 0;
	int cnt = 0;
	
	for (int i = 0; i < E; i++) {
		cin >> A >> B >> C;
		pq.push(edge(C, A, B));
	}

	while (!pq.empty()) {
		edge e = pq.top();
		pq.pop();

		bool result = merge(get<1>(e), get<2>(e));
		if (result) {
			sum += get<0>(e);
			if (++cnt == V - 1) {
				break;
			}
		}
	}

	cout << sum;
	return 0;
}