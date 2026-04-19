#include <iostream>
using namespace std;

int cnt;
int N, K;
int visit[11];

void comb(int index, int n) {
	if (index == K) {
		cnt++;
		return;
	}
	for (int i = n ; i < N; i++) {
		if (visit[i] != 1) {
			visit[i] = 1;
			comb(index+1, i);
			visit[i] = 0;
		}
	}
}


int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> K;

	comb(0, 0);

	cout << cnt;

	return 0;
}