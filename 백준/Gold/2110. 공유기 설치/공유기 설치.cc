#include <iostream>
#define MAX_N 200000

using namespace std;

int N, C;
int home[MAX_N];
int temp[MAX_N];

void merge_sort(int* arr, int start, int mid, int end) {
	int l = start;
	int t = start;
	int r = mid + 1;
	while (l <= mid && r <= end) {
		if (arr[l] < arr[r]) {
			temp[t++] = arr[l++];
		}
		else {
			temp[t++] = arr[r++];
		}
	}
	while (l <= mid) {
		temp[t++] = arr[l++];
	}
	while (r <= end) {
		temp[t++] = arr[r++];
	}
	for (int i = start; i <= end; i++) {
		arr[i] = temp[i];
	}
}

void merge(int *arr, int start, int end) {
	int mid = (start + end) / 2;
	if (start < end) {
		merge(arr, start, mid);
		merge(arr, mid + 1, end);
		merge_sort(arr, start, mid, end);
	}
}

int setup_cnt(int interval) {
	int cnt = 1;
	int prev_home = home[0];

	for (int i = 1; i < N; i++) {
		int dist = home[i] - prev_home;
		if (dist >= interval) {
			cnt++;
			prev_home = home[i];
		}
	}
	return cnt;
}

int main(void) {
	cin >> N >> C;

	for (int i = 0; i < N; i++) {
		cin >> home[i];
	}

	merge(home, 0, N - 1);

	int low = 1;
	int high = home[N-1] - home[0];
	int ans = 0;

	while (low <= high) {
		int mid = (low + high) / 2;
		int count = setup_cnt(mid);

		if (count >= C) {
			low = mid + 1;
			ans = mid;
		}
		else {
			high = mid - 1;
		}
	}

	cout << ans;

	return 0;
}