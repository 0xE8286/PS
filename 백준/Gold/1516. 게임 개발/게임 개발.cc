#include <iostream>
#include <queue>
using namespace std;

int N;

int cost[501];

int indegree[501];
vector<int> outEdge[501];
int sum[501];

int main() {

	queue<int> q;
	int base;

	cin >> N;
	
	for (int v = 1; v <= N; v++) {
		cin >> cost[v];
		cin >> base;
		if (base == -1) {
			sum[v] = cost[v];
			q.push(v);
			continue;
		}
		while (base != -1) {
			indegree[v]++;
			outEdge[base].push_back(v);
			cin >> base;
		}
	}

	while (!q.empty()) {
		int v = q.front(); q.pop();
		
		for (auto i : outEdge[v]) {
			indegree[i]--;
			sum[i] = max(sum[i], sum[v] + cost[i]);
			if (indegree[i] == 0) {	
				q.push(i);
			}
		}
	}
	
	for (int i = 1; i <= N; i++) {
		cout << sum[i] << '\n';
	}

	return 0;
}