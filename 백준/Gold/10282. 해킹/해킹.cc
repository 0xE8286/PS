#include <iostream>
#include <queue>
using namespace std;

int T;
int N, D, C;
int A, B, S;

typedef pair<int, int> pii;

vector<pii> edges[100001];

int dist[100001];
bool visit[100001];

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> T;
	while (T--) {
	
		cin >> N >> D >> C;
		for (int i = 0; i < D; i++) {
			cin >> A >> B >> S;
			edges[B].push_back({ S, A });
		}

		fill(dist, dist + 100001, 987654321);
		fill(visit, visit + 100001, false);

		priority_queue<pii, vector<pii>, greater<>> pq;

		dist[C] = 0;
		pq.push({ dist[C], C });

		while (!pq.empty()) {
			int curr_node = pq.top().second;
			int curr_cost = pq.top().first;
			pq.pop();

			visit[curr_node] = true;

			for (pii next : edges[curr_node]) {
				int next_node = next.second;
				int next_cost = next.first;

				if (visit[next_node]) continue;
				if (dist[curr_node] + next_cost < dist[next_node]) {
					dist[next_node] = dist[curr_node] + next_cost;
					pq.push({ dist[next_node], next_node });
				}

			}
		}

		int visit_cnt = 0;
		int all_hacked_time = 0;

		for (int i = 1; i <= N; i++) {
			if (visit[i]) {
				visit_cnt++;
				all_hacked_time = max(all_hacked_time, dist[i]);
			}
			edges[i].clear();
		}
		cout << visit_cnt << ' ' << all_hacked_time << '\n';
	}
	return 0;
}