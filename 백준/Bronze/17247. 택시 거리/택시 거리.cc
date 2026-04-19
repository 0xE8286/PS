#include <iostream>
using namespace std;

typedef pair<int, int> pos;

int N, M, v;
pos p[2];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;

	int f = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> v;
			if (v == 0) continue;
			
			p[f].first = i;
			p[f].second = j;
			f++;
		}
	}

	cout << abs(p[0].first - p[1].first) + abs(p[0].second - p[1].second);

	return 0;
}