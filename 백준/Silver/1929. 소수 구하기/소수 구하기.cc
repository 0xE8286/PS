#include <iostream>
#define MAX_M 1000001
using namespace std;

bool isPrime[MAX_M];
int n, m;

bool isInBoundary(int a) {
	if (a >= n && a <= m) return true;
	return false;
}

int main(void) {

	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin >> n >> m;

	for (int i = 2; i <= m; i++) {
		isPrime[i] = true;
	}

	for (int num = 2; num <= m; num++) {
		if (isPrime[num]) {
			if (isInBoundary(num)) {
				cout << num << "\n";
			}
			for (int i = num * 2; i <= m; i += num) {
				isPrime[i] = false;
			}
		}
	}
	return 0;
}