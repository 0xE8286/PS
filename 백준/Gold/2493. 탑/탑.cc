#include <iostream>
#include <stack>
using namespace std;

int N, height;
stack<pair<int, int>> st;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> height;

		while (!st.empty() && st.top().first < height) {
			st.pop();
		}
		if (st.empty()) {
			cout << 0;
		}
		else {
			cout << st.top().second;
		}
		cout << ' ';
		st.push({ height, i });
	}

	return 0;
}