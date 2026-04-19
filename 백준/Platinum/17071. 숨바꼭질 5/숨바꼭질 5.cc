#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int N, K;
int n[500001][2];
int k[500001];

typedef pair<int, int> pii;

int next(int x, int oper) {
	if (oper == 0) return x - 1;
	if (oper == 1) return x + 1;
	return x * 2;
}

bool isOk(int x) {
	if (x < 0) return false;
	if (x > 500000) return false;
	return true;
}

int main() {

	cin >> N >> K;

	if (N == K) {
		cout << 0;
		return 0;
	}

	memset(n, -1, sizeof(n));
	memset(k, -1, sizeof(k));

	queue<pii> q;
	q.push({ N, 0 });
	n[N][0] = 0;
	
	while (!q.empty()) {
		int cp = q.front().first;
		int ct = q.front().second;
		q.pop();
		
		for (int i = 0; i < 3; i++) {
			int np = next(cp, i);
			int nt = ct + 1;
			
			if (!isOk(np)) continue;
			if (n[np][nt % 2] != -1) continue;

			n[np][nt % 2] = nt;
			q.push({ np, nt });
		}
	}

	int pos = K;
	int time = 0;
	int subin_time;

	while (pos <= 500000) {
		k[pos] = time;
		subin_time = n[pos][time % 2];
		if (subin_time != -1 && subin_time <= time) {
			cout << time;
			return 0;
		}
		time++;
		pos += time;
	}
	cout << -1;
	return 0;
}