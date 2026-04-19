#include <iostream>

using namespace std;

int N, K;
int arr[1048576];
int temp[1048576];

void sort(int start, int mid, int end) {
	int left = start;
	int right = mid + 1;
	int temp_index = start;

	while (left <= mid && right <= end) {
		if (arr[left] <= arr[right]) {
			temp[temp_index++] = arr[left++];
		}
		else {
			temp[temp_index++] = arr[right++];
		}
	}
	
	while (left <= mid) {
		temp[temp_index++] = arr[left++];
	}
	while (right <= end) {
		temp[temp_index++] = arr[right++];
	}

	for (int i = start; i <= end; i++) {
		arr[i] = temp[i];
	}
}

void merge(int start, int end, int cnt) {
	if (start >= end) return;

	int mid = (start + end) / 2;

	merge(start, mid, cnt/2);
	merge(mid + 1, end, cnt/2);

	if (cnt <= N / K) {
		sort(start, mid, end);
	}
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	cin >> K;

	merge(0, N - 1, N);

	for (int i = 0; i < N; i++) {
		cout << arr[i] << ' ';
	}
}