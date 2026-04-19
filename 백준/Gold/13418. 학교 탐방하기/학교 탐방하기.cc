#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
int a, b, c;
int min_score, max_score;
int p[10001];

typedef pair<int, int> pii;
vector<pair<int, pii>> edge;

void _init() {
	for (int i = 0; i <= N; i++) {
		p[i] = -1;
	}
}

int _find(int x) {
	if (p[x] < 0) {
		return x;
	}
	p[x] = _find(p[x]);
	return p[x];
}

bool _union(int a, int b) {
	a = _find(a);
	b = _find(b);
	if (a == b) {
		return false;
	}
	p[b] = a;
	return true;
}

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;

	for (int i = 0; i <= M; i++) {
		cin >> a >> b >> c;
		edge.push_back({ c, { a, b } });
		edge.push_back({ c, { b, a } });
	}

	int cnt = 0;
	int up_cnt = 0;
	sort(edge.begin(), edge.end(), greater<>()); _init();
	
	for (auto e : edge) {
		if (_union(e.second.first, e.second.second)) {
			if (e.first == 0) up_cnt++;
			if (++cnt == N) {
				break;
			}
		}
	}
	
	min_score = up_cnt * up_cnt;
	
	cnt = 0; up_cnt = 0;
	sort(edge.begin(), edge.end()); _init();
	
	for (auto e : edge) {
		if (_union(e.second.first, e.second.second)) {
			if (e.first == 0) up_cnt++;
			if (++cnt == N) {
				break;
			}
		}
	}

	max_score = up_cnt * up_cnt;

	cout << max_score - min_score;

	return 0;
}