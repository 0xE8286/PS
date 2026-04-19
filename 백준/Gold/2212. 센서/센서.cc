#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, K;
int pos[10000];

int main() {

	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> pos[i];
	}

	sort(pos, pos + N);
	vector<int> dist;

	for (int i = 1; i < N; i++) {
		dist.push_back(pos[i] - pos[i - 1]);
	}

	sort(dist.begin(), dist.end(), greater<>());

	int sum = 0;

	for (int i = K - 1; i < dist.size(); i++) {
		sum += dist[i];
	}
	cout << sum;

	return 0;
}