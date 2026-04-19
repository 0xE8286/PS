#include <iostream>
#include <queue>

#define MAX_POS 200013
using namespace std;

int N, K;
int visit[MAX_POS];
int cnt;
int route[MAX_POS];

void init() {
	for (int i = 0; i < MAX_POS; i++) {
		visit[i] = -1;
		route[i] = -1;
	}
}

bool isValid(int x) {
	if (x > MAX_POS || x < 0) {
		return false;
	}
	return true;
}

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> K;

	queue<pair<int, int>> q;
	q.push({ N, 0 });
	visit[N] = -2;
	init();

	while (!q.empty()) {

		int curr = q.front().first;
		int depth = q.front().second;
		int next;

		q.pop();
		if (curr == K) {
			cnt = depth;
			break;
		}

		for (int i = 1; i <= 3; i++) {
			if (i == 1) next = curr - 1;
			else if (i == 2) next = curr + 1;
			else next = curr * 2;
			
			if (isValid(next) && visit[next] == -1) {
				q.push({ next, depth + 1 });
				visit[next] = curr;
			}
		}		
	}
	
	cout << cnt << '\n';

	int curr = K;
	for (int i = cnt; i >= 0; i--) {
		route[i] = curr;
		curr = visit[curr];
	}
	for (int i = 0; i <= cnt; i++) {
		cout << route[i] << ' ';
	}

	return 0;
}