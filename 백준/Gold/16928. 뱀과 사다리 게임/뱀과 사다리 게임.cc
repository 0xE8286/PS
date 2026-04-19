#include <iostream>
#include <map>
#include <queue>

using namespace std;

int N, M;
int x, y, u, v;
int ans;
map<int, int> sadari;
map<int, int> baem;
int visit[101];

typedef pair<int, int> pii;

int main() {

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> x >> y;
		sadari[x] = y;
	}
	for (int i = 0; i < M; i++) {
		cin >> u >> v;
		baem[u] = v;
	}

	visit[0] = 1;
	queue<pii> q;
	q.push(pii(0, 1));

	while (!q.empty()) {
		int now_d = q.front().first;
		int now_x = q.front().second; 
		q.pop();

		if (sadari.find(now_x) != sadari.end()) {
			now_x = sadari[now_x];
		}
		else if (baem.find(now_x) != baem.end()) {
			now_x = baem[now_x];
		}
		if (now_x == 100) {
			ans = now_d;
			break;
		} 
		for (int i = 1; i <= 6; i++) {
			int next_x = now_x + i;
			if (visit[next_x] == 0) {
				visit[next_x] = 1;
				q.push(pii(now_d + 1, next_x));
			}
		}
	}
	cout << ans;
	return 0;
}