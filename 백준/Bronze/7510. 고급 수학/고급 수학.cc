#include <iostream>
#include <algorithm>
using namespace std;

int T;
int edge[3];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		for (int i = 0; i < 3; i++) {
			cin >> edge[i];
			edge[i] = edge[i] * edge[i];
		}
		sort(edge, edge + 3, greater<>());

		cout << "Scenario #" << tc << ":\n";
		if (edge[0] == edge[1] + edge[2]) {
			cout << "yes\n";
		}
		else {
			cout << "no\n";
		}
		cout << '\n';
	}
	return 0;
}