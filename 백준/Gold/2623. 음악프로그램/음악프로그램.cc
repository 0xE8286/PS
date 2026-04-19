#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;
vector<int> out_edge[1001];
int in_edge_cnt[1001];

int main() {

	cin >> N >> M;
	int from, to, singer;
	
	
	for (int i = 0; i < M; i++) {
		cin >> singer;
		cin >> from;
		
		for (int j = 0; j < singer - 1; j++) {
			cin >> to;
			out_edge[from].push_back(to);
			in_edge_cnt[to]++;
			from = to;
		}
	}

	int start = 0;
	int loop_cnt = 0;
	queue<int> q;
	vector<int> ans;

	for (int i = 1; i <= N; i++) {
		if (in_edge_cnt[i] == 0) {
			q.push(i);
		}
	}

	while (!q.empty()) {
		int v = q.front(); q.pop();
		ans.push_back(v);
		loop_cnt++;
		
		vector<int> outs = out_edge[v];
		for (auto i = outs.begin(); i != outs.end(); i++) {
			--in_edge_cnt[*i];
			if (in_edge_cnt[*i] == 0) {
				q.push(*i);
			}
		}
	}

	if (loop_cnt < N) {
		cout << 0;
		return 0;
	}

	for (auto i = ans.begin(); i != ans.end(); i++) {
		cout << *i << '\n';
	}

	return 0;
}