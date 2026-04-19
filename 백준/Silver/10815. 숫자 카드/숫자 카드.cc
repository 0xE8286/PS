#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<int, bool> card;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M, x;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> x;
		card[x] = true;
	}
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> x;
		cout << (card[x] ? 1 : 0);
		cout << ' ';
	}

	return 0;
}