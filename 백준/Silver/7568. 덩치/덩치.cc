#include <iostream>

using namespace std;

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	int x, y = 0;
	int rank[50] = {0, };
	int stat[50][2] = { 0, };

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> stat[i][0] >> stat[i][1];
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (stat[i][0] < stat[j][0] && stat[i][1] < stat[j][1])
				rank[i]++;
		}
	}

	for (int i = 0; i < N; i++) {
		cout << rank[i]+1 << " ";
	}

	return 0;
}