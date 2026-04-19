#include <iostream>

using namespace std;

int N, K;

int min(int a, int b) {
	if (a < b) {
		return a;
	}
	return b;
}

int small_than(int mid) {
	int cnt = 0;
	for (int i = 1; i <= N; i++) {
		cnt += min(mid/i, N);
	}
	return cnt;
}

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> K;
	
	int low = 1;
	int high = K;
	int ans = 0;

	while (low <= high) {
		int mid = (low + high) / 2;
		if (small_than(mid) < K) {
			low = mid + 1;			
		}
		else {
			ans = mid;
			high = mid - 1;
		}
	}
	cout << ans;

	return 0;
}