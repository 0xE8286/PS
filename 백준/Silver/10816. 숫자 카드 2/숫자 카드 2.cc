#include <iostream>
#define MAX_N 500000
using namespace std;

int N, M;
int card[MAX_N];
int temp[MAX_N];
int ans[MAX_N];
int target;

int lower_bound(int* arr, int start, int end) {
	while (start < end) {
		int mid = (start + end) / 2;
		if (arr[mid] < target) {
			start = mid + 1;
		}
		else {
			end = mid;
		}
	}
	return end;
}

int upper_bound(int* arr, int start, int end) {
	if (target == arr[end]) {
		return end + 1;
	}
	while (start < end) {
		int mid = (start + end) / 2;
		if (arr[mid] <= target) {
			start = mid + 1;
		}
		else {
			end = mid;
		}
	}
	return end;
}

void merge_sort(int* arr, int start, int mid, int end) {
	int left_i = start;
	int right_i = mid + 1;
	int temp_i = start;

	while (left_i <= mid && right_i <= end) {
		if (arr[left_i] < arr[right_i])
			temp[temp_i++] = arr[left_i++];
		else
			temp[temp_i++] = arr[right_i++];
	}
	while (left_i <= mid) {
		temp[temp_i++] = arr[left_i++];
	}
	while (right_i <= end) {
		temp[temp_i++] = arr[right_i++];
	}
	for (int i = start; i <= end; i++) {
		arr[i] = temp[i];
	}
}

void merge(int* arr, int start, int end) {
	if (start < end) {
		int mid = (start + end) / 2;
		merge(arr, start, mid);
		merge(arr, mid + 1, end);
		merge_sort(arr, start, mid, end);
	}
}

int main(void) {

	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> card[i];
	}

	merge(card, 0, N - 1);
	
	cin >> M;
	
	for (int i = 0; i < M; i++) {
		cin >> target;
		ans[i] = upper_bound(card, 0, N - 1) - lower_bound(card, 0, N - 1);
	}

	for (int i = 0; i < M; i++) {
		cout << ans[i] << " ";
	}
	
	return 0;
}