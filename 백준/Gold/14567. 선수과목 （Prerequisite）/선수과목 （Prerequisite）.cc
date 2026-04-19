#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int indegree[1001];
vector<int> outdegree[1001];
int N, M;
int a, b;
int semester[1001];
typedef pair<int, int> pii;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		indegree[b]++;
		outdegree[a].push_back(b);
	}

	queue<pii> q;

	for (int i = 1; i <= N; i++) {
		if (indegree[i] == 0) {
			q.push(pii(i, 1));
		}
	}

	while (!q.empty()) {
		pii curr = q.front(); q.pop();
		semester[curr.first] = curr.second;
		for (int next : outdegree[curr.first]) {
			if (--indegree[next] == 0) {
				q.push(pii(next, curr.second + 1));
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		cout << semester[i] << ' ';
	}

	return 0;
}