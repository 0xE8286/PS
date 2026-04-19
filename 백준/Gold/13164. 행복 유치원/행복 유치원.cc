#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, K;

int main() {

	cin >> N >> K;
	
	vector<int> diff;
	int prev, curr;
	
	for (int i = 0; i < N; i++) {
		cin >> curr;
		if (i == 0) {
			prev = curr;
			continue;
		}
		diff.push_back(curr-prev);
		prev = curr;
	}

	sort(diff.begin(), diff.end(), greater<>());

	int sum = 0; int max_cost = 0; int cnt = 0;

	for (auto d : diff) {
		sum += d;
		if (cnt < K-1) {
			max_cost += d;
			cnt++;
		}
	}

	cout << sum - max_cost;

	return 0;
}