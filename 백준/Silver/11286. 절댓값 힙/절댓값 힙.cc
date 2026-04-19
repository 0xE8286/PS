#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

int N, cmd;

bool cmp(int a, int b) {
	if (abs(a) == abs(b)) {
		return a > b;
	}
	else {
		return abs(a) > abs(b);
	}
}

int main() {
	priority_queue<int, vector<int>, decltype(&cmp)> pq(cmp);

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> cmd;
		if (cmd == 0) {
			if (pq.size() <= 0) {
				cout << 0 << '\n';
			}
			else {
				cout << pq.top() << '\n';
				pq.pop();
			}
		}
		else {
			pq.push(cmd);
		}
	}
	return 0;
}