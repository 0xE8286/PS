#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, K, M;
vector<int> edge[101002];
bool visit[100001];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> K >> M;

	int station;
	for (int tube = 100001; tube <= 100000 + M; tube++) {
		
		for (int i = 0; i < K; i++) {
			cin >> station;
			edge[station].push_back(tube);
			edge[tube].push_back(station);
		}
	}
	
	if (N == 1) {
		cout << 1;
		return 0;
	}

	queue<pair<int, int>> q;
	q.push({ 1, 1 });
	visit[1] = true;

	while (!q.empty()) {
		int curr = q.front().first;
		int depth = q.front().second;
		q.pop();
		
		for (int next : edge[curr]) {
			
			if (next <= 100000) {
				if (!visit[next]) {

					if (next == N) {
						cout << depth + 1;
						return 0;
					}

					q.push({ next, depth + 1 });
					visit[next] = true;
				}
			}

			else {
				q.push({ next, depth });
			}
		}
	}

	cout << -1;
	
	return 0;
}