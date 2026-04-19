#include <iostream>
#include <map>
#include <vector>
#include <queue>

#define MAX 801
#define INF 2147483647

using namespace std;
typedef pair<int, int> wd;

int N, E;
int A, B;
int source, dest, weight;

map<int, vector<wd>> graph;

int weights[MAX];
int visit[MAX];

priority_queue<wd, vector<wd>, greater<wd>> pq;

void init() {
	for (int i = 1; i <= N; i++) {
		visit[i] = 0;
		weights[i] = INF;
	}
}

void dijkstra(int start) {
	
	init();

	weights[start] = 0;
	pq.push(wd(0, start));

	while (!pq.empty()) {
		wd now = pq.top();
		pq.pop();

		visit[now.second] = 1;

		for (int i = 0; i < graph[now.second].size(); i++) {
			wd next = graph[now.second][i];
			if (visit[next.second] == 0) {
				int new_weight = now.first + next.first;
				if (weights[next.second] > new_weight) {
					weights[next.second] = new_weight;
					next.first = new_weight;
					pq.push(next);
				}
			}
		}
	}
}

int min(int a, int b) {
	if (a < b) {
		return a;
	}
	return b;
}

int main() {

	cin >> N >> E;
	
	for (int i = 0; i < E; i++) {
		cin >> source >> dest >> weight;
		graph[source].push_back(wd(weight, dest));
		graph[dest].push_back(wd(weight, source));
	}

	cin >> A >> B;

	/* 구해야 할 리스트
		1. 1 → A, 1 → B
		2. A → B, A → N
		3. B → A, B → N */

	dijkstra(1);
	if (weights[A] == INF || weights[B] == INF) {
		cout << -1;
		return 0;
	}
	int __1toA = weights[A];
	int __1toB = weights[B];

	dijkstra(A);
	if (weights[B] == INF || weights[N] == INF) {
		cout << -1;
		return 0;
	}
	int __AtoB = weights[B];
	int __AtoN = weights[N];

	
	dijkstra(B);
	if (weights[A] == INF || weights[N] == INF) {
		cout << -1;
		return 0;
	}
	int __BtoA = weights[A];
	int __BtoN = weights[N];

	int __1ABN = __1toA + __AtoB + __BtoN;
	int __1BAN = __1toB + __BtoA + __AtoN;
	
	cout << min(__1ABN, __1BAN);
	return 0;
}