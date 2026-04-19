#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int arr[10000];

int main() {

	cin >> N;
	
	int low = 0;
	int high = 0;
	
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		high = max(high, arr[i]);
	}
	cin >> M;
	
	int result = 0;

	while (low <= high) {
		int mid = (low + high) / 2;
		int sum = 0;
		for (int req : arr) {
			sum += min(mid, req);
		}
		if (sum <= M) {
			low = mid + 1;
			result = mid;
		}
		else {
			high = mid - 1;
		}
	}
	cout << result;
	return 0;
}