#include <iostream>
#define NO_VISIT -99

using namespace std;

int N, K;
int parent[200001];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	fill(parent, parent + N, NO_VISIT);
	
	int curr, prev;

	cin >> prev;
	parent[prev] = -1;

	for (int i = 1; i < N; i++) {
		cin >> curr;
		K = max(curr, K);

		if (parent[curr] == NO_VISIT) {
			parent[curr] = prev;
		}

		prev = curr;
	}

	cout << K + 1 << '\n';
	
	for (int i = 0; i <= K; i++) {
		cout << parent[i] << ' ';
	}

	return 0;
}