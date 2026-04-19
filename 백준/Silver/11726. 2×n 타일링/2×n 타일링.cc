#include <iostream>
using namespace std;

#define MAX_N 1001
int N;
int tile[MAX_N];

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	tile[1] = 1;
	tile[2] = 2;

	for (int i = 3; i <= N; i++) {
		tile[i] = (tile[i - 2] + tile[i - 1]) % 10007;
	}
	cout << tile[N];

	return 0;
}