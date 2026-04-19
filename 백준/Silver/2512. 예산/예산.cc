#include <iostream>

using namespace std;

int N, M;
int low, high, result;
int arr[10000];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		high = max(high, arr[i]);
	}
	cin >> M;
	
	while (low <= high) {
		int mid = (low + high) / 2;
		int sum = 0;
		for (int req : arr) {
			sum += min(mid, req);
		}
		if (sum <= M) {
			result = mid;
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}
	cout << result;

	return 0;
}