#include <iostream>
using namespace std;

int way[11];
int T, N;

int main() {

	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	way[1] = 1;
	way[2] = 2;
	way[3] = 4;

	for (int i = 4; i <= 10; i++) {
		way[i] = way[i-1] + way[i-2] + way[i-3];
	}

	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N;
		cout << way[N] << '\n';
	}

	return 0;
}