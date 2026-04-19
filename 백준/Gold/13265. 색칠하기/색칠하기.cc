#include <iostream>
#include <queue>
using namespace std;

int T;
int N, M;
int s, e;

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> T;
	while (T--) {
		cin >> N >> M;

		vector<int> graph[1001];

		for (int i = 0; i < M; i++) {
			cin >> s >> e;
			graph[s].push_back(e);
			graph[e].push_back(s);
		}
		
		bool isPossible = true;
		int color[1001] = { 0, };
		queue<int> q;

		for (int i = 1; i <= N && isPossible; i++) {
			if (color[i] != 0) continue;

			color[i] = 1;
			q.push(i);
			
			while (!q.empty() && isPossible) {
				int curr = q.front(); q.pop();
				
				for (int next : graph[curr]) {
					if (color[next] == 0) {
						color[next] = (color[curr] * -1);
						q.push(next);
					}
					else {
						if (color[next] == color[curr]) {
							isPossible = false;
							break;
						}
					}
				}
			}
		}
		if (isPossible) {
			cout << "possible\n";
		}
		else {
			cout << "impossible\n";
		}
	}
	return 0;
}