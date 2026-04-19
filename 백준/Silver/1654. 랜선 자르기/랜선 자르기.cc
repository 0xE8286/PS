#include <iostream>
#define MAX_K 10000
using namespace std;

int K, N;
int cable[MAX_K];
long long low = 1;
long long high;
long long ok_max;

bool is_possible(long long value) {
	int cnt = 0;
	for (int i = 0; i < K; i++) {
		cnt += cable[i] / value;
	}
	if (cnt >= N) {
		return true;
	}
	else
		return false;
}

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> K >> N;

	for (int i = 0; i < K; i++) {
		cin >> cable[i];
		if (cable[i] > high) {
			high = cable[i];
		}
	}
	
	while (low <= high) {
		long long mid = (low + high) / 2;
		if (is_possible(mid)) {
			low = mid + 1;
			if (mid > ok_max)
				ok_max = mid;
		}
		else {
			high = mid - 1;
		}
	}
	cout << ok_max;

	return 0;
}