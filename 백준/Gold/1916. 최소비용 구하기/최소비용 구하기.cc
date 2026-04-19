#include <iostream>
#include <queue>
#include <list>
#include <vector>
using namespace std;
using route = pair<int, int>;

class Point {
public:
	list<route> linked;
	int index;
	int cost;
};

int N, M, ans;
vector<Point> vec(1001);
vector<bool> check(1001);
int main() {
	cin >> N;
	cin >> M;

	for (int i = 1; i <= N; i++) {
		vec[i].index = i;
	}
	int sp, ep, cost;
	for (int i = 0; i < M; i++) {
		cin >> sp >> ep >> cost;
		vec[sp].linked.push_back(route(cost, ep));
	}
	cin >> sp >> ep;

	priority_queue<route, vector<route>, greater<route>> pq;

	pq.push(route(0, sp));
	while (!pq.empty()) {
		int cost = pq.top().first;
		int point = pq.top().second; pq.pop();
		if (check[point]) continue;
		check[point] = true;

		if (point == ep) {
			ans = cost;
			break;
		}

		for (route next : vec[point].linked) {
			if (check[next.second] == 0) {
				pq.push(route(cost + next.first, next.second));
			}
		}
	}
	cout << ans;

	return 0;
}
