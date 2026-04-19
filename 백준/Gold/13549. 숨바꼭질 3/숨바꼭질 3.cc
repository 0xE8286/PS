#include <iostream>
#include <queue>
using namespace std;

int N, K;
int visit[100001];
int ans;

typedef pair<int, int> pii;
priority_queue<pii, vector<pii>, greater<pii>> q;

int isValid(int x) {
	if (x < 0 || x > 100000) return false;
	return true;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;

	q.push(pii(0, N));
	visit[N] = 1;

	while (!q.empty()) {
		pii now = q.top(); q.pop();
		int d = now.first;
		int x = now.second;
		
		if (x == K) {
			ans = d;
			break;
		}
		if (isValid(x * 2) && visit[x * 2] == 0) {
			q.push(pii(d, x * 2));
			visit[x * 2] = 1;
		}
		if (isValid(x - 1) && visit[x - 1] == 0) {
			q.push(pii(d + 1, x - 1));
			visit[x - 1] = 1;
		}
		if (isValid(x + 1) && visit[x + 1] == 0) {
			q.push(pii(d + 1, x + 1));
			visit[x + 1] = 1;
		}
	}
	cout << ans;
	return 0;
}