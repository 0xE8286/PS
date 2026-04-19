#include <iostream>
#include <map>
#include <vector>
#include <queue>

using namespace std;

int V, E;
int S;
int from, to, weight;

typedef pair<int, int> wt; //weight와 to를 가지는

#define MAX 20001
#define INF 2147483647

vector<wt> gp[MAX]; //index는 from을 의미

priority_queue<wt, vector<wt>, greater<wt>> pq;

int weights[MAX];
int visit[MAX];

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> V >> E;
	cin >> S;

	for (int i = 0; i < E; i++) {
		cin >> from >> to >> weight;
		gp[from].push_back(wt(weight, to));
	}

	for (int i = 1; i <= V; i++) {
		weights[i] = INF;
	}

	weights[S] = 0;
	pq.push(wt(0, S));

	while (!pq.empty()) {
		wt now = pq.top();
		pq.pop();
		
		visit[now.second] = 1;

		for (int i = 0; i < gp[now.second].size(); i++) {

			wt next = gp[now.second][i];

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

	for (int i = 1; i <= V; i++) {
		if (weights[i] == INF) {
			cout << "INF\n";
		}
		else {
			cout << weights[i] << "\n";
		}
	}

	return 0;
}
