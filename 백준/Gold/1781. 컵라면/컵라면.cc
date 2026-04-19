#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;

int N;
pii problem[200000];
ll sum;

bool comp(pii a, pii b) {
	if (a.first < b.first) {
		return true;
	}
	else if (a.first == b.first) {
		if (a.second > b.second) return true;
		return false;
	}
	else {
		return false;
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int day, score;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> day >> score;
		problem[i] = { day, score };
	}
	sort(problem, problem + N, comp);
	
	priority_queue<pii, vector<pii>, greater<>> pq;

	pq.push({ problem[0].second, problem[0].first });
	
	for (int i = 1; i < N; i++) {
		if (problem[i - 1].first != problem[i].first) {
			pq.push({ problem[i].second, problem[i].first });
			continue;
		}
		if (pq.size() < problem[i].first) {
			pq.push({ problem[i].second, problem[i].first });
			continue;
		}
		if (pq.top().first < problem[i].second) {
			pq.pop();
			pq.push({ problem[i].second, problem[i].first });
		}
	}
	while (!pq.empty()) {
		sum += pq.top().first;
		pq.pop();
	}
	cout << sum;
	
	return 0;
}