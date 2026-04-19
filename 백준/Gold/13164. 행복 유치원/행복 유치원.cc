#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, K;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> K;
	
	vector<int> cost;
	int prev, curr;
	int sum = 0;
	
	for (int i = 0; i < N; i++) {
		cin >> curr;
		if (i == 0) {
			prev = curr;
			continue;
		}
		int diff = curr - prev;

		sum += diff;
		cost.push_back(diff);
		
		prev = curr;
	}

	sort(cost.begin(), cost.end(), greater<>());

	int remove_cost = 0;

	for (int i = 0; i < K - 1; i++) {
		remove_cost += cost[i];
	}

	cout << sum - remove_cost;

	return 0;
}