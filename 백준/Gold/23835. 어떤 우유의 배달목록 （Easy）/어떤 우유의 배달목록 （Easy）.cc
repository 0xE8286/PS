#include <iostream>
#include <vector>
using namespace std;

int N, Q;
vector<int> graph[1001];
int milk[1001];

int deliver(int curr, int end, int cnt, bool* visit) {
	if (curr == end) {
		return cnt;
	}
	for (int next : graph[curr]) {
		if (visit[next] == 0) {
			visit[next] = 1;
			
			int result = deliver(next, end, cnt + 1, visit);
			milk[next] += result;
			
			if (result > 0) {
				return result - 1;
			}
		}
	}
	return 0;
}

int main() {

	cin >> N;
	int a, b;

	for (int i = 0; i < N - 1; i++) {
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	
	cin >> Q;
	int cmd, x;
	for (int i = 0; i < Q; i++) {
		cin >> cmd;
		if (cmd == 1) {
			cin >> a >> b;
			
			bool visit[1001];
			fill(visit, visit + N + 1, false);
			
			visit[a] = true;

			deliver(a, b, 0, visit);
		}
		else {
			cin >> x;
			cout << milk[x] << '\n';
		}
	}

	return 0;
}