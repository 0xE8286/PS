#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
int small, large;
int indegree[32001];
vector<int> edge[32001];

int main() {

	cin >> N >> M;
	
	for (int i = 0; i < M; i++) {
		cin >> small >> large;
		edge[small].push_back(large);
		indegree[large]++;
	}
	
	queue<int> q;
	vector<int> ans;

	for (int i = 1; i <= N; i++) {
		if (indegree[i] == 0) {
			q.push(i);
		}
	}

	for (int i = 0; i < N; i++) {
		int v = q.front(); q.pop();
		ans.push_back(v);
		
		vector<int> outs = edge[v];
		for (auto i = outs.begin(); i != outs.end(); i++) {
			--indegree[*i];
			if (indegree[*i] == 0) {
				q.push(*i);
			}
		}
	}
	
	for (auto i = ans.begin(); i != ans.end(); i++) {
		cout << *i << ' ';
	}

	return 0;
}