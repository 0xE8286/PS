#include <iostream>
#include <vector>
using namespace std;

int D, N, x;
int oven[300001];
int pizza[300001];
int ans;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> D >> N;
	cin >> oven[1];

	for (int i = 2; i <= D; i++) {
		cin >> x;
		if (x > oven[i - 1]) {
			oven[i] = oven[i - 1];
		}
		else {
			oven[i] = x;
		}
	}

	for (int i = 1; i <= N; i++) {
		cin >> pizza[i];
	}

	int depth = D;
	int i, j;

	for (i = 1; i <= N; i++) {
		
		if (pizza[i] > oven[1]) {
			cout << 0;
			return 0;
		}

		for (j = depth; j >= 1; j--) {
			if (pizza[i] <= oven[j]) {
				depth = j - 1;
				break;
			}
		}
		
		if (depth == 0) { // oven full 
			if (i == N) {
				cout << 1;
			}
			else {
				cout << 0;
			}
			return 0;
		}
	}
	cout << j;

	return 0;
}