#include <iostream>
#include <tuple>
#include <queue>

using namespace std;

typedef tuple<int, int, int> edge;

int V, E;
int x, y, cost;
int p[200001];

void init() {
	for (int i = 0; i < V; i++) {
		p[i] = -1;
	}
}

int find(int v) {
	if (p[v] == -1) {
		return v;
	}
	p[v] = find(p[v]);
	return p[v];
}

bool merge(int v1, int v2) {
	int p1 = find(v1);
	int p2 = find(v2);
	if (p1 == p2) {
		return false;
	}
	p[p2] = p1;
	return true;
}

int main(){

	cin >> V >> E;
	while (V != 0 && E != 0) {
		int sum = 0;
		int min_sum = 0;
		
		int cnt = 0;
		priority_queue<edge, vector<edge>, greater<edge>> pq;
		
		init();

		for (int i = 0; i < E; i++) {
			cin >> x >> y >> cost;
			pq.push(edge(cost, x, y));
			sum += cost;
		}

		while (!pq.empty()) {
			edge e = pq.top();
			pq.pop();
			
			if (merge(get<1>(e), get<2>(e))) {
				min_sum += get<0>(e);
				if (++cnt == V - 1) {
					break;
				}
			}
		}
		cout << sum - min_sum << '\n';
		cin >> V >> E;
	}

	return 0;
}
