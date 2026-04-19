#include <iostream>
#include <unordered_map>
#include <queue>
using namespace std;
typedef pair<int, int> nd;

int A, B;
int ans = -1;
queue<nd> q;

int main() {
	
	cin >> A >> B;
	q.push(nd(B, 0));

	while (!q.empty()) {
		nd now = q.front();
		q.pop();

		if (now.first == A) {
			ans = now.second;
			break;
		}

		if (now.first % 2 == 0 && now.first != 0) {
			q.push(nd(now.first / 2, now.second + 1));
		}

		else if (now.first % 10 == 1 && now.first > 10) {
			q.push(nd((now.first - 1) / 10, now.second + 1));
		}
	}

	if (ans == -1) {
		cout << ans;
	}
	else {
		cout << ans + 1;
	}

	return 0;
}