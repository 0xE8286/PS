#include <iostream>
#include <vector>
#include <queue>

#define MAX_N 5001
#define INF 1e9

#define A 1
#define B 2
#define OTHER 0

using namespace std;

int N, M;
int J, K;
int X, Y, Z;

int dist[MAX_N];
int type[MAX_N];

vector<pair<int, int>> edge[MAX_N];

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	cin >> J >> K;

	int h;
	
	for (int i = 0; i < K; i++) {
		cin >> h;
		type[h] = A;
	}
	
	for (int i = 0; i < K; i++) {
		cin >> h;
		type[h] = B;
	}

	for (int i = 0; i < M; i++) {
		cin >> X >> Y >> Z;
		edge[X].push_back({ Z, Y });
		edge[Y].push_back({ Z, X });
	}

	
	fill(dist, dist + MAX_N, INF);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

	pq.push({ 0, J });
	dist[J] = 0;

	while (!pq.empty()) {
		int cost = pq.top().first;
		int curr = pq.top().second;
		pq.pop();

		for (auto &e : edge[curr]) {
			if (dist[e.second] > cost + e.first) {
				dist[e.second] = cost + e.first;
				pq.push({ dist[e.second], e.second });
			}
		}
	}

	priority_queue<int, vector<int>, greater<>> a, b;
	
	for (int i = 1; i <= N; i++) {
		if (dist[i] == INF) {
			continue;
		}
		if (type[i] == A) a.push(dist[i]);
		if (type[i] == B) b.push(dist[i]);
	}

	if (a.empty()) {
		if (b.empty()) {
			cout << -1;
			return 0;
		}
		cout << "B\n";
		cout << b.top();
		return 0;
	}

	if (b.empty()) {
		cout << "A\n";
		cout << a.top();
		return 0;
	}

	if (a.top() <= b.top()) {
		cout << "A\n";
		cout << a.top();
		return 0;
	}
	else {
		cout << "B\n";
		cout << b.top();
		return 0;
	}

	return 0;
}