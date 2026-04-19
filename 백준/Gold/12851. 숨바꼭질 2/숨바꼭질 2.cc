#include <iostream>
#include <queue>
using namespace std;

int N, K;

int minDepth = 987654321;
int way = 0;
int visit[100001];

typedef pair<int, int> pii;
queue<pii> q;

int isValid(int x) {
	if (x < 0 || x > 100000) return false;
	return true;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;
	
	q.push(pii(N, 0)); 
	visit[N] = 1;
	
	while (!q.empty()) {
		pii now = q.front(); q.pop();
		int x = now.first;
		int d = now.second;

		visit[x] = 1;

		if (x == K && d <= minDepth) {
			visit[x] = 0;
			way++;
			minDepth = d;
			continue;
		}

		if (isValid(x - 1) && visit[x - 1] == 0 && d + 1 <= minDepth) {
			q.push(pii(x - 1, d + 1));
		}
		if (isValid(x + 1) && visit[x + 1] == 0 && d + 1 <= minDepth) {
			q.push(pii(x + 1, d + 1));
		}
		if (isValid(x * 2) && visit[x * 2] == 0 && d + 1 <= minDepth) {
			q.push(pii(x * 2, d + 1));
		}
	}

	cout << minDepth << '\n';
	cout << way << '\n';

	return 0;
}