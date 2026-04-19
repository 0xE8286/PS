#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;
int pre, nxt;
int indegree[32001];
vector<int> edge[32001];
vector<int> answer;

int main() {

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> pre >> nxt;
		indegree[nxt]++;
		edge[pre].push_back(nxt);
	}

	priority_queue<int, vector<int>, greater<int>> pq;
	
	for (int i = 1; i <= N; i++) {
		if (indegree[i] == 0) {
			pq.push(i);
		}
	}
	
	while (!pq.empty()) {
		int curr = pq.top(); pq.pop();
		answer.push_back(curr);

		for (int next : edge[curr]) {
			if (--indegree[next] == 0) {
				pq.push(next);
			}
		}
	}

	for (int order : answer) {
		cout << order << ' ';
	}

	return 0;
}