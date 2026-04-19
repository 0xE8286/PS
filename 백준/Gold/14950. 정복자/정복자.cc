#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, T;
int A, B, C;

typedef pair<int, int> line;
typedef pair<int, line> edge ;

int p[10001];
int sum, increse, cnt;
vector<edge> roads;

int _find(int n) {
	if (p[n] < 0) {
		return n;
	}
	p[n] = _find(p[n]);
	return p[n];
}


bool _union(int a, int b) {
	int r1 = _find(a);
	int r2 = _find(b);

	if (r1 == r2) {
		return false;
	}
	
	p[r1] = r2;
	return true;
}


int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M >> T;

	for (int i = 1; i <= N; i++) {
		p[i] = -1;
	}

	for (int i = 0; i < M; i++) {
		cin >> A >> B >> C;
		roads.push_back({ C, {A, B} });
	}

	sort(roads.begin(), roads.end());

	for (auto road : roads) {
		int cost = road.first;
		line dir = road.second;
		
		if (!_union(dir.first, dir.second)) {
			continue;
		}
		sum += cost + increse;
		increse += T;
		if (++cnt == N - 1) {
			break;
		}
	}
	cout << sum;

	return 0;
}